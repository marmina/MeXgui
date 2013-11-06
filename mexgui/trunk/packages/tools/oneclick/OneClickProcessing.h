﻿#pragma once

#include "MeGUI.OneClickWindow.h"
#include "core/util/LogItem.h"
#include "OneClickSettings.h"
#include "OneClickWindow.h"
#include "packages/reader/mediainfo/MediaInfoFile.h"
#include "packages/tools/fileindexer/MeGUI.FileIndexerWindow.h"
#include "packages/tools/chaptercreator/ChapterExtractor.h"
#include "packages/tools/chaptercreator/DvdExtractor.h"
#include "packages/tools/chaptercreator/ChapterInfo.h"
#include "packages/tools/chaptercreator/BlurayExtractor.h"
#include <string>
#include <vector>

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

//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Collections::Generic;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::IO;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Windows::Forms;

using namespace MeGUI::core::util;

namespace MeGUI
{
	namespace packages
	{
		namespace tools
		{
			namespace oneclick
			{
				class OneClickProcessing
				{
				private:
					OneClickWindow *oOneClickWindow;
					std::string strInput;
					LogItem *_log;
					OneClickSettings *_oSettings;

				public:
					OneClickProcessing(OneClickWindow *oWindow, const std::string &strFileOrFolderName, OneClickSettings *oSettings, LogItem *oLog);

					// batch processing
					OneClickProcessing(OneClickWindow *oWindow, std::vector<OneClickFilesToProcess*> &arrFilesToProcess, OneClickSettings *oSettings, LogItem *oLog);

					/// <summary>
					/// checks if the files/folders can be processed as DVD
					/// </summary>
					/// <returns>true if the files/folder can be processed as DVD, false otherwise</returns>
				private:
					bool getInputDVDBased(OneClickSettings *oSettings);

					/// <summary>
					/// checks if the files/folders can be processed as BluRay
					/// </summary>
					/// <returns>true if the files/folder can be processed as BluRay, false otherwise</returns>
					bool getInputBluRayBased(OneClickSettings *oSettings);

					/// <summary>
					/// checks if the input folder can be processed
					/// </summary>
					/// <returns>true if the folder can be processed, false otherwise</returns>
					bool getInputFolderBased(OneClickSettings *oSettings);

					/// <summary>
					/// checks if the input file can be processed
					/// </summary>
					/// <returns>true if the file can be processed, false otherwise</returns>
					bool getInputFileBased(OneClickSettings *oSettings);

					bool getInputIndexerBased(MediaInfoFile *iFile, OneClickSettings *oSettings);
				};
			}
		}
	}
}
