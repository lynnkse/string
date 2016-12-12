#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <iostream>

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

class String
{
	typedef char char_type;

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
		buf_advcpp::Buffer<char> m_buffer;
		size_t m_len;
};

String operator+(const String& _s1, const String& _s2);
bool operator==(const String& _s1, const String& _s2);
bool operator>(const String& _s1, const String& _s2);
bool operator<(const String& _s1, const String& _s2);
bool operator!=(const String& _s1, const String& _s2);
std::ostream& operator<<(std::ostream& _os, const String& _str);  

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

#endif






























