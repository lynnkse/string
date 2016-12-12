#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "string.h"
#include <cstdlib>
#include <cctype>

namespace advcpp
{

namespace buf_advcpp
{
	template<class T>	
	class Buffer
	{
		public:
			typedef T data_type;
		
		public:			
			Buffer(size_t _cap);
			Buffer(const Buffer& _buf);
			~Buffer();
			
			Buffer& operator=(const Buffer& _buf);
			size_t Cap() const;
			
			data_type& operator[](unsigned int _idx);
			data_type operator[](unsigned int _idx) const;
			
			void Resize(size_t _cap);
			const void* as_void_ptr() const;
			
		private:
			data_type* m_buf;
			size_t m_cap;
	};
}

template <class StringChar>
class String
{
	typedef StringChar char_type;

	public:
		String();
		String(const char_type* _str);
		
		String& operator+=(const String& _str);
		
		String Substring(unsigned int _idx);
		unsigned int Substring(const String& _str) const;
		String& ToLower();
		const char_type* As_cstr() const;
		char_type& operator[](unsigned int _idx);
		char_type operator[](unsigned int _idx) const;
		size_t Lenght();
		
	private:
		buf_advcpp::Buffer<char_type> m_buffer;
		size_t m_len;
};

template <class StringChar>
String<StringChar> operator+(const String<StringChar>& _s1, const String<StringChar>& _s2);
template <class StringChar>
bool operator==(const String<StringChar>& _s1, const String<StringChar>& _s2);
template <class StringChar>
bool operator>(const String<StringChar>& _s1, const String<StringChar>& _s2);
template <class StringChar>
bool operator<(const String<StringChar>& _s1, const String<StringChar>& _s2);
template <class StringChar>
bool operator!=(const String<StringChar>& _s1, const String<StringChar>& _s2);
template <class StringChar>
std::ostream& operator<<(std::ostream& _os, const String<StringChar>& _str);  

}

namespace advcpp
{
namespace buf_advcpp
{
template<class T>
Buffer<T>::Buffer(size_t _cap) 
	: m_cap(_cap)
{ 
	m_buf = new data_type[_cap]; m_cap = _cap;
}

template<class T>
Buffer<T>::Buffer(const Buffer& _buf) 
	: m_cap(_buf.m_cap)
{ 
	m_buf = new data_type[_buf.m_cap]; 
	std::copy(_buf.m_buf, _buf.m_buf + _buf.m_cap, m_buf); 
}

template<class T>
Buffer<T>::~Buffer() 
{ 
	delete[] m_buf; 
}

template<class T>		
Buffer<T>& Buffer<T>::operator=(const Buffer<T>& _buf) 
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

template<class T>
size_t Buffer<T>::Cap() const
{
	return m_cap;
}

template<class T>
typename Buffer<T>::data_type& Buffer<T>::operator[](unsigned int _idx)
{
	return m_buf[_idx];
}

template<class T>
typename Buffer<T>::data_type Buffer<T>::operator[](unsigned int _idx) const
{
	return m_buf[_idx];
}

template<class T>
void Buffer<T>::Resize(size_t _cap)
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

template<class T>
const void* Buffer<T>::as_void_ptr() const
{
	return m_buf;
}

}
}

namespace advcpp
{

//static Buffer<char> defaultBuffer;
template <class StringChar>
String<StringChar>::String()
	//: m_buffer(defaultBuffer)
	: m_buffer(1), m_len(1)
{
	m_buffer[0] = '\0';
}

template <class StringChar>
String<StringChar>::String(const char_type* _str/* = ""*/)
	: m_buffer(strlen(_str) + 1), m_len((strlen(_str)))
{
	std::copy(_str, _str + m_len + 1, &m_buffer[0]);
}

template <class StringChar>
String<StringChar>& String<StringChar>::operator+=(const String& _str)
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

template <class StringChar>
const typename String<StringChar>::char_type* String<StringChar>::As_cstr() const
{
	return static_cast<const char_type*>(m_buffer.as_void_ptr());
}

template <class StringChar>
size_t String<StringChar>::Lenght()
{
	return m_len;
}

template <class StringChar>
String<StringChar> String<StringChar>::Substring(unsigned int _idx)
{
	//assert(_idx < m_len);

	String s(&m_buffer[_idx]);
			
	return s;
}

template <class StringChar>
typename String<StringChar>::char_type& String<StringChar>::operator[](unsigned int _idx)
{
	return m_buffer[_idx];
}

template <class StringChar>
typename String<StringChar>::char_type String<StringChar>::operator[](unsigned int _idx) const
{
	return m_buffer[_idx];
}

template <class StringChar>
unsigned int String<StringChar>::Substring(const String& _str) const
{
	
	return std::strstr(As_cstr(), _str.As_cstr()) - As_cstr();
}

template <class StringChar>
String<StringChar>& String<StringChar>::ToLower()
{
	const char_type* ptr = As_cstr();
	while(*ptr)
	{
		std::tolower(*ptr++);
	}
	
	return *this;
}

template <class StringChar>
String<StringChar> operator+(const String<StringChar>& a, const String<StringChar>& b)
{
	String<StringChar> s(a);
	s += b;
	return s;
}

template <class StringChar>
bool operator==(const String<StringChar>& _s1, const String<StringChar>& _s2)
{
	String<StringChar>& mutString1 = const_cast<String<StringChar>&>(_s1);
	String<StringChar>& mutString2 = const_cast<String<StringChar>&>(_s2);
	
	return strcmp(mutString1.As_cstr(), mutString2.As_cstr()) == 0;
}

template <class StringChar>
bool operator!=(const String<StringChar>& _s1, const String<StringChar>& _s2)
{
	return !(_s1 == _s1);
}

template <class StringChar>
bool operator>(const String<StringChar>& _s1, const String<StringChar>& _s2)
{
	String<StringChar>& mutString1 = const_cast<String<StringChar>&>(_s1);
	String<StringChar>& mutString2 = const_cast<String<StringChar>&>(_s2);
	
	return strcmp(&mutString1[0], &mutString2[0]) > 0;
}

template <class StringChar>
bool operator<(const String<StringChar>& _s1, const String<StringChar>& _s2)
{
	String<StringChar>& mutString1 = const_cast<String<StringChar>&>(_s1);
	String<StringChar>& mutString2 = const_cast<String<StringChar>&>(_s2);
	
	return strcmp(&mutString1[0], &mutString2[0]) < 0;
}

template <class StringChar>
std::ostream& operator<<(std::ostream& _os, const String<StringChar>& _str)
{
	String<StringChar>& mutString = const_cast<String<StringChar>&>(_str);
	_os << &mutString[0];
	return _os;
}  

}


#endif






























