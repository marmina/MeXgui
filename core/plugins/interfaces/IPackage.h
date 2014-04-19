#pragma once

#include "core/util/GenericRegisterer.h"
#include "core/gui/MainForm.h"

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

//using namespace System::Text;



using namespace MeXgui;

namespace MeXgui
{
	namespace core
	{
		namespace plugins
		{
			namespace interfaces
			{
				class ITool : public IIDable
				{
				public:
					virtual const QString &getName() const = 0;
					virtual void Run(MainForm*) = 0;
					virtual const System::Windows::Forms::Shortcut &getShortcuts() const = 0;
				};

				class IOption : public IIDable
				{
				public:
					virtual const QString &getName() const = 0;
					virtual void Run(MainForm*) = 0;
					virtual const System::Windows::Forms::Shortcut &getShortcuts() const = 0;
				};
			}
		}
	}
}
