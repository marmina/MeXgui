#include "JobControl.h"




//using namespace System::Collections::Generic;



//using namespace System::Data;

//using namespace System::Diagnostics;





//using namespace System::Text;

//using namespace System::Threading;



//using namespace System::Xml::Serialization;

//using namespace System::Text::RegularExpressions;
using namespace MeXgui::core::util;
using namespace MeXgui::core::gui;
namespace MeXgui
{
	namespace core
	{
		namespace details
		{

			void JobControl::SendToWorkerThunk::handleEvent(QVector<TaggedJob*> &jobs)
			{
				for (QVector<TaggedJob*>::const_iterator j = jobs.begin(); j != jobs.end(); ++j)
				{
					if ((*j)->getStatus() == PROCESSING || (*j)->getStatus() == ABORTING)
					{
						MessageBox::Show("Can't move '" + (*j)->getName() + "' because it is currently processing.", "Can't move job", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						continue;
					}
					if ((*j)->getOwningWorker() == w->getName())
						continue;

					c->ReleaseJob(*j);

					w->AddJob(*j);
					(*j)->setOwningWorker(w->getName());
				}
				c->refresh();
			}

			JobControl::SendToWorkerThunk::SendToWorkerThunk(JobWorker *w, JobControl *c)
			{
				this->c = c;
				this->w = w;
			}

			void JobControl::JobListSerializer::InitializeInstanceFields()
			{
				mainJobList = QVector<QString>();
				workersAndTheirJobLists = QVector<Pair<QString, QVector<QString>*>*>();
			}

			void JobControl::ShowAllProcessWindows()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->IsProgressWindowAvailable)
						w->second->ShowProcessWindow();
			}

			void JobControl::HideAllProcessWindows()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					w->second->HideProcessWindow();
			}

			void JobControl::AbortAll()
			{
				for (QMap<QString, JobWorker*>::const_iterator worker = workers.begin(); worker != workers.end(); ++worker)
					if (worker->second->IsEncoding)
						worker->second->Abort();
				refresh();
			}

			void JobControl::StartAll(bool restartStopping)
			{
				// check for missing components
				if (UpdateWindow::isComponentMissing())
				{
					mainForm->startUpdateCheck();
					return;
				}

				if (workers.Values->Count == 0)
					NewWorker(freeWorkerName(), false);

				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
				{
					if (!w->second->IsEncoding)
						w->second->StartEncoding(false);
					else if (restartStopping && w->second->Status == Stopping)
						w->second->SetRunning();
				}
				refresh();
			}

