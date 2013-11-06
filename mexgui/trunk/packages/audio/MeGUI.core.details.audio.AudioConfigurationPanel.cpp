#include "MeGUI.core.details.audio.AudioConfigurationPanel.h"

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
		namespace details
		{
			namespace audio
			{

				AudioConfigurationPanel::AudioConfigurationPanel()
				{
					InitializeInstanceFields();
					_avisynthChannelSet = EnumProxy::CreateArray(this->getIsMultichanelSupported() ? (this->getIsMultichanelRequed() ? new object[]{Upmix, UpmixUsingSoxEq, UpmixWithCenterChannelDialog} : new object[]{KeepOriginal, StereoDownmix, DPLDownmix, DPLIIDownmix, ConvertToMono, Upmix, UpmixUsingSoxEq, UpmixWithCenterChannelDialog}) : new object[]{StereoDownmix, DPLDownmix, DPLIIDownmix, ConvertToMono});

					InitializeComponent();
					this->primaryDecoding->DataSource = EnumProxy::CreateArray(new object[] {NicAudio, FFAudioSource, DirectShow, BassAudio});
					this->besweetDownmixMode->DataSource = _avisynthChannelSet;
					this->besweetDownmixMode->BindingContext = new BindingContext();
					this->cbSampleRate->SelectedIndex = 0;
				}

				void AudioConfigurationPanel::showCommandLine()
				{

				}

				const bool &AudioConfigurationPanel::getIsMultichanelSupported() const
				{
					return true;
				}

				const bool &AudioConfigurationPanel::getIsMultichanelRequed() const
				{
					return false;
				}

				const MeGUI::AudioCodecSettings &AudioConfigurationPanel::getCodecSettings() const
				{
					throw new NotImplementedException("Must be overridden");
				}

				void AudioConfigurationPanel::setCodecSettings(const AudioCodecSettings &value)
				{
					throw new NotImplementedException("Must be overridden");
				}

				const MeGUI::AudioCodecSettings &AudioConfigurationPanel::getSettings() const
				{
					AudioCodecSettings *fas = getCodecSettings();
					fas->setPreferredDecoder(static_cast<AudioDecodingEngine>(primaryDecoding->SelectedIndex));
					EnumProxy *o = dynamic_cast<EnumProxy*>(besweetDownmixMode->SelectedItem);
					if (o != 0)
						fas->setDownmixMode(static_cast<ChannelMode>(o->getRealValue()));
					fas->setAutoGain(autoGain->Checked);
					fas->setSampleRateType(cbSampleRate->SelectedIndex);
					fas->setApplyDRC(applyDRC->Checked);
					fas->setNormalize(static_cast<int>(normalize->Value));
					return fas;
				}

				void AudioConfigurationPanel::setSettings(const AudioCodecSettings &value)
				{
					AudioCodecSettings *fas = value;
					besweetDownmixMode->SelectedItem = EnumProxy::Create(fas->getDownmixMode());
					primaryDecoding->SelectedIndex = static_cast<int>(fas->getPreferredDecoder());
					autoGain->Checked = fas->getAutoGain();
					cbSampleRate->SelectedIndex = fas->getSampleRateType();
					applyDRC->Checked = fas->getApplyDRC();
					normalize->Value = fas->getNormalize();
					setCodecSettings(fas);
				}

				void AudioConfigurationPanel::textField_KeyPress(object *sender, KeyPressEventArgs *e)
				{
					if (!isdigit(e->KeyChar) && static_cast<int>(Keys::Back) != static_cast<int>(e->KeyChar))
						e->Handled = true;
				}

				void AudioConfigurationPanel::besweetDelay_TextChanged(object *sender, System::EventArgs *e)
				{
				}

				void AudioConfigurationPanel::applyDRC_CheckedChanged(object *sender, EventArgs *e)
				{
					autoGain->Checked = applyDRC->Checked;
					autoGain_CheckedChanged(sender, e);
				}

				void AudioConfigurationPanel::autoGain_CheckedChanged(object *sender, EventArgs *e)
				{
					normalize->Enabled = autoGain->Checked;
				}

				void AudioConfigurationPanel::Dispose(bool disposing)
				{
					if (disposing && (components != 0))
					{
						delete components;
					}
					UserControl::Dispose(disposing);
				}

				void AudioConfigurationPanel::InitializeComponent()
				{
					this->encoderGroupBox = new System::Windows::Forms::GroupBox();
					this->besweetOptionsGroupbox = new System::Windows::Forms::GroupBox();
					this->tableLayoutPanel1 = new System::Windows::Forms::TableLayoutPanel();
					this->cbSampleRate = new System::Windows::Forms::ComboBox();
					this->primaryDecoding = new System::Windows::Forms::ComboBox();
					this->besweetDownmixMode = new System::Windows::Forms::ComboBox();
					this->applyDRC = new System::Windows::Forms::CheckBox();
					this->normalize = new System::Windows::Forms::NumericUpDown();
					this->autoGain = new System::Windows::Forms::CheckBox();
					this->label1 = new System::Windows::Forms::Label();
					this->BesweetChannelsLabel = new System::Windows::Forms::Label();
					this->lbSampleRate = new System::Windows::Forms::Label();
					this->besweetOptionsGroupbox->SuspendLayout();
					this->tableLayoutPanel1->SuspendLayout();
					(static_cast<System::ComponentModel::ISupportInitialize*>(this->normalize))->BeginInit();
					this->SuspendLayout();
					// 
					// encoderGroupBox
					// 
					this->encoderGroupBox->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right)));
					this->encoderGroupBox->Location = new System::Drawing::Point(1, 155);
					this->encoderGroupBox->Name = "encoderGroupBox";
					this->encoderGroupBox->Size = new System::Drawing::Size(390, 64);
					this->encoderGroupBox->TabIndex = 9;
					this->encoderGroupBox->TabStop = false;
					this->encoderGroupBox->Text = "placeholder for encoder options";
					// 
					// besweetOptionsGroupbox
					// 
					this->besweetOptionsGroupbox->Controls->Add(this->tableLayoutPanel1);
					this->besweetOptionsGroupbox->Dock = System::Windows::Forms::DockStyle::Top;
					this->besweetOptionsGroupbox->Location = new System::Drawing::Point(0, 0);
					this->besweetOptionsGroupbox->Name = "besweetOptionsGroupbox";
					this->besweetOptionsGroupbox->Size = new System::Drawing::Size(394, 149);
					this->besweetOptionsGroupbox->TabIndex = 8;
					this->besweetOptionsGroupbox->TabStop = false;
					this->besweetOptionsGroupbox->Text = " Audio Options ";
					// 
					// tableLayoutPanel1
					// 
					this->tableLayoutPanel1->ColumnCount = 3;
					this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle());
					this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle());
					this->tableLayoutPanel1->ColumnStyles->Add(new System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100));
					this->tableLayoutPanel1->Controls->Add(this->cbSampleRate, 1, 2);
					this->tableLayoutPanel1->Controls->Add(this->primaryDecoding, 1, 0);
					this->tableLayoutPanel1->Controls->Add(this->besweetDownmixMode, 1, 1);
					this->tableLayoutPanel1->Controls->Add(this->applyDRC, 1, 3);
					this->tableLayoutPanel1->Controls->Add(this->normalize, 2, 4);
					this->tableLayoutPanel1->Controls->Add(this->autoGain, 1, 4);
					this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
					this->tableLayoutPanel1->Controls->Add(this->BesweetChannelsLabel, 0, 1);
					this->tableLayoutPanel1->Controls->Add(this->lbSampleRate, 0, 2);
					this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
					this->tableLayoutPanel1->Location = new System::Drawing::Point(3, 16);
					this->tableLayoutPanel1->Name = "tableLayoutPanel1";
					this->tableLayoutPanel1->RowCount = 5;
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20));
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20));
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20));
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20));
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20));
					this->tableLayoutPanel1->RowStyles->Add(new System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20));
					this->tableLayoutPanel1->Size = new System::Drawing::Size(388, 130);
					this->tableLayoutPanel1->TabIndex = 13;
					// 
					// cbSampleRate
					// 
					this->cbSampleRate->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right)));
					this->tableLayoutPanel1->SetColumnSpan(this->cbSampleRate, 2);
					this->cbSampleRate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					this->cbSampleRate->FormattingEnabled = true;
					this->cbSampleRate->Items->AddRange(new object[11] {"Keep Original", "Change to   8000 Hz", "Change to 11025 Hz", "Change to 22050 Hz", "Change to 32000 Hz", "Change to 44100 Hz", "Change to 48000 Hz", "Speed-up (23.976 to 25)", "Slow-down (25 to 23.976)", "Speed-up (24 to 25)", "Slow-down (25 to 24)"});
					this->cbSampleRate->Location = new System::Drawing::Point(103, 55);
					this->cbSampleRate->Name = "cbSampleRate";
					this->cbSampleRate->Size = new System::Drawing::Size(282, 21);
					this->cbSampleRate->TabIndex = 15;
					// 
					// primaryDecoding
					// 
					this->primaryDecoding->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right)));
					this->tableLayoutPanel1->SetColumnSpan(this->primaryDecoding, 2);
					this->primaryDecoding->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					this->primaryDecoding->FormattingEnabled = true;
					this->primaryDecoding->Location = new System::Drawing::Point(103, 3);
					this->primaryDecoding->Name = "primaryDecoding";
					this->primaryDecoding->Size = new System::Drawing::Size(282, 21);
					this->primaryDecoding->TabIndex = 13;
					// 
					// besweetDownmixMode
					// 
					this->besweetDownmixMode->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right)));
					this->tableLayoutPanel1->SetColumnSpan(this->besweetDownmixMode, 2);
					this->besweetDownmixMode->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
					this->besweetDownmixMode->Location = new System::Drawing::Point(103, 29);
					this->besweetDownmixMode->Name = "besweetDownmixMode";
					this->besweetDownmixMode->Size = new System::Drawing::Size(282, 21);
					this->besweetDownmixMode->TabIndex = 3;
					// 
					// applyDRC
					// 
					this->applyDRC->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)));
					this->applyDRC->AutoSize = true;
					this->tableLayoutPanel1->SetColumnSpan(this->applyDRC, 2);
					this->applyDRC->Location = new System::Drawing::Point(103, 84);
					this->applyDRC->Name = "applyDRC";
					this->applyDRC->Size = new System::Drawing::Size(194, 17);
					this->applyDRC->TabIndex = 9;
					this->applyDRC->Text = "Apply Dynamic Range Compression";
					this->applyDRC->UseVisualStyleBackColor = true;
					this->applyDRC->CheckedChanged += new System::EventHandler(this, &AudioConfigurationPanel::applyDRC_CheckedChanged);
					// 
					// normalize
					// 
					this->normalize->Anchor = System::Windows::Forms::AnchorStyles::Left;
					this->normalize->Location = new System::Drawing::Point(226, 107);
					this->normalize->Name = "normalize";
					this->normalize->Size = new System::Drawing::Size(52, 20);
					this->normalize->TabIndex = 10;
					this->normalize->Value = decimal(new int[4] {100, 0, 0, 0});
					// 
					// autoGain
					// 
					this->autoGain->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left)));
					this->autoGain->AutoSize = true;
					this->autoGain->Location = new System::Drawing::Point(103, 107);
					this->autoGain->Name = "autoGain";
					this->autoGain->Size = new System::Drawing::Size(117, 20);
					this->autoGain->TabIndex = 6;
					this->autoGain->Text = "Normalize Peaks to";
					this->autoGain->CheckedChanged += new System::EventHandler(this, &AudioConfigurationPanel::autoGain_CheckedChanged);
					// 
					// label1
					// 
					this->label1->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)));
					this->label1->AutoSize = true;
					this->label1->Location = new System::Drawing::Point(3, 13);
					this->label1->Name = "label1";
					this->label1->Size = new System::Drawing::Size(94, 13);
					this->label1->TabIndex = 14;
					this->label1->Text = "Preferred Decoder";
					// 
					// BesweetChannelsLabel
					// 
					this->BesweetChannelsLabel->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)));
					this->BesweetChannelsLabel->AutoSize = true;
					this->BesweetChannelsLabel->Location = new System::Drawing::Point(3, 39);
					this->BesweetChannelsLabel->Name = "BesweetChannelsLabel";
					this->BesweetChannelsLabel->Size = new System::Drawing::Size(86, 13);
					this->BesweetChannelsLabel->TabIndex = 2;
					this->BesweetChannelsLabel->Text = "Output Channels";
					// 
					// lbSampleRate
					// 
					this->lbSampleRate->Anchor = (static_cast<System::Windows::Forms::AnchorStyles*>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)));
					this->lbSampleRate->AutoSize = true;
					this->lbSampleRate->Location = new System::Drawing::Point(3, 65);
					this->lbSampleRate->Name = "lbSampleRate";
					this->lbSampleRate->Size = new System::Drawing::Size(68, 13);
					this->lbSampleRate->TabIndex = 11;
					this->lbSampleRate->Text = "Sample Rate";
					// 
					// AudioConfigurationPanel
					// 
					this->AutoScaleDimensions = new System::Drawing::SizeF(6, 13);
					this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
					this->Controls->Add(this->encoderGroupBox);
					this->Controls->Add(this->besweetOptionsGroupbox);
					this->Name = "AudioConfigurationPanel";
					this->Size = new System::Drawing::Size(394, 276);
					this->besweetOptionsGroupbox->ResumeLayout(false);
					this->tableLayoutPanel1->ResumeLayout(false);
					this->tableLayoutPanel1->PerformLayout();
					(static_cast<System::ComponentModel::ISupportInitialize*>(this->normalize))->EndInit();
					this->ResumeLayout(false);

				}

				void AudioConfigurationPanel::InitializeInstanceFields()
				{
					delete components;
				}
			}
		}
	}
}
