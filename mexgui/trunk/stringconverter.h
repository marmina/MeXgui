#pragma once

//----------------------------------------------------------------------------------------
//	Copyright � 2004 - 2012 Tangible Software Solutions Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class is used to replace some conversions to or from strings.
//----------------------------------------------------------------------------------------
#include <sstream>

class StringConverterHelper
{
public:
	template<typename T>
	static std::string toString(const T &subject)
	{
		std::stringstream ss;
		ss << subject;
		return ss.str();
	}

	template<typename T>
	static T fromString(const std::string &subject)
	{
		std::stringstream ss(subject);
		T target;
		ss >> target;
		return target;
	}
};
