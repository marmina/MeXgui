#pragma once

#include "packages/audio/AudioCodecSettings.h"
#include "core/details/CodecManager.h"
#include "core/details/video/VideoCodecSettings.h"
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




namespace MeXgui
{
	enum OpusMode
	{
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[EnumTitle("VBR")]
		VBR,
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[EnumTitle("Constrained VBR")]
		CVBR,
//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in native C++:
//[EnumTitle("Hard CBR")]
		HCBR
	};

	class OpusSettings : public AudioCodecSettings
	{
	public:
		static const QString ID;

		static const OpusMode SupportedModes[3];

		OpusSettings();

	private:
		OpusMode mode;
	public:
		const OpusMode &getMode() const;
		void setMode(const OpusMode &value);
	};
}
