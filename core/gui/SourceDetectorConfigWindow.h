#pragma once

#include "SourceDetectorSettings.h"
#include "Properties.Settings.h"
#include "HelpButton.h"

// ****************************************************************************
// 
// Copyright (C) 2005-2009  Doom9 & al
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



//using namespace System::Data;



//using namespace System::Text;

//using namespace System::Threading;



namespace MeXgui
{
	class SourceDetectorConfigWindow : public System::Windows::Forms::Form
	{
		public:
		~SourceDetectorConfigWindow()
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
		SourceDetectorConfigWindow();

	private:
		void portionsAllowed_CheckedChanged(QObject *sender, QEvent *e);
	public:
		const SourceDetectorSettings &getSettings() const;
		void setSettings(const SourceDetectorSettings &value);


		/// <summary>
		/// Required designer variable.
		/// </summary>
	private:
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


		System::Windows::Forms::Label *analysisPercentLabel;
		System::Windows::Forms::NumericUpDown *analysisPercent;
		System::Windows::Forms::Label *minAnalyseSectionsLabel;
		System::Windows::Forms::NumericUpDown *minAnalyseSections;
		System::Windows::Forms::Label *hybridThresholdLabel;
		System::Windows::Forms::NumericUpDown *hybridThreshold;
		System::Windows::Forms::Label *hybridFOThresholdLabel;
		System::Windows::Forms::NumericUpDown *hybridFOThreshold;
		System::Windows::Forms::Label *portionThresholdLabel;
		System::Windows::Forms::NumericUpDown *portionThreshold;
		System::Windows::Forms::Label *maximumPortionsLabel;
		System::Windows::Forms::NumericUpDown *maximumPortions;
		System::Windows::Forms::CheckBox *portionsAllowed;
		System::Windows::Forms::Button *saveButton;
		System::Windows::Forms::Button *cancelButton;
		System::Windows::Forms::ComboBox *priority;
		System::Windows::Forms::Label *priorityLabel;
		MeXgui::core::gui::HelpButton *helpButton1;

	private:
		void InitializeInstanceFields();
	};
}
