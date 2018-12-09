//Author: Ngo Tan Vinh
//email:kieuphong2840@gmail.com
//Cai dat Lop String
//Su dung cac cau lenh don gian

#include"MyString.h"

#include<new>



MyString::MyString()
{
	_size = 0;
	_capacity = 15;
	this->_myString = new char[_capacity];
}
MyString::MyString(const char* str)
{
	int sizeOfStr = 0;
	while (str[sizeOfStr] != '\0')
	{
		sizeOfStr++;
	}
	this->_size = sizeOfStr;
	this->_capacity = ((this->_size / 16) + 1) * 16 - 1;
	this->_myString = new char[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = str[i];
	}
}
MyString::MyString(const MyString &str)
{
	this->_size = str._size;
	this->_capacity = ((this->_size / 16) + 1) * 16 - 1;
	this->_myString = new char[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = str._myString[i];

	}
}
MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	this->_size = len;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = str._myString[i + pos];
	}
}
MyString::MyString(const char* str, size_t n)
{
	this->_size = n;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = str[i];
	}
}
MyString::MyString(size_t n, char c)
{
	this->_size = n;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_size];
	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = c;
	}
}
MyString::~MyString()
{ 
	delete _myString;
}
//////////////////////////////operator
MyString& MyString::operator= (const char *str)
{ 
	int sizeOfStr = 0;
	while (str[sizeOfStr]!='\0')
	{
		sizeOfStr++;
	}
	
	this->_size = sizeOfStr;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_capacity];
	for (int i = 0; i < sizeOfStr; i++)
	{
		this->_myString[i] = str[i];
	}
	return *this;
}
MyString& MyString::operator= (const MyString &str)
{
	int sizeOfStr = str._size;
	this->_size = sizeOfStr;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_capacity];
	for (int i = 0; i < sizeOfStr; i++)
	{
		this->_myString[i] = str._myString[i];
	}
	return *this;
}
MyString& MyString::operator= (const char str)
{
	
	this->_size = 1;
	this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	this->_myString = new char[this->_capacity];
	
	this->_myString[0] = str;
	return *this;
}


MyString MyString::operator + (const MyString& rhs)
{
	if (this->_size + rhs._size <= this->_capacity)
	{
		for (int i = 0; i < rhs._size; i++)
		{
			this->_myString[i + this->_size] = rhs._myString[i];
		}
		this->_size += rhs._size;
	}
	else
	{
		MyString p(*this);
		delete this->_myString;
		this->_size += rhs._size;
		this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		this->_myString = new char[this->_size];
		for (int i = 0; i < p._size; i++)
		{
			this->_myString[i] = p._myString[i];
		}
		for (int i = 0; i < rhs._size; i++)
		{
			this->_myString[i + p._size] = rhs._myString[i];
		}
		
	}
	return *this;
}
MyString MyString::operator+ (const char*   rhs)
{
	MyString p(rhs);
	return *this + p;
}
MyString MyString::operator+ (char      rhs)
{
	MyString p(1,rhs);
	return *this + p;
}
MyString operator+ (const char*   lhs, const MyString& rhs)
{
	MyString p(lhs);
	return p + rhs;
}
MyString operator+ (char          lhs, const MyString& rhs)
{
	MyString p(1,lhs);
	return p + rhs;
}

MyString& MyString::operator+= (const MyString& str)
{
	return *this + str;

}
MyString& MyString::operator+= (const char* s)
{
	MyString str(s);
	return *this + str;

}
MyString& MyString::operator+= (char c)
{
	MyString str(1,c);
	return *this + str;

}


