//Author: Ngo Tan Vinh
//email:kieuphong2840@gmail.com
//Cai dat Lop String
//Su dung cac cau lenh don gian


#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include<conio.h>
#include<iostream>
#include<iterator>
using namespace std;
typedef allocator<char>  allocator_type;
typedef   unsigned int size_t;
class MyString
{ 
public:
	static const size_t npos = 4294967291;
private:
	char *_myString;
	int _size;
	int _capacity;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString &str);

	MyString(const MyString& str, size_t pos, size_t len = npos);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);
	~MyString();
	
	//operator
	friend ostream& operator<<(ostream&, MyString p);
	friend istream& operator>>(istream&, MyString p);
	MyString& operator= (const char *str);
	MyString& operator= (const char str);
	MyString& operator= (const MyString &str);
	MyString operator+ ( const MyString& rhs);
	MyString operator+ ( const char*   rhs);
	MyString operator+ ( char          rhs);
	bool operator==(const MyString&);
	bool operator== (const char*   rhs);
	bool operator!=(const MyString&);
	bool operator!= (const char*   rhs);
	bool operator>=(const MyString&);
	bool operator>= (const char*   rhs);
	bool operator<=(const MyString&);
	bool operator<= (const char*   rhs);
	bool operator>(const MyString&);
	bool operator>  (const char*   rhs);
	bool operator<(const MyString&);
	bool operator<  (const char*   rhs);
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);
	///////////////////////////////Element access:
	char operator[](int);
	char& at(int);
	char& back();
	char& front();
	////////////////////////////////////////////////////////
	
	///////////////////////interators
	typedef char * iterator;
	iterator begin()
	{
		return _myString;
	}
	
	typedef char * const_iterator;
	const_iterator begin() const
	{
		return _myString;
	}

	typedef char * iterator;
	iterator end()
	{
		return (_myString+_size);
	}
	typedef char * const_iterator;
	const_iterator end() const
	{
		return (_myString + _size );
	}

	
	typedef char * reverse_iterator;
	reverse_iterator rbegin()
	{
		return (_myString + _size);
	}

	typedef char * const_reverse_iterator;
	const_reverse_iterator rbegin() const
	{
		return (_myString + _size);
	}
	
	typedef char * reverse_iterator;
	reverse_iterator rend()
	{
		return (_myString);
	}

	typedef char * const_reverse_iterator;
	const_reverse_iterator rend() const
	{
		return (_myString);
	}

	const_iterator cbegin() const //noexcept
	{
		return (_myString);
	}

	const_iterator cend() const //noexcept
	{
		return (_myString+_size);
	}

	const_reverse_iterator crbegin() const //noexcept
	{
		return _myString + _size;
	}
	const_reverse_iterator crend() const //noexcept
	{
		return _myString ;
	}
	

	///////////////////////////////
	//capacity
	int size();
	int length();
	int capacity();
	size_t max_size();
	void resize(int new_size,char add_str);

	void clear();
	bool empty();
	void shrink_to_fit();
	////////////Modifiers
	void push_back(char c);

	//////
	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	typedef char * iterator;
	MyString& append(iterator first, iterator last);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	typedef char * iterator;
	MyString& MyString::assign(iterator first, iterator last);
	


	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(iterator p, size_t n, char c);
	MyString& insert(iterator p, char c);
	typedef char * iterator;
	void insert(iterator p, iterator first, iterator last);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(iterator i1, iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str,		size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(iterator i1, iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(iterator i1, iterator i2, const char* s, size_t n);//
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, size_t n, char c);
	typedef char * iterator;
	MyString& replace(iterator i1, iterator i2, iterator first, iterator last);

	void swap(MyString& str);
	void pop_back();


	size_t copy(char* s, size_t len, size_t pos=0) const;

	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	
	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	
	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	
	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	
	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str,	size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	MyString substr(size_t pos , size_t len ) const;
	////////////Non-member function overloads
	
	MyString& erase(size_t pos, size_t len);
	MyString& erase(iterator p);
	MyString& erase(iterator first, iterator last);

	void swap(MyString& x, MyString& y);


	const char* c_str() const;
	const char* data() const;
	void reserve(size_t n = 0);
	
	allocator_type get_allocator() const;
	
};
MyString operator+ (const char*   lhs, const MyString& rhs);
MyString operator+ (char          lhs, const MyString& rhs);
bool operator== (const char*   lhs, const MyString& rhs);
bool operator!= (const char*   lhs, const MyString& rhs);
bool operator<  (const char*   lhs, const MyString& rhs);
bool operator<= (const char*   lhs, const MyString& rhs);
bool operator>  (const char*   lhs, const MyString& rhs);
bool operator>= (const char*   lhs, const MyString& rhs);

istream& getline(istream& is, MyString& str);


istream& getline(istream& is, MyString& str, char delim);

#endif