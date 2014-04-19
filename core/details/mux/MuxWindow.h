#pragma once

#include "baseMuxWindow.h"
#include "core/details/PackageSystem.h"
#include "core/util/GenericRegisterer.h"
#include "core/plugins/interfaces/Job.h"
#include "MuxJob.h"
#include "core/gui/MainForm.h"
#include "core/plugins/interfaces/IMuxing.h"
#include "core/details/Streams.h"
#include "core/util/FileSize.h"
#include "core/util/DAR.h"
#include "core/details/CodecManager.h"
#include "core/gui/FileBar.h"
#include "core/gui/FileBar.h"
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




//using namespace System::Collections::Generic;



//using namespace System::Data;

//using namespace System::Diagnostics;





//using namespace System::Text;



using namespace MeXgui::core::util;
using namespace MeXgui::core::details;

namespace MeXgui
{
	class MuxWindow : public baseMuxWindow
	{
	public:
		static IDable<MeXgui::core::details::ReconfigureJob> *const Configurer;

		public:
		~MuxWindow()
		{
			this->Dispose(true);
		}

//C# TO C++ CONVERTER WARNING: Unlike C#, there is no automatic call to this finalizer method in native C++:
		private:
		void Finalize()
		{
			this->Dispose(false);
		}

	private:
		static MeXgui::Job *ReconfigureJob(MeXgui::Job *j);

	public:
		MuxWindow(IMuxing *muxer, MainForm *mainForm);

	protected:
		virtual void muxButton_Click();

		virtual MuxJob *generateMuxJob();

	public:
		const MuxJob &getJob() const;
		void setJob(const MuxJob &value);

	private:
		void setConfig(const QString &videoInput, const QString &videoName, const QString &muxedInput, Nullable<decimal> framerate, MuxStream audioStreams[], MuxStream subtitleStreams[], const QString &chapterFile, const QString &output, Nullable<FileSize> splitSize, Nullable<Dar> dar, const QString &deviceType);

	protected:
		virtual void ChangeOutputExtension();

	private:
		ContainerType *getContainerType(const QString &outputFilename);

	protected:
		virtual bool isFPSRequired();

	private:
		void muxedInput_FileSelected(FileBar *sender, FileBarEventArgs *args);


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


		FileBar *muxedInput;

	private:
		void InitializeInstanceFields();
	};
}
