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
			
			Buffer(size_t _numOfItems = 1);
			Buffer(const Buffer& _buf);
			~Buffer();
			
			Buffer& operator=(const Buffer& _buf);
			size_t Length() const;
			
		private:
			data_type* m_buf;
			size_t m_numOfItems;
			size_t m_cap;
	};
}

class String
{
	public:
		String();
		String(const String& _str);
		String(const char* _str);
		~String();
		
		String& operator=(const String& _str);
		String& operator+=(const String& _str);
		
		String Substring(unsigned int _idx) const;
		unsigned int Substring(const String& _str) const;
		String& ToLower();
		const char* As_cstr() const;
		char& operator[](unsigned int _idx);
		char operator[](unsigned int _idx) const;
		size_t Lenght();
		
	private:
		char* m_str;//FIXME auto_ptr-like
};

String operator+(const String& _s1, const String& _s2);
bool operator==(const String& _s1, const String& _s2);
bool operator>(const String& _s1, const String& _s2);
bool operator<(const String& _s1, const String& _s2);
bool operator!=(const String& _s1, const String& _s2);
std::ostream& operator<<(std::ostream& _os, const String& _str);  

}

#endif






























