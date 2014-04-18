﻿#pragma once

#include "core/gui/MeXgui.MainForm.h"
#include "core/details/MeXguiSettings.h"
#include "HDStreamsExJob.h"
#include "Eac3ToInfo.h"
#include "Extensions.h"
#include "eac3to/Feature.h"
#include "core/util/LogItem.h"
#include "eac3to/Stream.h"
#include "eac3to/StreamType.h"
#include "core/util/LanguageSelectionContainer.h"
#include "core/util/Drives.h"
#include "core/details/CodecManager.h"
#include "eac3to/File.h"
#include "CustomDataGridView.h"
#include <QString>
#include <QMap>
#include <QVector>
#include "stringconverter.h"

// ****************************************************************************
// 
// Copyright (C) 2005-2013 Doom9 & al
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// 
// ****************************************************************************




//using namespace System::Collections::Generic;



//using namespace System::Diagnostics;

//using namespace System::Text;

//using namespace System::Text::RegularExpressions;



using namespace MeXgui::core::plugins::interfaces;
using namespace MeXgui::core::details;
using namespace MeXgui::core::util;
using namespace eac3to;

// Copyright (C) 2005-2012 Doom9 & al

namespace MeXgui
{
	namespace packages
	{
		namespace tools
		{
			namespace hdbdextractor
			{
				class HdBdStreamExtractor : public System::Windows::Forms::Form
				{
				private:
					MainForm *mainForm;
					MeXguiSettings *settings;
					HDStreamsExJob *lastJob;
					int inputType;
					QString dummyInput;
					Eac3toInfo *_oEac3toInfo;
					QVector<QString> input;

					public:
					~HdBdStreamExtractor()
					{
						this->Dispose(true);
					}

//C# TO C++ CONVERTER WARNING: Unlike C#, there is no automatic call to this finalizer method in native C++:
					private:
					void Finalize()
					{
						this->Dispose(false);
					}

				public:
					HdBdStreamExtractor(MainForm *info);


				private:
					void SetProgress(object *sender, ProgressChangedEventArgs *e);

				public:
					void SetData(object *sender, RunWorkerCompletedEventArgs *e);

					typedef void (*SetToolStripProgressBarValueCallback)(int value);
				private:
					void SetToolStripProgressBarValue(int value);

					typedef void (*SetToolStripLabelTextCallback)(const QString &message);
					void SetToolStripLabelText(const QString &message);

					typedef void (*ResetCursorCallback)(System::Windows::Forms::Cursor *cursor);
					void ResetCursor(System::Windows::Forms::Cursor *cursor);

					void FolderInputSourceButton_Click();

					void FolderOutputSourceButton_Click();

					void FeatureButton_Click();

					void StreamDataGridView_DataSourceChanged();

					void QueueButton_Click();

				public:
					const HDStreamsExJob &getLastJob() const;
					void setLastJob(const HDStreamsExJob &value);
					const bool &getJobCreated() const;

				private:
					QString GenerateArguments();

					void CancelButton2_Click();

					void HelpButton2_Click();

					void HdBrStreamExtractor_FormClosing(object *sender, System::Windows::Forms::FormClosingEventArgs *e);

					bool IsStreamCheckedForExtract();

					void Eac3toLinkLabel_LinkClicked(object *sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs *e);

					void FeatureDataGridView_SelectionChanged();

					void FeatureDataGridView_DataBindingComplete(object *sender, System::Windows::Forms::DataGridViewBindingCompleteEventArgs *e);

					void FeatureDataGridView_RowLeave(object *sender, System::Windows::Forms::DataGridViewCellEventArgs *e);

					void FeatureDataGridView_DataSourceChanged();

					void SelectTracks();

					QString getBDMVPath(const QString &path, const QString &file);


					/// <summary>
					/// Required designer variable.
					/// </summary>
					System::ComponentModel::IContainer *components;

					/// <summary>
					/// Clean up any resources being used.
					/// </summary>
					/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
					void Dispose(bool disposing);

					/// <summary>
					/// Required method for Designer support - do not modify
					/// the contents of this method with the code editor.
					/// </summary>
					void InitializeComponent();

					System::Windows::Forms::FolderBrowserDialog *folderBrowserDialog1;
					System::Windows::Forms::GroupBox *InputGroupBox;
					System::Windows::Forms::TextBox *FolderInputTextBox;
					System::Windows::Forms::Button *FolderInputSourceButton;
					System::Windows::Forms::BindingSource *FeatureBindingSource;
					System::Windows::Forms::GroupBox *FeatureGroupBox;
					System::Windows::Forms::BindingSource *StreamsBindingSource;
					System::Windows::Forms::GroupBox *StreamGroupBox;
					MeXgui::packages::tools::hdbdextractor::CustomDataGridView *StreamDataGridView;
					System::Windows::Forms::Button *HelpButton2;
					System::Windows::Forms::LinkLabel *Eac3toLinkLabel;
					System::Windows::Forms::Button *QueueButton;
					System::Windows::Forms::Button *CancelButton2;
					System::Windows::Forms::StatusStrip *StatusStrip;
					System::Windows::Forms::ToolStripStatusLabel *ToolStripStatusLabel;
					System::Windows::Forms::ToolStripProgressBar *ToolStripProgressBar;
					MeXgui::packages::tools::hdbdextractor::CustomDataGridView *FeatureDataGridView;
					System::Windows::Forms::DataGridViewTextBoxColumn *FeatureNumberDataGridViewTextBoxColumn1;
					System::Windows::Forms::DataGridViewTextBoxColumn *FeatureNameDataGridViewTextBoxColumn;
					System::Windows::Forms::DataGridViewTextBoxColumn *FeatureDescriptionDataGridViewTextBoxColumn;
					System::Windows::Forms::DataGridViewComboBoxColumn *FeatureFileDataGridViewComboBoxColumn;
					System::Windows::Forms::DataGridViewTextBoxColumn *FeatureDurationDataGridViewTextBoxColumn;
					System::Windows::Forms::GroupBox *OutputGroupBox;
					System::Windows::Forms::Button *FolderOutputSourceButton;
					System::Windows::Forms::TextBox *FolderOutputTextBox;
					System::Windows::Forms::RadioButton *FolderSelection;
					System::Windows::Forms::RadioButton *FileSelection;
					System::Windows::Forms::OpenFileDialog *openFileDialog1;
					System::Windows::Forms::Button *FeatureButton;
					System::Windows::Forms::BindingSource *extractTypesBindingSource;
					System::Windows::Forms::DataGridViewCheckBoxColumn *StreamExtractCheckBox;
					System::Windows::Forms::DataGridViewTextBoxColumn *StreamNumberTextBox;
					System::Windows::Forms::DataGridViewTextBoxColumn *StreamTypeTextBox;
					System::Windows::Forms::DataGridViewTextBoxColumn *StreamDescriptionTextBox;
					System::Windows::Forms::DataGridViewComboBoxColumn *StreamExtractAsComboBox;
					System::Windows::Forms::DataGridViewTextBoxColumn *StreamAddOptionsTextBox;
					System::Windows::Forms::DataGridViewTextBoxColumn *numberDataGridViewTextBoxColumn;
					System::Windows::Forms::DataGridViewTextBoxColumn *nameDataGridViewTextBoxColumn;
					System::Windows::Forms::DataGridViewTextBoxColumn *typeDataGridViewTextBoxColumn;
					System::Windows::Forms::DataGridViewTextBoxColumn *languageDataGridViewTextBoxColumn;
					System::Windows::Forms::CheckBox *closeOnQueue;

				private:
					void InitializeInstanceFields();
				};
			}
		}
	}
}
