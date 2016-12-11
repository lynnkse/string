#include <cstring>
#include "string.h"
#include <cstdlib>
#include <cctype>

namespace advcpp
{
namespace buf_advcpp
{

Buffer::Buffer(size_t _cap) 
	: m_cap(_cap)
{ 
	m_buf = new data_type[_cap]; m_cap = _cap;
}

Buffer::Buffer(const Buffer& _buf) 
	: m_cap(_buf.m_cap)
{ 
	m_buf = new data_type[_buf.m_cap]; 
	std::copy(_buf.m_buf, _buf.m_buf + _buf.m_cap, m_buf); 
}

Buffer::~Buffer() 
{ 
	delete[] m_buf; 
}
			
Buffer& Buffer::operator=(const Buffer& _buf) 
{
	if(&_buf != this)
	{
		if(m_cap < _buf.m_cap)
		{
			delete[] m_buf;
			m_buf = new data_type[_buf.m_cap];
			m_cap = _buf.m_cap;
		}
		
		std::copy(_buf.m_buf, _buf.m_buf + _buf.m_cap, m_buf); 
	} 
	
	return *this;
}


size_t Buffer::Cap() const
{
	return m_cap;
}

Buffer::data_type& Buffer::operator[](unsigned int _idx)
{
	return m_buf[_idx];
}

Buffer::data_type Buffer::operator[](unsigned int _idx) const
{
	return m_buf[_idx];
}

void Buffer::Resize(size_t _cap)
{
	if(m_cap < _cap)
	{
		data_type* temp = m_buf;
		m_buf = new data_type[_cap];
		std::copy(temp, temp + m_cap, m_buf);
		delete[] temp;
		m_cap = _cap;
	}
}

}

String::String()
	: m_buffer(1), m_len(1)
{
	m_buffer[0] = '\0';
}

String::String(const char_type* _str)
	: m_buffer(strlen(_str) + 1), m_len((strlen(_str)))
{
	std::copy(_str, _str + m_len + 1, &m_buffer[0]);
}

String& String::operator+=(const String& _str)
{
	String& mutString = const_cast<String&>(_str);

	m_buffer.Resize(m_len + _str.m_len + 1);
	std::copy(&(mutString.m_buffer[0]), &(mutString.m_buffer[mutString.m_len + 1]), &m_buffer[m_len]);
	m_len += _str.m_len;
}

const String::char_type* String::As_cstr() const
{
	String& mutString = const_cast<String&>(*this);
	return &mutString[0];
}

size_t String::Lenght()
{
	return m_len;
}

String String::Substring(unsigned int _idx)
{
	String s;
		
	if(_idx < m_len)
	{
		std::copy(&m_buffer[_idx], &m_buffer[m_len], &s[0]);
	} 
	
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
	return strstr(&m_buffer[0], &_str.m_buffer[0]) - &m_buffer[0];
}

String& String::ToLower()
{
	char_type* ptr = &m_buffer[0];
	while(*ptr != '\0')
	{
		tolower(*ptr++);
	}
	
	return *this;
}

String operator+(const String& _s1, const String& _s2)
{
	String s;
	s += _s1;
	s += _s2;
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































