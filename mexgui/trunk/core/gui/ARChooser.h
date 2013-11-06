#pragma once

#include "MeGUI.core.gui.StandardAndCustomComboBox.h"
#include "MeGUI.MainForm.h"
#include "StandardAndCustomComboBox.h"
#include "core/util/DAR.h"
#include "MeGUI.core.gui.AspectRatioChooser.h"
#include "core/util/Util.h"
#include <string>
#include <vector>
#include <stdexcept>

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
//using namespace System::ComponentModel;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Text;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Windows::Forms;

using namespace MeGUI::core::util;

namespace MeGUI
{
	namespace core
	{
		namespace gui
		{
			class ARChooser : public StandardAndCustomComboBox
			{

				public:
				~ARChooser()
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
				void Dispose(bool disposing);

				static const std::string Later;

			public:
				static const Named<Dar> ARs[7];

				ARChooser();

			private:
				bool hasLater;
			public:
				const bool &getHasLater() const;
				void setHasLater(const bool &value);

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
				const Nullable<Dar> &getValue() const;
				void setValue(const Nullable<Dar> &value);

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility::Hidden)]
				const Dar &getRealValue() const;
				void setRealValue(const Dar &value);

				const Dar *getCustomDARs() const;
				void setCustomDARs(Dar value[]);
			};

		}
	}
}
