#pragma once

#include "Util.h"
#include "FileUtil.h"
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

//using namespace System::Text;



namespace MeXgui
{
	namespace core
	{
		namespace util
		{
			typedef void (*SingleFileReceiver)(const QString &file);
			typedef void (*MultiFileReceiver)(QString& files[]);

			class DragDropUtil
			{
			public:
				static void RegisterSingleFileDragDrop(Control *c, SingleFileReceiver r);

				static void RegisterSingleFileDragDrop(Control *c, SingleFileReceiver r, const QString &filter);

				static void RegisterSingleFileDragDrop(Control *c, SingleFileReceiver r, Getter<QString> filter);

				static void RegisterMultiFileDragDrop(Control *c, MultiFileReceiver r);

				static void RegisterMultiFileDragDrop(Control *c, MultiFileReceiver r, const QString &filter);

				static void RegisterMultiFileDragDrop(Control *c, MultiFileReceiver r, Getter<QString> filter);
			};
		}
	}
}
