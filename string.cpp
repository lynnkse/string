#include <cstring>
#include "string.h"
#include <cstdlib>
#include <cctype>


class A;
class B{
 A& a;
public:
	B(A& r) : a(r) {}
};


namespace advcpp
{

static Buffer<char> defaultBuffer;

String::String()
	: m_buffer(defaultBuffer)
	: m_buffer(1), m_len(1)
{
	m_buffer[0] = '\0';
}

size_t strlen(const char* p){
	const char* q = p;>
	while(*p++)
		;

	return p-q;
}

String::String(const char_type* _str = "")

: m_buffer(strlen(_str) + 1), m_len((strlen(_str)))
{
	std::copy(_str, _str + m_len + 1, &m_buffer[0]);
}










String& String::operator+=(const String& _str)
{
	size_t req = m_len + _str.m_len + 1;
	m_buffer.EnsureCapacity(req);

	char_type* b =   _str.as_cstr();
	char_type* e =   b + m_len +1;
	
	std::copy(b, e, , (char*)as_cstr());
	m_len += _str.m_len;

	return *this;
}

const String::char_type* String::As_cstr() const
{
	return m_buffer.as_voidptr();
}

size_t String::Lenght()
{
	return m_len;
}

String String::Substring(unsigned int _idx)
{
	assert(_idx < m_len);

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

unsigned int String::Substring(String& _str) 
{
	return std::strstr(&m_buffer[0], &_str.m_buffer[0]) - &m_buffer[0];
}
>
String& String::ToLower()
{
	char_type* ptr = &m_buffer[0];
	while(*ptr != '\0')
	{
		std::tolower(*ptr++);
	}
	
	return *this;
}

String operator+(const String& a, const String& b)
String operator+(String a, const String& b)
{
	a += b;
	return a;
///////////////////>

	return (String) a += b;

///////////////////////////////
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































