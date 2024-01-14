#include <Windows.h>
#include "MyEncoding.h"


My::String::MyEncoding::MyEncoding()
{
	const int code = CP_UTF8;
	this->SetEncode(code);

};

void My::String::MyEncoding::SetEncode(int codePage)
{
	if (this->m_CodePage != codePage)
	{
		this->m_CodePage = codePage;
	}
	SetConsoleOutputCP(this->m_CodePage);
	return;
}

const int My::String::MyEncoding::GetEncode(void) const
{
	return this->m_CodePage;
}

