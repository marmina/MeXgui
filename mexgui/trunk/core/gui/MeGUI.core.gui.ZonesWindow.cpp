﻿#include "MeGUI.core.gui.ZonesWindow.h"

//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Collections::Generic;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::ComponentModel;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Data;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Drawing;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Text;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Windows::Forms;
namespace MeGUI
{
	namespace core
	{
		namespace gui
		{

			ZonesWindow::ZonesWindow(MainForm *mf, const std::string &input)
			{
				InitializeInstanceFields();
				InitializeComponent();
				zonesControl1->setMainForm(mf);
				zonesControl1->setInput(input);
			}

			const Zone &ZonesWindow::getZones() const
			{
				return zonesControl1->getZones();
			}

			void ZonesWindow::setZones(const Zone &value[])
			{
				zonesControl1->setZones((value != 0) ? value : new Zone[0]);
			}

			void ZonesWindow::Dispose(bool disposing)
			{
				if (disposing && (components != 0))
				{
					delete components;
				}
				System::Windows::Forms::Form::Dispose(disposing);
			}

			void ZonesWindow::InitializeComponent()
			{
				System::ComponentModel::ComponentResourceManager *resources = new System::ComponentModel::ComponentResourceManager(ZonesWindow::typeid);
				this->zonesControl1 = new MeGUI::ZonesControl();
				this->flowLayoutPanel1 = new System::Windows::Forms::FlowLayoutPanel();
				this->button2 = new System::Windows::Forms::Button();
				this->button1 = new System::Windows::Forms::Button();
				this->flowLayoutPanel1->SuspendLayout();
				this->SuspendLayout();
				// 
				// zonesControl1
				// 
				this->zonesControl1->setCreditsStartFrame(0);
				this->zonesControl1->Dock = System::Windows::Forms::DockStyle::Fill;
				this->zonesControl1->setInput("");
				this->zonesControl1->setIntroEndFrame(0);
				this->zonesControl1->Location = new System::Drawing::Point(0, 0);
//C# TO C++ CONVERTER WARNING: C# to C++ Converter converted the original 'null' assignment to a call to 'delete', but you should review memory allocation of all pointer variables in the converted code:
				delete this->zonesControl1->getMainForm();
				this->zonesControl1->Name = "zonesControl1";
				this->zonesControl1->Size = new System::Drawing::Size(321, 417);
				this->zonesControl1->TabIndex = 0;
				this->zonesControl1->setZones(new MeGUI::Zone[0]);
				// 
				// flowLayoutPanel1
				// 
				this->flowLayoutPanel1->AutoSize = true;
				this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->flowLayoutPanel1->Controls->Add(this->button2);
				this->flowLayoutPanel1->Controls->Add(this->button1);
				this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::RightToLeft;
				this->flowLayoutPanel1->Location = new System::Drawing::Point(0, 417);
				this->flowLayoutPanel1->Name = "flowLayoutPanel1";
				this->flowLayoutPanel1->Size = new System::Drawing::Size(321, 29);
				this->flowLayoutPanel1->TabIndex = 1;
				// 
				// button2
				// 
				this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				this->button2->Location = new System::Drawing::Point(243, 3);
				this->button2->Name = "button2";
				this->button2->Size = new System::Drawing::Size(75, 23);
				this->button2->TabIndex = 1;
				this->button2->Text = "Cancel";
				this->button2->UseVisualStyleBackColor = true;
				// 
				// button1
				// 
				this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->button1->Location = new System::Drawing::Point(162, 3);
				this->button1->Name = "button1";
				this->button1->Size = new System::Drawing::Size(75, 23);
				this->button1->TabIndex = 0;
				this->button1->Text = "OK";
				this->button1->UseVisualStyleBackColor = true;
				// 
				// ZonesWindow
				// 
				this->AutoScaleDimensions = new System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = new System::Drawing::Size(321, 446);
				this->Controls->Add(this->zonesControl1);
				this->Controls->Add(this->flowLayoutPanel1);
				this->Font = new System::Drawing::Font("Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (static_cast<unsigned char>(0)));
				this->Icon = (static_cast<System::Drawing::Icon*>(resources->GetObject("$this.Icon")));
				this->Name = "ZonesWindow";
				this->Text = "ZonesWindow";
				this->flowLayoutPanel1->ResumeLayout(false);
				this->ResumeLayout(false);
				this->PerformLayout();

			}

			void ZonesWindow::InitializeInstanceFields()
			{
				delete components;
			}
		}
	}
}
