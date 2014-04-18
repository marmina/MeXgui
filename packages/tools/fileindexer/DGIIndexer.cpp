﻿#include "DGIIndexer.h"




//using namespace System::Collections::Generic;



//using namespace System::Text;

//using namespace System::Text::RegularExpressions;
using namespace MeXgui::core::util;

namespace MeXgui
{

JobProcessorFactory *const DGIIndexer::Factory = new JobProcessorFactory(new ProcessorFactory(&init), "DGIIndexer");

	IJobProcessor *DGIIndexer::init(MainForm *mf, Job *j)
	{
		if (dynamic_cast<DGIIndexJob*>(j) != 0)
			return new DGIIndexer(mf->getSettings()->getDgnvIndexPath());
		return 0;
	}

	DGIIndexer::DGIIndexer(const QString &executableName)
	{
		executable = executableName;
	}

	void DGIIndexer::ProcessLine(const QString &line, StreamType stream, ImageType oType)
	{
		if (Regex::IsMatch(line, "^[0-9]{1,3}$", RegexOptions::Compiled))
		{
			su->setPercentageDoneExact(int::Parse(line));
			return;
		}

		if (line.find("Project") != string::npos)
			su->setStatus("Creating DGI...");
		else
			su->setStatus("Creating " + line);
		CommandlineJobProcessor::startTime = DateTime::Now;
		CommandlineJobProcessor::ProcessLine(line, stream, oType);
	}

	void DGIIndexer::checkJobIO()
	{
		try
		{
			if (!job->Output.empty())
				FileUtil::ensureDirectoryExists(Path::GetDirectoryName(job->Output));
		}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to the exception 'finally' clause:
		finally
		{
			CommandlineJobProcessor::checkJobIO();
		}
		su->setStatus("Creating DGI...");
	}

	const QString &DGIIndexer::getCommandline() const
	{
		StringBuilder *sb = new StringBuilder();
		sb->Append("-i \"" + job->Input + "\"");
		if (MainForm::Instance->getSettings()->getAutoLoadDG() && Path::GetExtension(job->Input)->ToLower(System::Globalization::CultureInfo::InvariantCulture)->Equals(".vob"))
		{
			QString strFile = Path::GetFileNameWithoutExtension(job->Input);
			int iNumber = 0;
			if (int::TryParse(strFile.substr(strFile.length() - 1), iNumber))
			{
				while (++iNumber < 10)
				{
					QString strNewFile = "";
					strNewFile = Path::Combine(Path::GetDirectoryName(job->Input), strFile.substr(0, strFile.length() - 1) + StringConverterHelper::toString(iNumber) + ".vob");
					if (File::Exists(strNewFile))
						sb->Append(",\"" + strNewFile + "\"");
					else
						break;
				}
			}
		}
		if (job->getDemuxVideo())
			sb->Append(" -od \"" + job->Output + "\" -e -h");
		else
			sb->Append(" -o \"" + job->Output + "\" -e -h");
		if (job->getDemuxMode() == 2)
			sb->Append(" -a"); // demux everything
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return sb->ToString();
	}
}
