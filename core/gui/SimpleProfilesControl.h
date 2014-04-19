#pragma once

#include "packages/audio/AudioCodecSettings.h"
#include "core/plugins/interfaces/Profile.h"
#include "StandardAndCustomComboBox.h"
#include "SimpleProfilesControl.h"
#include "core/details/ProfileManager.h"
#include "core/util/LogItem.h"
#include "packages/audio/naac/NeroAACSettings.h"
#include "MainForm.h"
#include "packages/audio/qaac/QaacSettings.h"
#include <QString>

// ****************************************************************************
// 
// Copyright (C) 2005-2012 Doom9 & al
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








using namespace MeXgui::core::util;

namespace MeXgui
{
	namespace core
	{
		namespace gui
		{
			
			class ProfileCouldntBeSelectedException : public MeXguiException
			{
			private:
				QString name;
			public:
				const QString &getProfileName() const;

				ProfileCouldntBeSelectedException(const QString &name);
			};

			
			class SimpleProfilesControl : public UserControl
			{
				public:
				~SimpleProfilesControl()
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
				SimpleProfilesControl();

				void SetSettings(AudioCodecSettings *value);


//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
				const Profile &getSelectedProfile() const;

				void SelectProfile(const QString &fqname);

				void SelectProfile(Profile *prof);

				void SetProfileNameOrWarn(const QString &fqname);

			private:
				ProfileManager *manager;

			public:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
				const ProfileManager &getManager() const;
				void setManager(const ProfileManager &value);

			private:
				void ProfilesChanged(object *_, QEvent *__);

				QString profileSet;
				/// <summary>
				/// The string describing the profile set to request from the profile manager
				/// </summary>
			public:
				const QString &getProfileSet() const;
				void setProfileSet(const QString &value);

			protected:
				void RefreshProfiles();

				void raiseProfileChangedEvent();

//C# TO C++ CONVERTER TODO TASK: There is no direct equivalent to .NET events in native C++:
//				public event EventHandler SelectedProfileChanged;

			private:
				void comboBox1_SelectedIndexChanged(QObject *sender, QEvent *e);


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
				System::Windows::Forms::ComboBox *comboBox1;
				System::Windows::Forms::TableLayoutPanel *tableLayoutPanel1;


			private:
				void InitializeInstanceFields();
			};
		}
	}
}
