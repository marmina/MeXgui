﻿#include "ChapterExtractor.h"

//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Collections::Generic;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Linq;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Text;
//C# TO C++ CONVERTER TODO TASK: The .NET System namespace is not available from native C++:
//using namespace System::Security::Cryptography;

namespace MeGUI
{

	const bool &ChapterExtractor::getSupportsMultipleStreams() const
	{
		return true;
	}

	std::string ChapterExtractor::ComputeMD5Sum(const std::string &path)
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Replace' method:
		return BitConverter->ToString((new MD5CryptoServiceProvider())->ComputeHash(System::IO::File::ReadAllBytes(path)))->Replace("-", "")->ToLower(System::Globalization::CultureInfo::InvariantCulture);
	}

	void ChapterExtractor::OnExtractionComplete()
	{
		ExtractionComplete(this, EventArgs::Empty);
	}

	void ChapterExtractor::OnStreamDetected(ChapterInfo *pgc)
	{
		StreamDetected(this, new ProgramChainArg(new object[] {ProgramChain = pgc}));
	}

	void ChapterExtractor::OnChaptersLoaded(ChapterInfo *pgc)
	{
		ChaptersLoaded(this, new ProgramChainArg(new object[] {ProgramChain = pgc}));
	}

	const ChapterInfo &ProgramChainArg::getProgramChain() const
	{
		return privateProgramChain;
	}

	void ProgramChainArg::setProgramChain(const ChapterInfo &value)
	{
		privateProgramChain = value;
	}
}
