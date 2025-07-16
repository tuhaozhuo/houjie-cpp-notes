#ifndef STRING_H
#define STRING_H
#include<string.h>

class String
{
public:
    String(const char* cstr = 0);  // 构造函数ctor
    String(const String& str);  // 拷贝构造函数
    String& operator = (const String& str);  // 拷贝赋值函数
    ~String();  // 析构函数 dtor
    char* get_c_str() const { return m_data;}
private:
    char* m_data;
};

// 构造函数 ctor
inline
String::String(const char* cstr = 0)
{
	if(cstr) {
		m_data = new char[strlen(cstr)+1];
		strcpy(m_data, cstr);
	}
	else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

// 析构函数 dtor
inline
String::~String()
{
	delete[] m_data;
}

// 拷贝构造函数
inline
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data)+1];
	strcpy(m_data, str.m_data);
}

// 拷贝赋值函数
inline
String& String::operator=(const String& str)
{
	if(this == &str) return *this;  // 自我检查
	
	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1];
	strcpy(m_data, str.m_data);
	return *this;
}

#endif