ostream& operator<<(ostream& out, MyString p)
{
	for (int i = 0; i < p._size; i++)
	{
		out << p._myString[i];
	}
	return out;
}
 istream& operator>>(istream& in, MyString p)
{
	for (int i = 0; i < p._size; i++)
	{
		in>> p._myString[i];
	}
	return in;
}
 bool MyString::operator==(const MyString& b)
 {
	 if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] != b._myString[i])
			 {
				 return 0;
			 }
		 }
	 }
	 else
	 {
		 return 0;
	 }
	 return 1;
 }
 bool MyString::operator== (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this == rhs;
 }
 bool operator== (const char*   lhs, const MyString& rhs)
 {
	 MyString str(lhs);
	
	 return lhs == rhs;
 }
 bool MyString::operator!= (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this != rhs;
 }

 bool MyString::operator!=(const MyString& b)
 {
	 if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] == b._myString[i])
			 {
				 return 0;
			 }
		 }
	 }
	
	return 1;
	 
	
 }
 bool MyString::operator>=(const MyString& b)
 {
	 if (this->_size < b._size)
	 {
		 return 0;
	 }
	 else if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] < b._myString[i])
			 {
				 return 0;
			 }
		 }
	 }
	 return 1;
 }
 bool MyString::operator>= (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this >= rhs;

 }
 bool MyString::operator<=(const MyString& b)
 {
	 if (this->_size > b._size)
	 {
		 return 0;
	 }
	 else if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] > b._myString[i])
			 {
				 return 0;
			 }
		 }
	 }
	 return 1;
 }
 bool MyString::operator<= (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this <= rhs;
 }
 bool MyString::operator>(const MyString& b)
 {
	 if (this->_size < b._size)
	 {
		 return 0;
	 }
	 else if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] < b._myString[i])
			 {
				 return 0;
			 }
		 }
		 return 0;
	 }
	 return 1;
 }
 bool MyString::operator>  (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this > rhs;
 }
 bool MyString::operator<(const MyString&b)
 {
	 if (this->_size > b._size)
	 {
		 return 0;
	 }
	 else if (this->_size == b._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] > b._myString[i])
			 {
				 return 0;
			 }
		 }
		 return 0;
	 }
	 return 1;
 }
 bool MyString::operator<  (const char*   rhs)
 {
	 MyString str(rhs);
	 return *this < rhs;
 }

 bool operator!= (const char*   lhs, const MyString& rhs)
 {
	 MyString srt(lhs);
	 return lhs != rhs;
 }
 bool operator<  (const char*   lhs, const MyString& rhs)
 {
	 MyString srt(lhs);
	 return lhs < rhs;
 }
 bool operator<= (const char*   lhs, const MyString& rhs)
 {
	 MyString srt(lhs);
	 return lhs <= rhs;
 }
 bool operator>  (const char*   lhs, const MyString& rhs)
 {
	 MyString srt(lhs);
	 return lhs > rhs;
 }
 bool operator>= (const char*   lhs, const string& rhs)
 {
	 MyString srt(lhs);
	 return lhs >= rhs;
 }


 char MyString::operator[](int b)
 {
	 return this->_myString[b];
 }

 char& MyString::at(int b)
 {
	 return this->_myString[b];
 }
 char& MyString::back()
 {
	 return this->_myString[this->_size - 1];
 }
 char& MyString::front()
 {
	 return this->_myString[0];
 }
 ///////////////////////////capacity

 int MyString::size()
 {
	 return this->_size;
 }

 int MyString::length()
 {
	 return this->_size;
 }

 int MyString::capacity()
 {
	 return _capacity;
 }
 
 size_t MyString::max_size()
 {
	 return npos;
 }
 
 void MyString::resize(int new_size, char add_str)
 {
	 
	 if (_capacity - new_size >= 0)
	 {
		 
		 for (int i = this->_size; i < new_size; i++)
		 {
			 this->_myString[i] = add_str;
		 }
		 this->_size = new_size;
	 }
	 else
	 {
		 char *p;
		 this->_capacity = (new_size / 16 + 1) * 16 - 1;
		 p = new char[this->_size];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 delete this->_myString;
		 this->_myString=new char[ this->_capacity];

		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 
		 for (int i = this->_size; i < new_size; i++)
		 {
			 this->_myString[i] = add_str;
		 }
		 
		 this->_size = new_size;
		 delete p;
	 }

 }

 void MyString::clear()
 {
	 this->_size = 0;
 }
 
 bool MyString::empty()
 {
	 if (this->_size != 0)
	 {
		 return 0;
	 }
	 return 1;
 }
 
 void MyString::shrink_to_fit()
 {
	 char *p;
	 p = new char[this->_size];
	 for (int i = 0; i < this->_size; i++)
	 {
		 p[i] = this->_myString[i];
	 }
	 delete this->_myString;
	 this->_myString = new char[this->_size];
	
	 for (int i = 0; i < this->_size; i++)
	 {
		 this->_myString[i]=p[i];
	 }
	 this->_capacity = this->_size;
	 delete p;
	 
 }


 

 /////////////////////Modifiers

 MyString& MyString::append(const MyString& str)
 {
	 if (this->_size + str._size <= this->_capacity)
	 {
		 for (int i = 0; i < str._size; i++)
		 {
			 this->_myString[i + this->_size] = str._myString[i];
		 }
		 this->_size += str._size;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + str._size];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = 0; i < str._size; i++)
		 {
			 p[i + this->_size] = str._myString[i];
		 }
		 delete this->_myString;
		 this->_size += str._size;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
 MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen)
 {

	 if (this->_size + sublen <= this->_capacity)
	 {
		 for (int i = 0; i < sublen; i++)
		 {
			 this->_myString[i + this->_size] = str._myString[subpos+i];
		 }
		 this->_size += sublen;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + sublen];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = 0; i < sublen; i++)
		 {
			 p[i + this->_size] = str._myString[subpos + i];
		 }
		 delete this->_myString;
		 this->_size =this->_size +sublen;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
 MyString& MyString::append(const char* str)
 {
	 int sizeOfStr = 0;
	 while (str[sizeOfStr] != '\0')
	 {
		 sizeOfStr++;
	 }
	 if (this->_size + sizeOfStr <= this->_capacity)
	 {
		 for (int i = 0; i < sizeOfStr; i++)
		 {
			 this->_myString[i + this->_size] = str[i];
		 }
		 this->_size += sizeOfStr;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + sizeOfStr];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = 0; i < sizeOfStr; i++)
		 {
			 p[i + this->_size] = str[i];
		 }
		 delete this->_myString;
		 this->_size+=sizeOfStr;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
 MyString& MyString::append(const char* str, size_t n)
 {
	 if (this->_size + n <= this->_capacity)
	 {
		 for (int i = 0; i < n; i++)
		 {
			 this->_myString[i + this->_size] = str[i];
		 }
		 this->_size += n;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + n];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = 0; i < n; i++)
		 {
			 p[i + this->_size] = str[ i];
		 }
		 delete this->_myString;
		 this->_size += n;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
