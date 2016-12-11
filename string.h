#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <iostream>

namespace advcpp
{

namespace buf_advcpp
{
	class Buffer
	{
		public:
			typedef char data_type;
		
		public:			
			Buffer(size_t _cap);
			Buffer(const Buffer& _buf);
			~Buffer();
			
			Buffer& operator=(const Buffer& _buf);
			size_t Cap() const;
			
			data_type& operator[](unsigned int _idx);
			data_type operator[](unsigned int _idx) const;
			
			void Resize(size_t _cap);
			
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
		unsigned int Substring(String& _str);
		String& ToLower();
		const char_type* As_cstr() const;
		char_type& operator[](unsigned int _idx);
		char_type operator[](unsigned int _idx) const;
		size_t Lenght();
		
	private:
		buf_advcpp::Buffer m_buffer;
		size_t m_len;
};

String operator+(const String& _s1, const String& _s2);
bool operator==(const String& _s1, const String& _s2);
bool operator>(const String& _s1, const String& _s2);
bool operator<(const String& _s1, const String& _s2);
bool operator!=(const String& _s1, const String& _s2);
std::ostream& operator<<(std::ostream& _os, const String& _str);  

}

#endif






























