#include "Extensions.h"




//using namespace System::Collections::Generic;

//using namespace System::Reflection;
namespace MeXgui
{
	namespace packages
	{
		namespace tools
		{
			namespace hdbdextractor
			{

				const QString &StringValueAttribute::getValue() const
				{
					return privateValue;
				}

				void StringValueAttribute::setValue(const QString &value)
				{
					privateValue = value;
				}

				StringValueAttribute::StringValueAttribute(const QString &value)
				{
					setValue(value);
				}

QMap<Enum*, StringValueAttribute*> Extensions::stringValues = QMap<Enum*, StringValueAttribute*>();

				QString Extensions::GetStringValue(Enum *value)
				{
					QString output = "";
					Type *valueType = value->GetType();
					Type *stringValueAttributeType = StringValueAttribute::typeid;

					if (stringValues.find(value) != stringValues.end())
						output = stringValues[value]->getValue();
					else
					{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
						FieldInfo *fi = valueType->GetField(value->ToString());
//ORIGINAL LINE: StringValueAttribute[] attrs = dynamic_cast<array<StringValueAttribute^>^>(fi.GetCustomAttributes(stringValueAttributeType, false));
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
						StringValueAttribute *attrs = dynamic_cast<StringValueAttribute[]>(fi->GetCustomAttributes(stringValueAttributeType, false));

						if (sizeof(attrs) / sizeof(attrs[0]) > 0)
						{
							stringValues.insert(make_pair(value, attrs[0]));
							output = attrs[0]->getValue();
						}
					}

					return output;
				}

				QString Extensions::ToPascal(const QString &value)
				{
					QString s = value;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
					s = s.Trim()->ToLower(System::Globalization::CultureInfo::InvariantCulture);

					if (s.length() == 0)
						return value;

//ORIGINAL LINE: string[] ar = nullptr;
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
					QString *ar = 0;

					if (s.find('_') > -1)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
						ar = s.Split('_');
					else if (s.find(' ') > -1)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
						ar = s.Split(' ');

					s = "";

					if (ar != 0)
					{
						for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
							if (ar[i].Trim()->Length > 0)
								s += ar[i].substr(0, 1)->ToUpper(System::Globalization::CultureInfo::InvariantCulture) + ar[i].substr(1);

						return s;
					}
					return value;
				}

				QString Extensions::ToCamel(const QString &value)
				{
					QString s = value;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
					s = s.Trim()->ToLower(System::Globalization::CultureInfo::InvariantCulture);

					if (s.length() == 0)
						return value;

//ORIGINAL LINE: string[] ar = nullptr;
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
					QString *ar = 0;

					if (s.find('_') > -1)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
						ar = s.Split('_');
					else if (s.find(' ') > -1)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
						ar = s.Split(' ');

					if (ar != 0)
					{
						for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
						{
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
							if (ar[i].Trim()->Length > 0)
							{
								if (i == 0)
									s = ar[i];
								else
									s += ar[i].substr(0, 1)->ToUpper(System::Globalization::CultureInfo::InvariantCulture) + ar[i].substr(1);
							}
						}

						return s;
					}

					return value;
				}

				QString Extensions::Capitalize(const QString &value)
				{
					QString s = value;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
					s = s.Trim()->ToLower(System::Globalization::CultureInfo::InvariantCulture);

					if (s.length() == 0)
						return value;

//ORIGINAL LINE: string[] ar = s.Split('.');
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
					QString *ar = s.Split('.');
					s = "";

					if (ar != 0)
					{
						for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
							if (ar[i].Trim()->Length > 0)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
								s += ar[i].Trim()->substr(0, 1)->ToUpper(System::Globalization::CultureInfo::InvariantCulture) + ar[i].Trim()->substr(1) + ". ";

						return s;
					}

					return value;
				}

				QString Extensions::CapitalizeAll(const QString &value)
				{
					QString s = value;
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
					s = s.Trim()->ToLower(System::Globalization::CultureInfo::InvariantCulture);

					if (s.length() == 0)
						return value;

//ORIGINAL LINE: string[] ar = s.Split(' ');
//C# TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, C# to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Split' method:
					QString *ar = s.Split(' ');
					s = "";

					if (ar != 0)
					{
						for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
							if (ar[i].Trim()->Length > 0)
//C# TO C++ CONVERTER TODO TASK: There is no direct native C++ equivalent to the .NET String 'Trim' method:
								s += ar[i].Trim()->substr(0, 1)->ToUpper(System::Globalization::CultureInfo::InvariantCulture) + ar[i].Trim()->substr(1) + " ";

						return s;
					}

					return value;
				}
			}
		}
	}
}