MyString& MyString::append(size_t n, char c)
 {
	 if (this->_size + n <= this->_capacity)
	 {
		 for (int i = 0; i < n; i++)
		 {
			 this->_myString[i + this->_size] = c;
		 }
		 this->_size += n;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + n];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = 0; i < n; i++)
		 {
			 p[i + this->_size] = c;
		 }
		 delete this->_myString;
		 this->_size += n;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
typedef char * iterator;
MyString& MyString::append(iterator first, iterator last)
{
	for (auto i = first; i != last; i++)
	{
		this->push_back(*i);
	}
	return *this;
}



 void MyString::push_back(char c)
 {
	 if (this->_size + 1 <= this->_capacity)
	 {
		 this->_myString[this->_size] = c;
		 this->_size++;
	 }
	 else
	 {
		 char *p;
		 p = new char[this->_size + 1];
		 for (int i = 0; i < this->_size; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 p[this->_size] = c;
		 delete this->_myString;
		 this->_size++;
		 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
		 this->_myString = new char[_capacity];
		 for (int i = 0; i < this->_size ; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 
		 delete p;
	 }
	 
 }

 
 ///////////////////interators


MyString& MyString::assign(const MyString& str)
 {
	 *this = str;
	 return *this;
 }
MyString& MyString::assign(const MyString& str, size_t subpos, size_t sublen)
 {
	 this->_size = sublen;
	 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	 this->_myString = new char[this->_capacity];
	 for (int i = 0; i < this->_size; i++)
	 {
		 this->_myString[i] = str._myString[i + subpos];
	 }
	 return *this;
 }
MyString& MyString::assign(const char* s)
 {
	 *this = s;
	 return *this;
 }
MyString& MyString::assign(const char* s, size_t n)
 {
	 this->_size = n;
	 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	 this->_myString = new char[this->_capacity];
	 for (int i = 0; i < this->_size; i++)
	 {
		 this->_myString[i] = s[i];
	 }
	 return *this;
 }
MyString& MyString::assign(size_t n, char c)
 {
	 this->_size = n;
	 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
	 this->_myString = new char[this->_capacity];
	 for (int i = 0; i < this->_size; i++)
	 {
		 this->_myString[i] = c;
	 }
	 return *this;
 }

typedef char * iterator;
MyString& MyString::assign(iterator first, iterator last)
{
	MyString p;
	for (auto i = first; i != last; i++)
	{
		p.push_back(*i);
	}
	*this = p;
	return *this;
}

 MyString& MyString::insert(size_t pos, const MyString& str)
 {
	 if (this->_size + str._size <= this->_capacity)
	 {
	
		 for (int i = this->_size+ str._size - 1; i >= pos + str._size; i--)
		 {
			 this->_myString[i] = this->_myString[i - str._size];
		 }
		 for (int i =0 ; i < str._size; i++)
		 {
			 this->_myString[i+pos] = str._myString[i];
		 }
		 this->_size += str._size;

	 }
	 else
	 {
		
		 this->_capacity = ((this->_size + str._size )/ 16 + 1) * 16 - 1;
		 char *p;
		 p = new char[this->_capacity];
		 for (int i = 0; i<pos; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = pos; i<pos+str._size; i++)
		 {
			 p[i] = str._myString[i-pos];
		 }
		 for (int i = pos + str._size; i<this->_size + str._size; i++)
		 {
			 p[i] = this->_myString[i - str._size];
		 }

		 this->_size += str._size;
		 delete this->_myString;
		 this->_myString = new char[this->_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;

	 }
	 return *this;
 }
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
 {
	 if (this->_size + sublen <= this->_capacity)
	 {

		 for (int i = this->_size + sublen - 1; i >= pos + sublen; i--)
		 {
			 this->_myString[i] = this->_myString[i - sublen];
		 }
		 for (int i = 0; i < sublen; i++)
		 {
			 this->_myString[i + pos] = str._myString[i+subpos];
		 }
		 this->_size += sublen;

	 }
	 else
	 {

		 this->_capacity = ((this->_size + sublen) / 16 + 1) * 16 - 1;
		 char *p;
		 p = new char[this->_capacity];
		 for (int i = 0; i<pos; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = pos; i<pos + sublen; i++)
		 {
			 p[i] = str._myString[i - pos];
		 }
		 for (int i = pos + sublen; i<this->_size + sublen; i++)
		 {
			 p[i] = this->_myString[i - sublen];
		 }

		 this->_size += sublen;
		 delete this->_myString;
		 this->_myString = new char[this->_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;

	 }
	 return *this;

 }
MyString& MyString::insert(size_t pos, const char* str)
 {
	 int sizeOfStr = 0;
	 while (str[sizeOfStr] != '\0')
	 {
		 sizeOfStr++;
	 }
	 if (this->_size + sizeOfStr <= this->_capacity)
	 {

		 for (int i = this->_size + sizeOfStr - 1; i >= pos + sizeOfStr; i--)
		 {
			 this->_myString[i] = this->_myString[i - sizeOfStr];
		 }
		 for (int i = 0; i < sizeOfStr; i++)
		 {
			 this->_myString[i + pos] = str[i];
		 }
		 this->_size += sizeOfStr;

	 }
	 else
	 {

		 this->_capacity = ((this->_size + sizeOfStr) / 16 + 1) * 16 - 1;
		 char *p;
		 p = new char[this->_capacity];
		 for (int i = 0; i<pos; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = pos; i<pos + sizeOfStr; i++)
		 {
			 p[i] = str[i - pos];
		 }
		 for (int i = pos + sizeOfStr; i<this->_size + sizeOfStr; i++)
		 {
			 p[i] = this->_myString[i - sizeOfStr];
		 }

		 this->_size += sizeOfStr;
		 delete this->_myString;
		 this->_myString = new char[this->_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
MyString& MyString::insert(size_t pos, const char* str, size_t n)
 {
	 if (this->_size + n <= this->_capacity)
	 {

		 for (int i = this->_size + n - 1; i >= pos + n; i--)
		 {
			 this->_myString[i] = this->_myString[i - n];
		 }
		 for (int i = 0; i < n; i++)
		 {
			 this->_myString[i + pos] = str[i];
		 }
		 this->_size += n;
	 }
	 else
	 {

		 this->_capacity = ((this->_size + n) / 16 + 1) * 16 - 1;
		 char *p;
		 p = new char[this->_capacity];
		 for (int i = 0; i<pos; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = pos; i<pos + n; i++)
		 {
			 p[i] = str[i - pos];
		 }
		 for (int i = pos + n; i<this->_size + n; i++)
		 {
			 p[i] = this->_myString[i - n];
		 }
		 this->_size += n;
		 delete this->_myString;
		 this->_myString = new char[this->_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;
	 }
	 return *this;
 }
MyString& MyString::insert(size_t pos, size_t n, char c)
 {

	 if (this->_size + n <= this->_capacity)
	 {

		 for (int i = this->_size + n - 1; i >= pos + n; i--)
		 {
			 this->_myString[i] = this->_myString[i - n];
		 }
		 for (int i = 0; i < n; i++)
		 {
			 this->_myString[i + pos] = c;
		 }
		 this->_size += n;

	 }
	 else
	 {

		 this->_capacity = ((this->_size + n) / 16 + 1) * 16 - 1;
		 char *p;
		 p = new char[this->_capacity];
		 for (int i = 0; i<pos; i++)
		 {
			 p[i] = this->_myString[i];
		 }
		 for (int i = pos; i<pos + n; i++)
		 {
			 p[i] = c;
		 }
		 for (int i = pos + n; i<this->_size + n; i++)
		 {
			 p[i] = this->_myString[i - n];
		 }


		 this->_size += n;
		 delete this->_myString;
		 this->_myString = new char[this->_capacity];
		 for (int i = 0; i < this->_size; i++)
		 {
			 this->_myString[i] = p[i];
		 }
		 delete p;

	 }
	 return *this;
 }
void MyString::insert(iterator p, size_t n, char c)
{
	int index = 0;
	iterator it = this->begin();
	while (it != p)
	{
		index++;
		it++;
	}
	this->insert(index, n, c);
	
}
MyString& MyString::insert(iterator p, char c)
{
	int index = 0;
	iterator it = this->begin();
	while (it != p)
	{
		index++;
		it++;
	}
	return this->insert(index, 1, c);
}
void MyString::insert(iterator p, iterator first, iterator last)
{
	int index = 0;
	iterator it = this->begin();
	while (it != p)
	{
		index++;
		it++;
	}
	MyString str;
	it = first;
	for (it; it != last; it++)
	{
		str.push_back(*it);
	}
	this->insert(index,str);
}

 MyString& MyString::erase(size_t pos, size_t len)
 {
	 for (int i = 0; i < this->_size - pos - len; i++)
	 {
		 this->_myString[i + pos] = this->_myString[i + pos + len];
	 }
	 this->_size  =this->_size- len;
	 return *this;
 }
 MyString& MyString::erase(iterator p)
 {
	 int i = 0;
	 iterator index=this->begin();
	 while (i<this->_size)
	 {
		 if (index = p)
		 {
			 this->_size = i + 1;
			 return *this;
		 }
		 i++;
	 }
	 
	 return *this;
 }
 MyString& MyString::erase(iterator first, iterator last)
 {
	 int i1 = 0,i2=0;
	 for (auto it = this->begin(); it != first; it++)
	 {
		 i1++;
	 }
	 for (auto it = first; it != last; it++)
	 {
		 i2++;
	 }
	 for (int j =0 ; j < this->_size - i2; j++)
	 {
		 this->_myString[i1 + j] = this->_myString[i2 + j];
	 }
	 this->_size -= i2;
	 return *this;
 }

MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
 {
	 if (pos + len <= this->_size)
	 {
		 if (this->_size + str._size - len < this->_capacity)
		 {
			 char *p;
			 p = new char[this->_size - pos - len];
			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 p[i] = this->_myString[pos + len + i];
			 }
			 for (int i = 0; i < str._size; i++)
			 {
				 this->_myString[i + pos] = str._myString[i];
			 }

			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 this->_myString[i + pos + str._size] = p[i];
			 }
			 this->_size = this->_size + str._size - len;
			 delete p;
		 }
		 else
		 {
			 char *p1, *p2;
			 p1 = new char[pos];
			 p2 = new char[this->_size - pos - len];
			 for (int i = 0; i < pos; i++)
			 {
				 p1[i] = this->_myString[i];
			 }
			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 p2[i] = this->_myString[pos + len + i];
			 }
			 delete this->_myString;
			 this->_capacity = ((this->_size + str._size - len) / 16 + 1) * 16 - 1;
			 this->_myString = new char[this->_capacity];
			 for (int i = 0; i < pos; i++)
			 {
				 this->_myString[i] = p1[i];
			 }
			 for (int i = 0; i < str._size; i++)
			 {
				 this->_myString[i + pos] = str._myString[i];
			 }

			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 this->_myString[i + pos + str._size] = p2[i];
			 }
			 this->_size = this->_size + str._size - len;
			 delete p1, p2;
		 }

	 }
	 else
	 {
		 if (this->_size + str._size - len < this->_capacity)
		 {
			
			 this->_size = pos + str._size;
			 for (int i = 0; i < str._size; i++)
			 {
				 this->_myString[i + pos] = str._myString[i];
			 }
		 }
		 else
		 {
			 char *p1;
			 p1 = new char[pos];
			
			 for (int i = 0; i < pos; i++)
			 {
				 p1[i] = this->_myString[i];
			 }
			 
			 delete this->_myString;
			 this->_size = pos + str._size;
			 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
			 this->_myString = new char[this->_capacity];
			 for (int i = 0; i < pos; i++)
			 {
				 this->_myString[i] = p1[i];
			 }
			 for (int i = 0; i < str._size; i++)
			 {
				 this->_myString[i + pos] = str._myString[i];
			 }

			 delete p1;
		 }

	 }
	 

	 return *this;
 }
MyString& MyString::replace(iterator i1, iterator i2, const MyString& str)
{
	int i_1 = 0, i_2 = 0;
	iterator index;
	index = this->begin();
	while (1)
	{
		if (index == i1)
		{
			break;
		}
		index++;
		i_1++;
	}
	index = i1;
	while (1)
	{
		if (index == i2)
		{
			break;
		}
		index++;
		i_2++;
	}
	return this->replace(i_1, i_2, str);
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
 {

	 if (pos + len <= this->_size)
	 {
		 if (this->_size + sublen - len < this->_capacity)
		 {
			 char *p;
			 p = new char[this->_size - pos - len];
			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 p[i] = this->_myString[pos + len + i];
			 }
			 for (int i = 0; i < sublen; i++)
			 {
				 this->_myString[i + pos] = str._myString[i + subpos];
			 }

			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 this->_myString[i + pos + sublen] = p[i];
			 }
			 this->_size = this->_size + sublen - len;
			 delete p;
		 }
		 else
		 {
			 char *p1, *p2;
			 p1 = new char[pos];
			 p2 = new char[this->_size - pos - len];
			 for (int i = 0; i < pos; i++)
			 {
				 p1[i] = this->_myString[i];
			 }
			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 p2[i] = this->_myString[pos + len + i];
			 }
			 delete this->_myString;
			 this->_capacity = ((this->_size + sublen - len) / 16 + 1) * 16 - 1;
			 this->_myString = new char[this->_capacity];
			 for (int i = 0; i < pos; i++)
			 {
				 this->_myString[i] = p1[i];
			 }
			 for (int i = 0; i < sublen; i++)
			 {
				 this->_myString[i + pos] = str._myString[i+subpos];
			 }

			 for (int i = 0; i < this->_size - pos - len; i++)
			 {
				 this->_myString[i + pos + sublen] = p2[i];
			 }
			 this->_size = this->_size + sublen - len;
			 delete p1;
			 delete p2;
		 }

	 }
	 else
	 {
		 if (this->_size + str._size - len < this->_capacity)
		 {

			 this->_size = pos + sublen;
			 for (int i = 0; i < sublen; i++)
			 {
				 this->_myString[i + pos] = str._myString[i+subpos];
			 }
		 }
		 else
		 {
			 char *p1;
			 p1 = new char[pos];

			 for (int i = 0; i < pos; i++)
			 {
				 p1[i] = this->_myString[i];
			 }

			 delete this->_myString;
			 this->_size = pos + sublen;
			 this->_capacity = (this->_size / 16 + 1) * 16 - 1;
			 this->_myString = new char[this->_capacity];
			 for (int i = 0; i < pos; i++)
			 {
				 this->_myString[i] = p1[i];
			 }
			 for (int i = 0; i < sublen; i++)
			 {
				 this->_myString[i + pos] = str._myString[i+subpos];
			 }

			 delete p1;
		 }

	 }


	 return *this;

 }
MyString& MyString::replace(iterator i1, iterator i2, const char* str)
 {
	 int i_1 = 0, i_2 = 0;
	 iterator index;
	 index = this->begin();
	 while (1)
	 {
		 if (index == i1)
		 {
			 break;
		 }
		 index++;
		 i_1++;
	 }
	 index = i1;
	 while (1)
	 {
		 if (index == i2)
		 {
			 break;
		 }
		 index++;
		 i_2++;
	 }
	 return this->replace(i_1, i_2, str);
 }
MyString& MyString::replace(size_t pos, size_t len, const char* s)
 {
	 MyString str(s);
	 return this->replace(pos,len,str);

 }
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
 {
	 MyString str(s);
	 return this->replace(pos, len, str,0,n);
 }
MyString& MyString::replace(iterator i1, iterator i2, const char* str, size_t n)
{
	int i_1 = 0, i_2 = 0;
	iterator index;
	index = this->begin();
	while (1)
	{
		if (index == i1)
		{
			break;
		}
		index++;
		i_1++;
	}
	index = i1;
	while (1)
	{
		if (index == i2)
		{
			break;
		}
		index++;
		i_2++;
	}
	return this->replace(i_1, i_2, str,n);
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
 {
	 char *p;
	 p = new char[n];
	 for (int i = 0; i < n; i++)
	 {
		 p[i] = c;
	 }
	 MyString str(p);
	 delete p;
	 return this->replace(pos, len, str);
	 
 }
MyString& MyString::replace(iterator i1, iterator i2, size_t n, char c)
{
	int i_1 = 0, i_2 = 0;
	iterator index;
	index = this->begin();
	while (1)
	{
		if (index == i1)
		{
			break;
		}
		index++;
		i_1++;
	}
	index = i1;
	while (1)
	{
		if (index == i2)
		{
			break;
		}
		index++;
		i_2++;
	}
	return this->replace(i_1, i_2, c, n);
}
MyString& MyString::replace(iterator i1, iterator i2, iterator first, iterator last)
{

	int i_1 = 0, i_2 = 0;
	iterator index;
	MyString str;
	for (auto it = first; it != last; it++)
	{
		str.push_back(*it);
	}
	index = this->begin();
	while (1)
	{
		if (index == i1)
		{
			break;
		}
		index++;
		i_1++;
	}
	index = i1;
	while (1)
	{
		if (index == i2)
		{
			break;
		}
		index++;
		i_2++;
	}
	return this->replace(i_1, i_2, str);
}

 void MyString::swap(MyString& str)
 {
	 MyString temp;
	 temp = str;
	 str = *this;
	 *this = temp;
 }

 void MyString::pop_back()
 {
	 this->_size--;
 }

 size_t MyString::copy(char* s, size_t len, size_t pos ) const
 {
	 for (int i = 0; i < len; i++)
	 {
		 s[i] = this->_myString[i + pos];
	 }
	 return len;
 }
 size_t MyString::find(const MyString& str, size_t pos) const
 {
	
	 for (int i = pos; i < this->_size - str._size; i++)
	 {
		 MyString p(*this, i, str._size);
		 if (p == str)
		 {
			 
			return i ;
		 }
	 }
	 return npos;
 }
 size_t MyString::find(const char* s, size_t pos)  const
 {
	 MyString str(s);
	 return this->find(str, pos);
 }
 size_t MyString::find(const char* s, size_t pos, size_t n) const
 {
	 MyString str(s,n);
	 return this->find(str, pos);
 }
 size_t MyString::find(char c, size_t pos ) const
 {
	 for (int i = pos; i < this->_size ; i++)
	 {
		
		 if (this->_myString[i] == c)
		 {
			 return i;
		 }
	 }
	 return npos;
 }
 
 size_t MyString::rfind(const MyString& str, size_t pos ) const
 {
	 if (pos == npos)
	 {
		 pos = this->_size;
	 }
	 for (int i = pos - 1-str._size; i >0; i--)
	 {
		 MyString p(*this, i, str._size);
		 if (p == str)
		 {
			 return i;
		 }
	 }
	 return npos;
 }
 size_t MyString::rfind(const char* s, size_t pos ) const
 {
	 MyString str(s);
	 return this->rfind(str,pos);
 }
 size_t MyString::rfind(const char* s, size_t pos, size_t n) const
 {
	 MyString str(s, n);
	 return this->rfind(s, pos);
 }
 size_t MyString::rfind(char c, size_t pos) const
 {
	 if (pos == npos)
	 {
		 pos = this->_size;
	 }
	 for (int i = pos - 1 ; i >0; i--)
	 {
		
		 if (c == this->_myString[i])
		 {
			 return i;
		 }
	 }
	 return npos;
 }

 size_t MyString::find_first_of(const MyString& str, size_t pos) const
 {
	 for (int i = pos; i < this->_size ; i++)
	 {
		 for (int j = 0; j < str._size; j++)
		 {
			 if (str._myString[j] == this->_myString[i])
			 {
				 return i;
			 }
		 }
	 }
	 return npos;
 }
size_t MyString::find_first_of(const char* s, size_t pos ) const
 {
	MyString str(s);
	return this->find_first_of(str, pos);
 }
size_t MyString::find_first_of(const char* str, size_t pos, size_t n) const
{
	for (int i = pos; i < this->_size; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[j] == this->_myString[i])
			{
				return i;
			}
		}
	}
	return npos;
}
size_t MyString::find_first_of(char c, size_t pos ) const
{
	for (int i = pos; i < this->_size; i++)
	{
		
			if (c == this->_myString[i])
			{
				return i;
			}
	
	}
	return npos;
}

 size_t MyString::find_last_of(const MyString& str, size_t pos ) const
{
	if (pos == npos)
	{
		pos = this->_size;
	}
	for (int i = pos-1; i >0; i--)
	{
		for (int j = 0; j < str._size; j++)
		{
			if (str._myString[j] == this->_myString[i])
			{
				return i;
			}
		}
	}
	return npos;
}
 size_t MyString::find_last_of(const char* s, size_t pos) const
 {
	 MyString str(s);
	 return this->find_last_of(str, pos);
 }
 size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const
 {
	 MyString str(s,n);
	 return this->find_last_of(str, pos);
 }
 size_t MyString::find_last_of(char c, size_t pos) const
 {
	 if (pos == npos)
	 {
		 pos = this->_size;
	 }
	 for (int i = pos; i >0; i--)
	 {
		
			 if (c== this->_myString[i])
			 {
				 return i;
			 }
		
	 }
	 return npos;
 }

 size_t MyString::find_first_not_of(const MyString& str, size_t pos) const
 {
	 for (int i = pos; i < this->_size; i++)
	 {
		 int kt = 0;
		 for (int j = 0; j < str._size; j++)
		 {
			 if (str._myString[j] == this->_myString[i])
			 {
				 kt++;
			 }
		 }
		 if (kt == 0)
		 {
			 return i;
		 }
	 }
	 return npos;
 }
 size_t MyString::find_first_not_of(const char* s, size_t pos) const
 {
	 MyString str(s);
	 return this->find_first_not_of(str, pos);
 }
 size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const
 {
	 MyString str(s,n);
	 return this->find_first_not_of(str, pos);

 }
 size_t MyString::find_first_not_of(char c, size_t pos) const
 {
	 for (int i = pos; i < this->_size; i++)
	 {
		 if (c != this->_myString[i])
		 {
			 return i;
		 }
	 }
	 return npos;
 }

 size_t MyString::find_last_not_of(const MyString& str, size_t pos ) const
 {
	 if (pos == npos)
	 {
		 pos = this->_size;
	 }
	 for (int i = pos-1; i >0; i--)
	 {
		 int kt = 0;
		 for (int j = 0; j < str._size; j++)
		 {
			 if (str._myString[j] == this->_myString[i])
			 {
				 kt++;
			 }
		 }
		 if (kt == 0)
		 {
			 return i;
		 }
	 }
	 return npos;
 }
 size_t MyString::find_last_not_of(const char* s, size_t pos ) const
 {
	 MyString str(s);
	 return this->find_last_not_of(str, pos);
 }
 size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const
 {
	 MyString str(s,n);
	 return this->find_last_not_of(str, pos);
 }
 size_t MyString::find_last_not_of(char c, size_t pos) const
 {
	 if (pos == npos)
	 {
		 pos = this->_size;
	 }
	 for (int i = pos - 1; i >0; i--)
	 {
		
		 if (c!=this->_myString[i])
		 {
			 return i;
		 }
	 }
	 return npos;
 }

 int MyString :: compare(const MyString& str) const
 {
	 if (this->_size < str._size)
	 {
		 return -1;
	 }
	 else if(this->_size == str._size)
	 {
		 for (int i = 0; i < this->_size; i++)
		 {
			 if (this->_myString[i] < str._myString[i])
			 {
				 return -1;
			 }
			 else if (this->_myString[i] > str._myString[i])
			 {
				 return 1;
			 }
		 }
		 return 0;
	 }
	 return 1;
 }
 int MyString::compare(size_t pos, size_t len, const MyString& str) const
 {
	 if (len < str._size)
	 {
		 return -1;
	 }
	 else if (len == str._size)
	 {
		 for (int i = 0; i < len; i++)
		 {
			 if (this->_myString[i+pos] < str._myString[i])
			 {
				 return -1;
			 }
			 else if (this->_myString[i+pos] > str._myString[i])
			 {
				 return 1;
			 }
		 }
		 return 0;
	 }
	 return 1;
 }
 int MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const
 {

	 if (len < sublen)
	 {
		 return -1;
	 }
	 else if (len == sublen)
	 {
		 for (int i = 0; i < len; i++)
		 {
			 if (this->_myString[i + pos] < str._myString[i+subpos])
			 {
				 return -1;
			 }
			 else if (this->_myString[i + pos] > str._myString[i+subpos])
			 {
				 return 1;
			 }
		 }
		 return 0;
	 }
	 return 1;
 }
 int MyString::compare(const char* s) const
 {
	 MyString str(s);
	 return this->compare(str);
 }
 int MyString::compare(size_t pos, size_t len, const char* s) const
 {
	 MyString str(s);
	 return this->compare(pos,len,str);
 }
 int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const
 {
	 MyString str(s);
	 return this->compare(pos, len, str,0,n);
 }

 MyString MyString::substr(size_t pos, size_t len) const
 {
	 MyString str;
	 for (int i = 0; i < len; i++)
	 {
		 str.push_back(this->_myString[i + pos]);
	 }
	 return str;
 }

 void MyString::swap(MyString& x, MyString& y)
 {
	 x.swap(y);
 }

 const char* MyString::c_str() const
 {
	 this->_myString[this->_size] = '\0';
	 return this->_myString;
 }

 const char* MyString::data() const
 {
	 this->_myString[this->_size] = '\0';
	 return this->_myString;
 }

 void MyString::reserve(size_t n )
 {
	 char* p;
	 p = new char[this->_size];
	 for (int i = 0; i < this->_size; i++)
	 {
		 p[i] = this->_myString[i];
	 }
	 delete this->_myString;
	 this->_capacity = (n / 16 + 1) * 16 - 1;
	 this->_myString = new char[this->_capacity];
	 for (int i = 0; i < this->_size; i++)
	 {
		 this->_myString[i] = p[i];
	 }
 }
 //////////////////////getline
 istream& getline(istream& is, MyString& str)
 {
	 char c;
	  c=_getch();
	 while (c != 13)
	 {
		 cout << c;
		 str.push_back(c);
		  c = _getch();
	 }
	 return is;

 }


 istream& getline(istream& is, MyString& str, char delim)
 {
	 char c;
	
	 int de_lim = delim;
	 int i = 1;
	 while (1)
	 {
		 c = _getch();
		 if (c != 13)
		 {
			 cout << c;
		 }
		 if (c == 13 && i)
		 {
			 str.push_back('\n');
		 }
		 if (c != de_lim&&i)
		 {
			 str.push_back(c);
		 }
		 if (c==de_lim)
		 {
			 i = 0;
		 }
		 if (c == 13)
		 {
			 cout << endl;
		 }
		 if (c == 13 && i == 0)
		 {
			 break;
		 }
	 } 
	 return is;
 }
