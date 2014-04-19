#pragma once

#include "core/util/LanguageSelectionContainer.h"
#include "core/util/EnumProxy.h"
#include "OneClickSettings.h"
#include "core/util/DragDropUtil.h"
#include "core/gui/MainForm.h"
#include "packages/audio/AudioCodecSettings.h"
#include "OneClickStream.h"
#include "core/details/TrackInfo.h"
#include "core/gui/NiceComboBox.h"
#include "core/gui/StandardAndCustomComboBox.h"
#include "core/util/LogItem.h"
#include "core/util/VideoUtil.h"
#include "packages/reader/vobsub/idxReader.h"
#include "core/util/PrettyFormatting.h"
#include "core/gui/ConfigableProfilesControl.h"
#include "core/gui/FileSCBox.h"
#include "core/plugins/interfaces/ISettingsProvider.h"
#include <QString>
#include <QMap>
#include <QVector>

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





using namespace MeXgui::core::gui;
using namespace MeXgui::core::util;


namespace MeXgui
{
	class OneClickStreamControl : public UserControl
	{
//C# TO C++ CONVERTER TODO TASK: There is no direct equivalent to .NET events in native C++:
//		public event EventHandler SomethingChanged;

		public:
		~OneClickStreamControl()
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
		OneClickStreamControl();

		void enableDragDrop();

		void initProfileHandler();

		void SelectProfileNameOrWarn(const QString &fqname);

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
		const AudioEncodingMode &getEncodingMode() const;
		void setEncodingMode(const AudioEncodingMode &value);

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
		const AudioCodecSettings &getEncoderProfileSettings() const;

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
		const QString &getEncoderProfile() const;

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
		const OneClickStream &getStream() const;

		void setStream(const OneClickStream &value);

	private:
		QString defaultLanguage;
	public:
		void setDefaultLanguage(const QString &value);
		const QString &getDefaultLanguage() const;

	private:
		bool showDelay;
	public:
		void setShowDelay(const bool &value);
		const bool &getShowDelay() const;

	private:
		bool showDefaultStream;
	public:
		void setShowDefaultStream(const bool &value);
		const bool &getShowDefaultStream() const;

	private:
		bool showForceStream;
	public:
		void setShowForceStream(const bool &value);
		const bool &getShowForceStream() const;

		const QString &getFilter() const;
		void setFilter(const QString &value);

		const object *getStandardStreams() const;
		void setStandardStreams(object value[]);

		const object *getCustomStreams() const;
		void setCustomStreams(object value[]);

		/// <summary>
		/// Index of the selected item, or -1 if the selected item isn't on the list
		/// or if it is in a submenu.
		/// </summary>
		const int &getSelectedStreamIndex() const;
		void setSelectedStreamIndex(const int &value);

		/// <summary>
		/// Selected Item
		/// </summary>
		const SCItem &getSelectedItem() const;

		/// <summary>
		/// Selected Stream
		/// </summary>
		const OneClickStream &getSelectedStream() const;

		/// <summary>
		/// Selected File
		/// </summary>
		const QString &getSelectedFile() const;

		void SetLanguage(const QString &lang);

	private:
		void removeTrack_Click();

		void raiseEvent();

		void chkForceStream_CheckedChanged();

		void chkDefaultStream_CheckedChanged();

		void setFileName(const QString &strFileName);

//C# TO C++ CONVERTER TODO TASK: There is no direct equivalent to .NET events in native C++:
//		public event EventHandler FileUpdated;
		void input_SelectionChanged(object *sender, const QString &val);

		void encoderProfile_SelectedProfileChanged();

		void cbEncodingMode_SelectedIndexChanged();


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


	protected:
		System::Windows::Forms::TextBox *subName;
		System::Windows::Forms::Label *SubNamelabel;
		System::Windows::Forms::ComboBox *subtitleLanguage;
		System::Windows::Forms::Label *subtitleLanguageLabel;
		System::Windows::Forms::Label *subtitleInputLabel;
		System::Windows::Forms::Label *delayLabel;
		System::Windows::Forms::NumericUpDown *delay;
	private:
		System::Windows::Forms::TableLayoutPanel *tableLayoutPanel1;
	public:
		System::Windows::Forms::CheckBox *chkDefaultStream;
		System::Windows::Forms::CheckBox *chkForceStream;
	protected:
		System::Windows::Forms::Button *removeSubtitleTrack;
	private:
		core::gui::FileSCBox *input;
		core::gui::ConfigableProfilesControl *encoderProfile;
		System::Windows::Forms::ComboBox *cbEncodingMode;
	protected:
		System::Windows::Forms::Label *label2;
		System::Windows::Forms::Label *label1;

	private:
		void InitializeInstanceFields();
	};
}
