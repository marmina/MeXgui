#pragma once

#include "Stream.h"
#include "StreamType.h"
#include <QString>

// ****************************************************************************
// 
// Copyright (C) 2005-2008  Doom9 & al
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




namespace eac3to
{
	/// <summary>A Stream of StreamType Subtitle</summary>
	class SubtitleStream : public Stream
	{
	private:
		QString privateLanguage;
	public:
		const virtual QString &getLanguage() const;
		virtual void setLanguage(const QString &value);
	private:
		bool privateIsSDH;
	public:
		const bool &getIsSDH() const;
		void setIsSDH(const bool &value);

		const virtual object *getExtractTypes() const;

		SubtitleStream(const QString &s);

		static Stream *Parse(const QString &s);

		virtual QString ToString();
	};
}
