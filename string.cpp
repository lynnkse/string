#include <cstring>
#include "string.h"
namespace advcpp
{
namespace buf_advcpp
{

Buffer::Buffer(size_t _numOfItems = 1) 
	: m_numOfItems(_numOfItems), m_cap(_numOfItems)
{ 
	m_buf = new char[_numOfItems]; m_numOfItems = _numOfItems; m_cap = _numOfItems;
}

Buffer::Buffer(const Buffer& _buf) 
	: m_numOfItems(_buf.m_numOfItems), m_cap(_buf.m_numOfItems)
{ 
	m_buf = new char[_buf.m_numOfItems]; 
	std::memcpy(m_buf, _buf.m_buf, sizeof(*m_buf) * m_numOfItems); 
}

Buffer::~Buffer() 
{ 
	delete[] m_buf; 
}
			
Buffer& Buffer::operator=(const Buffer& _buf) 
{
	if(_buf != this)
	{
		if(_cap < _buf.m_numOfItems)
		{
			delete[] m_buf;
			m_buf = new char[_buf.m_numOfItems];
			m_buf = _buf.m_numOfItems;
			m_cap = _buf.m_numOfItems;
		}
		
		memcpy(m_buf, _buf.m_buf, _buf.m_numOfItems);
	} 
	
	return *this;
}

Buffer& Buffer::operator+=(const Buffer& _buf)
{
	if(_cap < m_numOfItems + _buf.m_numOfItems)
	{
			char* temp = m_buf;
			m_buf = new char[_cap < m_numOfItems + _buf.m_numOfItems];
			memcpy(m_buf, temp, sizeof(*m_buf) * m_numOfItems);
			delete[] temp;
	}
	
	memcpy(m_buf + m_numOfItems, _buf.m_buf, sizeof(*m_buf) * _buf.m_numOfItems);
	m_numOfItems += _buf.m_numOfItems; 
}

Buffer Buffer::SubBuffer(unsigned int _idx) const
{
	Buffer b;
	b.m_cap = m_numOfItems - _idx;
	b.m_numOfItems = m_numOfItems - _idx;
	std::memcpy(b.m_buf, m_buf + _idx, sizeof(*m_buf) * b.m_numOfItems);
	return b;
}

const char* Buffer::GetBuff() const
{
	return m_buf;
}

size_t Buffer::Length() const
{
	return m_numOfItems;
}

char& Buffer::operator[](unsigned int _idx)
{
	return m_buf[_idx];
}

char Buffer::operator[](unsigned int _idx) const
{
	return m_buf[_idx];
}

unsigned int Buffer::SubBuffer(const Buffer& _buf) const
{
	char* cp = strstr(m_buf, _buf.m_buf);
	return cp - m_buf;
}

}
}







































