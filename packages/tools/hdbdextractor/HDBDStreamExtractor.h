﻿#pragma once

#include "core/plugins/interfaces/IPackage.h"
#include "core/gui/MeXgui.MainForm.h"
#include "MeXgui.packages.tools.hdbdextractor.HdBdStreamExtractor.h"
#include <QString>

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

namespace MeXgui
{
	namespace packages
	{
		namespace tools
		{
			namespace hdbdextractor
			{

				class HdBdExtractorTool : public ITool
				{


				public:
					const QString &getName() const;

					void Run(MainForm *info);

					const Shortcut *getShortcuts() const;



					const QString &getID() const;

				};
			}
		}
	}
}
