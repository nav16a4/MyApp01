#pragma once
#include <string>

namespace My
{
	namespace String
	{
		class MyString;
	}
}


class My::String::MyString
{
public:
	MyString();
	MyString(const std::string& cp949);
	MyString(const std::u8string& utf8);

	MyString(const MyString& str);
	MyString& operator=(const MyString& str);


	MyString(MyString&& str);
	MyString& operator=(MyString&& str);

	~MyString() = default;

public:
	static void ConvertEncoding(std::string& utf8, const std::string& cp949);

};

