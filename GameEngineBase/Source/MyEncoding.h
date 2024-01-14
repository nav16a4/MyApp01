#pragma once
#include "Singleton.h"

namespace My
{
	namespace String
	{
		class MyEncoding;
	}
}

/**
* @class My::String::MyEncoding
* @brief 출력할 인코딩 설정
* @date 2024-01-14
*/
class My::String::MyEncoding : public Singleton<My::String::MyEncoding>
{
private:
	int m_CodePage = 0;
public:
	MyEncoding();
	~MyEncoding() = default;

	MyEncoding(const MyEncoding&) = delete;
	MyEncoding& operator=(const MyEncoding&) = delete;	
	MyEncoding(MyEncoding&&) = delete;
	MyEncoding& operator=(MyEncoding&&) = delete;
private:
	void SetEncode(int codePage);
public:
	const int GetEncode(void) const;
};


