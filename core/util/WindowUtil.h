#pragma once

#include <QString>
#include "stringconverter.h"

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

//using namespace System::Diagnostics;

//using namespace System::Runtime::InteropServices;

//using namespace System::Text;



namespace MeXgui
{
	namespace core
	{
		namespace util
		{
			class WindowUtil
			{
			private:
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[FlagsAttribute]
				enum EXECUTION_STATE
				{
					ES_SYSTEM_REQUIRED = 0x00000001,
					ES_DISPLAY_REQUIRED = 0x00000002,
					// Legacy flag, should not be used.
					// ES_USER_PRESENT   = 0x00000004,
					ES_CONTINUOUS = 0x80000000,
				};

//C# TO C++ CONVERTER NOTE: The following .NET DllImport attribute was converted using the Microsoft-specific __declspec(dllimport):
//[DllImport("user32.dll", CharSet = CharSet::Auto, SetLastError = true)]
			private:
				__declspec(dllimport) static int GetWindowText(IntPtr hWnd, StringBuilder *lpString, int nMaxCount);

//C# TO C++ CONVERTER NOTE: The following .NET DllImport attribute was converted using the Microsoft-specific __declspec(dllimport):
//[DllImport("user32.dll", SetLastError = true, CharSet = CharSet::Auto)]
				__declspec(dllimport) static int GetWindowTextLength(IntPtr hWnd);

			public:
				static QString GetText(IntPtr hWnd);

//C# TO C++ CONVERTER NOTE: The following .NET DllImport attribute was converted using the Microsoft-specific __declspec(dllimport):
//[DllImport("kernel32.dll", CharSet = CharSet::Auto, SetLastError = true)]
				__declspec(dllimport) static EXECUTION_STATE SetThreadExecutionState(EXECUTION_STATE esFlags);

				static void PreventSystemPowerdown();

				static void AllowSystemPowerdown();

				static QString GetErrorText(int iErrorValue);
			};
		}
	}
}
