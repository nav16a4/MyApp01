#include "MyString.h"
#include "MyEncoding.h"
#include <boost/locale.hpp>

My::String::MyString::MyString()
{
	//static MyEncoding* encoding = MyEncoding::GetInstancePtr();
}

My::String::MyString::MyString(const std::string& cp949)
{
	std::string& utf8 = this->m_String;
	MyString::ConvertEncoding(utf8, cp949);
}

My::String::MyString::MyString(const std::u8string& utf8)
{
	this->m_String = reinterpret_cast<const std::string&>(utf8);
}

My::String::MyString::MyString(const MyString& str)
{
	this->m_String = str.m_String;
}

My::String::MyString::MyString(MyString&& str)
{
	this->m_String = std::move(str.m_String);
}

//자동 생성 시키면 형식에서 에러. 자동으로 만들 때 확인해보자
My::String::MyString& My::String::MyString::operator=(const MyString& str)
{
	this->m_String = str.m_String;
	return *this;
}

//자동 생성 시키면 형식에서 에러. 자동으로 만들 때 확인해보자
My::String::MyString& My::String::MyString::operator=(MyString&& str)
{
	this->m_String = std::move(str.m_String);
	return *this;

}

void My::String::MyString::ConvertEncoding(std::string& utf8, const std::string& cp949)
{
	const std::string& before = cp949;
	std::string& after = utf8;

	after = boost::locale::conv::to_utf<char>(before, "EUC-KR");
}




void My::String::MyString::Test(void)
{
	MyString testStr("test 테스트");

	std::string cp949 = "안녕하세요";
	std::string utf8 = "";

	MyString::ConvertEncoding(utf8, cp949);

	std::cout << "cp949 : " << cp949 << std::endl;
	std::cout << "utf8 : " << utf8 << std::endl;

	




}


std::ostream& My::String::operator<<(std::ostream& os, const MyString& str)
{
	os << str.m_String;
	return os;
}
