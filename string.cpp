#include <cstring>
#include "string.h"
#include <cstdlib>
#include <cctype>

namespace advcpp
{

//static Buffer<char> defaultBuffer;

String::String()
	//: m_buffer(defaultBuffer)
	: m_buffer(1), m_len(1)
{
	m_buffer[0] = '\0';
}

String::String(const char_type* _str/* = ""*/)
	: m_buffer(strlen(_str) + 1), m_len((strlen(_str)))
{
	std::copy(_str, _str + m_len + 1, &m_buffer[0]);
}

String& String::operator+=(const String& _str)
{
	size_t req = m_len + _str.m_len + 1;
	m_buffer.Resize(req);
	//m_buffer.EnsureCapacity(req);

	const char_type* b =   _str.As_cstr();
	const char_type* e =   b + m_len +1;
	
	std::copy(b, e, const_cast<char_type*>(As_cstr()));
	m_len += _str.m_len;

	return *this;
}

const String::char_type* String::As_cstr() const
{
	return static_cast<const char_type*>(m_buffer.as_void_ptr());
}

size_t String::Lenght()
{
	return m_len;
}

String String::Substring(unsigned int _idx)
{
	//assert(_idx < m_len);

	String s(&m_buffer[_idx]);
			
	return s;
}

String::char_type& String::operator[](unsigned int _idx)
{
	return m_buffer[_idx];
}

String::char_type String::operator[](unsigned int _idx) const
{
	return m_buffer[_idx];
}

unsigned int String::Substring(const String& _str) const
{
	
	return std::strstr(As_cstr(), _str.As_cstr()) - As_cstr();
}

String& String::ToLower()
{
	const char_type* ptr = As_cstr();
	while(*ptr)
	{
		std::tolower(*ptr++);
	}
	
	return *this;
}

String operator+(const String& a, const String& b)
{
	String s(a);
	s += b;
	return s;
}

bool operator==(const String& _s1, const String& _s2)
{
	String& mutString1 = const_cast<String&>(_s1);
	String& mutString2 = const_cast<String&>(_s2);
	
	return strcmp(mutString1.As_cstr(), mutString2.As_cstr()) == 0;
}

bool operator!=(const String& _s1, const String& _s2)
{
	return !(_s1 == _s1);
}

bool operator>(const String& _s1, const String& _s2)
{
	String& mutString1 = const_cast<String&>(_s1);
	String& mutString2 = const_cast<String&>(_s2);
	
	return strcmp(&mutString1[0], &mutString2[0]) > 0;
}

bool operator<(const String& _s1, const String& _s2)
{
	String& mutString1 = const_cast<String&>(_s1);
	String& mutString2 = const_cast<String&>(_s2);
	
	return strcmp(&mutString1[0], &mutString2[0]) < 0;
}

std::ostream& operator<<(std::ostream& _os, const String& _str)
{
	String& mutString = const_cast<String&>(_str);
	_os << &mutString[0];
	return _os;
}  

}