			void JobControl::StopAll()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->IsEncoding)
						w->second->SetStopping();
				refresh();
			}

			JobControl::JobControl()
			{
				InitializeInstanceFields();
				InitializeComponent();
				addClearButton();
				addSendToWorkerMenuItems();
				addSendToTemporaryWorkerMenuItem();
				jobQueue->RequestJobDeleted = new RequestJobDeleted(this, &JobControl::DeleteJob);
				summary = new WorkerSummary(this);
				resourceLock = new SeQMaphore(1, 1);
			}

			const SeQMaphore &JobControl::getResourceLock() const
			{
				return resourceLock;
			}

			void JobControl::setResourceLock(const SeQMaphore &value)
			{
				resourceLock = value;
			}

			void JobControl::addSendToTemporaryWorkerMenuItem()
			{
//C# TO C++ CONVERTER TODO TASK: Lambda expressions and anonymous methods are not converted to native C++ unless the option to convert to C++0x lambdas is selected:
				jobQueue->AddMenuItem("Run in new temporary worker", 0, new MultiJobHandler(delegate(QVector<TaggedJob*> jobs)
						// find a good name
				{
					int number = 0;
					QString name;
					do
					{
						number++;
						name = "Temporary worker " + number;
					} while (workers.find(name) != workers.end());
					JobWorker *w = NewWorker(name, false);
					for (unknown::const_iterator j = jobs.begin(); j != jobs.end(); ++j)
					{
						ReleaseJob(*j);
						w->AddJob(*j);
					}
					this->refresh();
					w->setMode(CloseOnLocalListCompleted);
					w->IsTemporaryWorker = true;
					w->StartEncoding(true);
				}
			   ));
			}

			void JobControl::ReleaseJob(TaggedJob *j)
			{
				if (j->getOwningWorker() == "")
					return;

				workers[j->getOwningWorker()]->RemoveJobFromQueue(j);
				j->setOwningWorker("");
				if (!jobQueue->HasJob(j))
					jobQueue->queueJob(j);
				refresh();
			}

			void JobControl::addSendToWorkerMenuItems()
			{
//C# TO C++ CONVERTER TODO TASK: Lambda expressions and anonymous methods are not converted to native C++ unless the option to convert to C++0x lambdas is selected:
				jobQueue->AddDynamicSubMenu("Send to worker", 0, new MultiJobMenuGenerator(delegate
				{
					Pair<QString, MultiJobHandler> list[workers.size()];
					int i = 0;
					for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					{
						list[i] = new Pair<QString, MultiJobHandler>(w->second->Name, new MultiJobHandler((new SendToWorkerThunk(w->second, this))->handleEvent));
						i++;
					}
					return list;
				}
			   ));
			}

			void JobControl::setMainForm(const MeXgui::MainForm &value)
			{
				mainForm = value;
				mainForm->RegisterForm(summary);
			}

			const bool &JobControl::getIsAnyWorkerEncoding() const
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->IsEncoding)
						return true;
				return false;
			}

			const bool &JobControl::getIsAnyWorkerEncodingAudio() const
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->IsEncodingAudio)
						return true;
				return false;
			}

			const MeXgui::AfterEncoding &JobControl::getCurrentAfterEncoding() const
			{
				return currentAfterEncoding;
			}

			void JobControl::addClearButton()
			{
				jobQueue->AddButton("Clear", new EventHandler(deleteAllJobsButton_Click));
			}

			void JobControl::deleteAllJobsButton_Click()
			{
				int incompleteJobs = 0;
				DialogResult *dr = DialogResult::No;
				TaggedJob jobList[allJobs.size()];
				allJobs.Values->CopyTo(jobList, 0);
				for (MeXgui::core::details::TaggedJob::const_iterator j = jobList->begin(); j != jobList->end(); ++j)
				{
					if ((*j)->getStatus() != DONE)
						++incompleteJobs;
				}
				if (incompleteJobs != 0)
				{
					dr = MessageBox::Show("Delete incomplete jobs as well?\n\nYes for All, No for completed or Cancel to abort:", "Are you sure you want to clear the queue?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
					if (dr == DialogResult::Cancel)
						return;
				}
				for (MeXgui::core::details::TaggedJob::const_iterator j = jobList->begin(); j != jobList->end(); ++j)
				{
					if (dr == DialogResult::Yes || (*j)->getStatus() == DONE)
						reallyDeleteJob(*j);
				}
			}

			void JobControl::DeleteJob(TaggedJob *job)
			{
				if (job->getStatus() == PROCESSING || job->getStatus() == ABORTING)
				{
					MessageBox::Show("You cannot delete a job while it is being processed.", "Deleting " + job->getName() + " failed", MessageBoxButtons::OK, MessageBoxIcon::Stop);
					return;
				}

				if (job->EnabledJobs.empty() && job->RequiredJobs.empty())
				{
					reallyDeleteJob(job);
					return;
				}

				DialogResult *dr = MessageBox::Show("'" + job->getName() + "' is related to a job series. Do you want to delete all related jobs?\r\n" + "Press Yes to delete all related jobs, No to delete this job and " + "remove the dependencies, or Cancel to abort", "Job dependency detected", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);

				switch (dr)
				{
					case DialogResult::Yes: // Delete all dependent jobs
						deleteAllDependantJobs(job);
						break;

					case DialogResult::No: // Just delete the single job
						reallyDeleteJob(job);
						break;

					case DialogResult::Cancel: // do nothing
						break;
				}
			}

			void JobControl::RemoveCompletedJob(TaggedJob *job)
			{
				reallyDeleteJob(job);
			}

			void JobControl::reallyDeleteJob(TaggedJob *job)
			{
				if (job->getStatus() == PROCESSING || job->getStatus() == ABORTING)
					return;

				if (job->getStatus() != DONE && getMainForm()->Instance->Settings->DeleteIntermediateFiles)
				{
					QVector<QString> filesToDelete = QVector<QString>();
					if (job->getJob()->FilesToDelete.size() > 0)
						filesToDelete.AddRange(job->getJob()->FilesToDelete);
					if (dynamic_cast<CleanupJob*>(job->getJob()) != 0 && (static_cast<CleanupJob*>(job->getJob()))->files.size() > 0)
						filesToDelete.AddRange((static_cast<CleanupJob*>(job->getJob()))->files);
					if (filesToDelete.size() > 0)
					{
						LogItem *oLog = FileUtil::DeleteIntermediateFiles(filesToDelete, false, true);
						if (oLog != 0)
						{
							LogItem *log = mainForm->getLog()->Info(QString::Format("Log for {0} ({1}, {2} -> {3})", job->getName(), job->getJob()->EncodingMode, job->getInputFileName(), job->getOutputFileName()));
							log->Add(oLog);
						}
					}
				}

				mainForm->getJobs()->getResourceLock()->WaitOne(10000, false);
				if (job->getOwningWorker() != "" && workers.find(job->getOwningWorker()) != workers.end())
					workers[job->getOwningWorker()]->RemoveJobFromQueue(job);

				if (jobQueue->HasJob(job))
					jobQueue->removeJobFromQueue(job);

				for (QVector<TaggedJob*>::const_iterator p = job->RequiredJobs.begin(); p != job->RequiredJobs.end(); ++p)
					(*p)->EnabledJobs->Remove(job);

				for (QVector<TaggedJob*>::const_iterator j = job->EnabledJobs.begin(); j != job->EnabledJobs.end(); ++j)
					(*j)->RequiredJobs->Remove(job);

				QString fileName = Path::Combine(mainForm->getMeXguiPath(), "jobs");
					   fileName = Path::Combine(fileName, job->getName() + ".xml");
				if (File::Exists(fileName))
					File::Delete(fileName);

				allJobs.erase(job->getName());
				mainForm->getJobs()->getResourceLock()->Release();
			}

			void JobControl::deleteAllDependantJobs(TaggedJob *job)
			{
				reallyDeleteJob(job);

				for (QVector<TaggedJob*>::const_iterator j = job->EnabledJobs.begin(); j != job->EnabledJobs.end(); ++j)
					deleteAllDependantJobs(*j);

				for (QVector<TaggedJob*>::const_iterator j = job->RequiredJobs.begin(); j != job->RequiredJobs.end(); ++j)
					deleteAllDependantJobs(*j);
			}

			void JobControl::refresh()
			{
				jobQueue->refreshQueue();
				summary->RefreshInfo();
			}

			void JobControl::StartPostponedWorkers()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->Status == Postponed)
						w->second->StartEncoding(false);
			}

			void JobControl::StartIdleWorkers()
			{
				// start idle and postponed workers if required
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (!w->second->IsEncoding && ((w->second->Status == Idle && getMainForm()->Instance->Settings->AutoStartQueue) || w->second->Status == Postponed))
						w->second->StartEncoding(false);
			}

			QVector<QString> JobControl::toStringList(IEnumerable<TaggedJob*> *jobList)
			{
				QVector<QString> strings = QVector<QString>();
				for (IEnumerable<TaggedJob*>::const_iterator j = jobList->begin(); j != jobList->end(); ++j)
					strings.push_back((*j)->getName());
				return strings;
			}

			void JobControl::saveJobs()
			{
				mainForm->getJobs()->getResourceLock()->WaitOne(10000, false);
				for (QMap<QString, TaggedJob*>::const_iterator job = allJobs.begin(); job != allJobs.end(); ++job)
				{
					job->second->EnabledJobNames = toStringList(job->second->EnabledJobs);
					job->second->RequiredJobNames = toStringList(job->second->RequiredJobs);
					saveJob(job->second, mainForm->getMeXguiPath());
				}
				mainForm->getJobs()->getResourceLock()->Release();
				saveJobLists();
			}

			void JobControl::saveJobLists()
			{
				JobListSerializer *s = new JobListSerializer();

				mainForm->getJobs()->getResourceLock()->WaitOne(10000, false);
				s->mainJobList = toStringList(jobQueue->getJobList());

				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					s->workersAndTheirJobLists.push_back(new Pair<QString, QVector<QString>*>(w->second->Name, toStringList(w->second->Jobs)));
				QString path = Path::Combine(mainForm->getMeXguiPath(), "joblists.xml");

				Util::XmlSerialize(s, path);
				mainForm->getJobs()->getResourceLock()->Release();
			}

			void JobControl::loadJobLists()
			{
				QString path = Path::Combine(mainForm->getMeXguiPath(), "joblists.xml");

				JobListSerializer *s = Util::XmlDeserializeOrDefault<JobListSerializer*>(path);
				jobQueue->setJobList(toJobList(s->mainJobList));

				for (QVector<Pair<QString, QVector<QString>*>*>::const_iterator p = s->workersAndTheirJobLists.begin(); p != s->workersAndTheirJobLists.end(); ++p)
				{
					JobWorkerMode mode = RequestNewJobs;
					bool bIsTemporaryWorker = false;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'StartsWith' method:
					if ((*p)->fst->StartsWith("Temporary worker "))
					{
						if ((*p)->snd->Count == 0)
							continue;
						mode = CloseOnLocalListCompleted;
						bIsTemporaryWorker = true;
					}
					JobWorker *w = NewWorker((*p)->fst, false);
					w->setMode(mode);
					w->IsTemporaryWorker = bIsTemporaryWorker;

					// check if there are any unassigned jobs which belongs to this worker
					for (QMap<QString, TaggedJob*>::const_iterator oJob = allJobs.begin(); oJob != allJobs.end(); ++oJob)
					{
						if (w->getName().Equals(oJob->second->OwningWorker) && !(*p)->snd->Contains(oJob->second->Name))
							(*p)->snd->Add(oJob->second->Name);
					}

					IEnumerable<TaggedJob*> *list = toJobList((*p)->snd);
					for (IEnumerable<TaggedJob*>::const_iterator j = list->begin(); j != list->end(); ++j)
						w->AddJob(*j);
				}

				// check if there are any assigned jobs which have no existing worker
				for (QMap<QString, TaggedJob*>::const_iterator oJob = allJobs.begin(); oJob != allJobs.end(); ++oJob)
				{
					if (oJob->second->OwningWorker != 0 && !workers.find(oJob->second->OwningWorker) != workers.end())
						oJob->second->OwningWorker = 0;
				}
			}

			void JobControl::loadJobs()
			{
				QString jobsPath = Path::Combine(mainForm->getMeXguiPath(), "jobs");
				DirectoryInfo *di = FileUtil::ensureDirectoryExists(jobsPath);
//ORIGINAL LINE: FileInfo[] files = di.GetFiles("*.xml");
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
				FileInfo *files = di->GetFiles("*.xml");
				for (FileInfo::const_iterator fi = files->begin(); fi != files->end(); ++fi)
				{
					QString fileName = (*fi)->FullName;
					TaggedJob *job = loadJob(fileName);
					if (job != 0 && job->getName() != "")
					{
						if (allJobs.find(job->getName()) != allJobs.end())
							MessageBox::Show("A job named " + job->getName() + " is already in the queue.\nThe job defined in " + fileName + "\nwill be discarded", "Duplicate job name detected", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						else
							allJobs.insert(make_pair(job->getName(), job));
					}
				}

				for (QMap<QString, TaggedJob*>::const_iterator job = allJobs.begin(); job != allJobs.end(); ++job)
				{
					if (job->second->Status == PROCESSING || job->second->Status == ABORTING)
						job->second->Status = ABORTED;

					job->second->RequiredJobs = toJobList(job->second->RequiredJobNames);
					job->second->EnabledJobs = toJobList(job->second->EnabledJobNames);
				}
				loadJobLists();
			}

			QVector<TaggedJob*> JobControl::toJobList(IEnumerable<QString> *list)
			{
				QVector<TaggedJob*> jobList = QVector<TaggedJob*>();
				for (IEnumerable<QString>::const_iterator name = list->begin(); name != list->end(); ++name)
				{
					try
					{
						jobList.push_back(allJobs[*name]);
					}
					catch (KeyNotFoundException *e1)
					{

					}
				}
				return jobList;
			}

			void JobControl::saveJob(TaggedJob *job, const QString &path)
			{
				QString fileName = Path::Combine(path, "jobs");
					   fileName = Path::Combine(fileName, job->getName() + ".xml");
				Util::XmlSerialize(job, fileName);
			}

			MeXgui::core::details::TaggedJob *JobControl::loadJob(const QString &name)
			{
				XmlSerializer *ser = 0;
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//				using (Stream s = File.OpenRead(name))
				Stream *s = File::OpenRead(name);
				try
				{
					try
					{
						ser = new XmlSerializer(TaggedJob::typeid);
						return static_cast<TaggedJob*>(ser->Deserialize(s));
					}
					catch (std::exception &e)
					{
						DialogResult *r = MessageBox::Show("Job " + name + " could not be loaded. Delete?", "Error loading Job", MessageBoxButtons::YesNo, MessageBoxIcon::Error);
						if (r == DialogResult::Yes)
						{
							try
							{
								s->Close();
								File::Delete(name);
							}
							catch (std::exception &e1)
							{
							}
						}
						LogItem *_oLog = getMainForm()->Instance->Log->Info("Error");
						_oLog->LogValue("loadJob: " + name, e, Error);
						return 0;
					}
				}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to the exception 'finally' clause:
				finally
				{
					if (s != 0)
						s.Dispose();
				}
			}

			QString JobControl::getFreeJobName()
			{
				int jobNr = 1;
				QString name = "";
				while (true)
				{
					name = "job" + jobNr;
					if (!allJobs.find(name) != allJobs.end())
						return name;
					jobNr++;
				}
			}

			void JobControl::addJobsWithDependencies(JobChain *c, bool bStartQueue)
			{
				if (c == 0)
					return;

				for (unknown::const_iterator j = c->Jobs.begin(); j != c->Jobs.end(); ++j)
					addJob(*j);
				saveJobs();
				if (mainForm->getSettings()->getAutoStartQueue() && bStartQueue)
					StartAll(false);
				refresh();
			}

			void JobControl::addJobsToQueue(...)
			{
				for (unknown::const_iterator j = jobs.begin(); j != jobs.end(); ++j)
					addJob(new TaggedJob(*j));
				saveJobs();
				if (mainForm->getSettings()->getAutoStartQueue())
					StartAll(false);
				refresh();
			}

			void JobControl::addJob(TaggedJob *job)
			{
				mainForm->getJobs()->getResourceLock()->WaitOne(10000, false);
				job->setName(getFreeJobName());
				allJobs[job->getName()] = job;
				jobQueue->queueJob(job);
				mainForm->getJobs()->getResourceLock()->Release();
			}

			void JobControl::updateProcessingStatus()
			{
				throw std::exception();
			}

			void JobControl::showAfterEncodingStatus(MeXguiSettings *Settings)
			{
				currentAfterEncoding = Settings->getAfterEncoding();
				cbAfterEncoding->SelectedIndex = static_cast<int>(currentAfterEncoding);
				if (Settings->getAfterEncodingCommand().empty())
					cbAfterEncoding->Items[2] = "Run command (command not specified!)";
				else
					cbAfterEncoding->Items[2] = "Run '" + Settings->getAfterEncodingCommand() + "'";
			}

			MeXgui::core::details::TaggedJob *JobControl::ByName(const QString &p)
			{
				return allJobs[p];
			}

			bool JobControl::areDependenciesMet(TaggedJob *j)
			{
				for (QVector<TaggedJob*>::const_iterator job = j->RequiredJobs.begin(); job != j->RequiredJobs.end(); ++job)
					if ((*job)->getStatus() != DONE && (*job)->getStatus() != SKIP)
						return false;

				return true;
			}

			MeXgui::core::details::TaggedJob *JobControl::getJobToProcess()
			{
//C# TO C++ CONVERTER TODO TASK: There is no built-in support for multithreading in native C++:
				lock (nextJobLock)
				{
					for (IEnumerable<TaggedJob*>::const_iterator job = jobQueue->getJobList()->begin(); job != jobQueue->getJobList()->end(); ++job)
					{
						if ((*job)->getStatus() == WAITING && (*job)->getOwningWorker() == "" && areDependenciesMet(*job))
							//(!IsAnyWorkerEncodingAudio || !job.Job.EncodingMode.Equals("audio")))
							return job;
					}
					return 0;
				}
			}

			void JobControl::RenameWorker(const QString &name, const QString &value)
			{
				if (workers.find(value) != workers.end())
					throw new NameTakenException(value);

				JobWorker *w = workers[name];
				w->setName(value);
				workers.erase(name);
				workers[value] = w;
				summary->Rename(name, value);

				for (QMap<QString, TaggedJob*>::const_iterator job = allJobs.begin(); job != allJobs.end(); ++job)
				{
					if (name == job->second->OwningWorker)
						job->second->OwningWorker = value;
				}

			}

			void JobControl::jobQueue_StartClicked()
			{
				StartAll(true);
			}

			void JobControl::jobQueue_StopClicked()
			{
				StopAll();
			}

			void JobControl::jobQueue_AbortClicked()
			{
				DialogResult *r = MessageBox::Show("Do you really want to abort all jobs?", "Really abort?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (r == DialogResult::Yes)
					AbortAll();
			}

			QString JobControl::freeWorkerName()
			{
				int num = 0;
				QString name;
				do
				{
					num++;
					name = "Worker " + num;
				} while (workers.find(name) != workers.end());

				return name;
			}

			QVector<Pair<QString, bool>*> JobControl::ListWorkers()
			{
				QVector<Pair<QString, bool>*> ans = QVector<Pair<QString, bool>*>();

				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
				{
					ans.push_back(new Pair<QString, bool>(w->second->Name, w->second->Visible));
				}

				return ans;
			}

			void JobControl::HideAllWorkers()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					w->second->Hide();
			}

			void JobControl::ShowAllWorkers()
			{
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					w->second->Show();
			}

			void JobControl::RequestNewWorker()
			{
				QString name = InputBox::Show("Please enter a name for this new worker", "Please enter a name", freeWorkerName());
				if (name.empty())
					return;
				if (workers.find(name) != workers.end())
				{
					MessageBox::Show("A worker by this name already exists. Adding worker failed", "Adding worker failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				JobWorker *w = NewWorker(name, true);
				w->StartEncoding(true);
			}

			MeXgui::core::details::JobWorker *JobControl::NewWorker(const QString &name, bool show)
			{
				assert(!workers.find(name) != workers.end());

				JobWorker *w = new JobWorker(mainForm);
				w->setName(name);
				w->WorkerFinishedJobs += new EventHandler(this, &JobControl::WorkerFinishedJobs);
				workers.insert(make_pair(w->getName(), w));
				summary->Add(w);
				mainForm->RegisterForm(w);
				return w;
			}

			void JobControl::WorkerFinishedJobs()
			{
				mainForm->getJobs()->StartPostponedWorkers();

				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
					if (w->second->IsEncoding)
						return;

				mainForm->runAfterEncodingCommands();
			}

			void JobControl::ShowSummary()
			{
				summary->Show();
			}

			void JobControl::HideSummary()
			{
				summary->Hide();
			}

			const bool &JobControl::getSummaryVisible() const
			{
				return summary->Visible;
			}

			void JobControl::SetWorkerVisible(const QString &p, bool p_2)
			{
				if (p_2)
					workers[p]->Show();
				else
					workers[p]->Hide();
			}

			void JobControl::newWorkerButton_Click()
			{
				RequestNewWorker();
			}

			void JobControl::UpdateProgress(const QString &name)
			{
				summary->RefreshInfo(name);
			}

			void JobControl::ShutDown(JobWorker *w)
			{
				workers.erase(w->getName());
				if (w->Visible)
//C# TO C++ CONVERTER TODO TASK: Lambda expressions and anonymous methods are not converted to native C++ unless the option to convert to C++0x lambdas is selected:
					Util::ThreadSafeRun(w, delegate
					{
						w->Close();
					}
				   );
				summary->Remove(w->getName());
			}

			QVector<Pair<QString, bool>*> JobControl::ListProgressWindows()
			{
				QVector<Pair<QString, bool>*> ans = QVector<Pair<QString, bool>*>();
				for (QMap<QString, JobWorker*>::const_iterator w = workers.begin(); w != workers.end(); ++w)
				{
					if (w->second->IsProgressWindowAvailable)
						ans.push_back(new Pair<QString, bool>(w->second->Name, w->second->IsProgressWindowVisible));
				}
				return ans;
			}

			void JobControl::HideProgressWindow(const QString &p)
			{
				if (workers[p]->getIsProgressWindowAvailable())
					workers[p]->HideProcessWindow();
			}

			void JobControl::ShowProgressWindow(const QString &p)
			{
				if (workers[p]->getIsProgressWindowAvailable())
					workers[p]->ShowProcessWindow();
			}

			void JobControl::cbAfterEncoding_SelectedIndexChanged()
			{
				currentAfterEncoding = static_cast<AfterEncoding>(cbAfterEncoding->SelectedIndex);
			}

			void JobControl::Dispose(bool disposing)
			{
				if (disposing && (components != 0))
				{
					delete components;
				}
				UserControl::Dispose(disposing);
			}

			void JobControl::InitializeComponent()
			{
				this->lblAfterEncoding = new System::Windows::Forms::Label();
				this->newWorkerButton = new QPushButton;
				this->tableLayoutPanel1 = new System::Windows::Forms::TableLayoutPanel();
				this->cbAfterEncoding = new System::Windows::Forms::ComboBox();
				this->helpButton1 = new MeXgui::core::gui::HelpButton();
				this->jobQueue = new MeXgui::core::gui::JobQueue();
				this->tableLayoutPanel1->SuspendLayout();
				this->SuspendLayout();
				// 
				// lblAfterEncoding
				// 
				this->lblAfterEncoding->AutoSize = true;
				this->lblAfterEncoding->Dock = System::Windows::Forms::DockStyle::Fill;
				this->lblAfterEncoding->Location = new System::Drawing::Point(3, 0);
				this->lblAfterEncoding->Name = "lblAfterEncoding";
				this->lblAfterEncoding->Size = new System::Drawing::Size(79, 29);
				this->lblAfterEncoding->TabIndex = 1;
				this->lblAfterEncoding->Text = "After encoding:";
				this->lblAfterEncoding->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				// 
				// newWorkerButton
				// 
				this->newWorkerButton->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->newWorkerButton->AutoSize = true;
				this->newWorkerButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->newWorkerButton->Location = new System::Drawing::Point(431, 3);
				this->newWorkerButton->Name = "newWorkerButton";
				this->newWorkerButton->Size = new System::Drawing::Size(74, 23);
				this->newWorkerButton->TabIndex = 2;
				this->newWorkerButton->Text = "New worker";
				this->newWorkerButton->UseVisualStyleBackColor = true;
				this->newWorkerButton->Click += new System::EventHandler(this, &JobControl::newWorkerButton_Click);
				// 
				// tableLayoutPanel1
				// 
				this->tableLayoutPanel1->AutoSize = true;
				this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->tableLayoutPanel1->ColumnCount = 4;
				this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle());
				this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100));
				this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle());
				this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle());
				this->tableLayoutPanel1->Controls->Add(this->lblAfterEncoding, 0, 0);
				this->tableLayoutPanel1->Controls->Add(this->cbAfterEncoding, 1, 0);
				this->tableLayoutPanel1->Controls->Add(this->newWorkerButton, 2, 0);
				this->tableLayoutPanel1->Controls->Add(this->helpButton1, 3, 0);
				this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->tableLayoutPanel1->Location = new System::Drawing::Point(0, 521);
				this->tableLayoutPanel1->Name = "tableLayoutPanel1";
				this->tableLayoutPanel1->RowCount = 1;
				this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle());
				this->tableLayoutPanel1->Size = new System::Drawing::Size(553, 29);
				this->tableLayoutPanel1->TabIndex = 4;
				// 
				// cbAfterEncoding
				// 
				this->cbAfterEncoding->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right)));
				this->cbAfterEncoding->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->cbAfterEncoding->FormattingEnabled = true;
				this->cbAfterEncoding->Items->AddRange(new object[4] {"Do Nothing", "Shutdown", "Run Command", "Close MeXgui"});
				this->cbAfterEncoding->Location = new System::Drawing::Point(88, 4);
				this->cbAfterEncoding->Name = "cbAfterEncoding";
				this->cbAfterEncoding->Size = new System::Drawing::Size(337, 21);
				this->cbAfterEncoding->TabIndex = 5;
				this->cbAfterEncoding->SelectedIndexChanged += new System::EventHandler(this, &JobControl::cbAfterEncoding_SelectedIndexChanged);
				// 
				// helpButton1
				// 
				this->helpButton1->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->helpButton1->setArticleName("Main Window#Queue");
				this->helpButton1->AutoSize = true;
				this->helpButton1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->helpButton1->Location = new System::Drawing::Point(511, 3);
				this->helpButton1->Name = "helpButton1";
				this->helpButton1->Size = new System::Drawing::Size(39, 23);
				this->helpButton1->TabIndex = 3;
				// 
				// jobQueue
				// 
				this->jobQueue->Dock = System::Windows::Forms::DockStyle::Fill;
				this->jobQueue->Location = new System::Drawing::Point(0, 0);
				this->jobQueue->Name = "jobQueue";
				this->jobQueue->setPauseResumeMode(MeXgui::core::gui::Disabled);
				this->jobQueue->Size = new System::Drawing::Size(553, 521);
				this->jobQueue->setStartStopMode(MeXgui::core::gui::Start);
				this->jobQueue->TabIndex = 0;
				this->jobQueue->AbortClicked += new System::EventHandler(this, &JobControl::jobQueue_AbortClicked);
				this->jobQueue->StartClicked += new System::EventHandler(this, &JobControl::jobQueue_StartClicked);
				this->jobQueue->StopClicked += new System::EventHandler(this, &JobControl::jobQueue_StopClicked);
				// 
				// JobControl
				// 
				this->AutoScaleDimensions = new System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->Controls->Add(this->jobQueue);
				this->Controls->Add(this->tableLayoutPanel1);
				this->Name = "JobControl";
				this->Size = new System::Drawing::Size(553, 550);
				this->tableLayoutPanel1->ResumeLayout(false);
				this->tableLayoutPanel1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}

			void JobControl::InitializeInstanceFields()
			{
				allJobs = QMap<QString, TaggedJob*>();
				workers = QMap<QString, JobWorker*>();
				nextJobLock = new object();
				delete components;
			}
		}
	}
}
