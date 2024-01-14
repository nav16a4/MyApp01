#pragma once
#include <iostream>
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
private:
	std::string m_String;
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
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	
public:
	static void ConvertEncoding(std::string& utf8, const std::string& cp949);

	static void Test(void);
};

