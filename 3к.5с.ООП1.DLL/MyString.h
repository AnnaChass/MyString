#pragma once
#include <iostream>
#include <string>

template <typename T>
class MyString
{
private:
	int count = 0;
	T* elems;
	char* c_str_elems = NULL;

public:
	MyString() : count(0) { elems = new T[0];  }
	MyString(const MyString &str); 				// copy constructor
	MyString(char *str);					// char array constructor
	MyString(std::initializer_list<T> list);	// initializer list constructor 
	MyString(std::string str);				// std::string constructor
	MyString(char *str, int count); 		// init class with count characters of  char *str,Constructor(“hello”, 4) -> “hell”
	MyString(T *data, int count, int flag); // for own service
	MyString(int count, char simbol);		// init class with count of characters	MyString(4, ‘a’)->“aaa”

	~MyString();

	T* operator + (const MyString &str); 		// concatenate with Mystring
	T* operator + (char *str); 			// concatenate with char array
	T* operator + (std::string str); 	// concatenate with std::string
	T* operator += (const MyString &str); 		// assignment with Mystring
	T* operator += (char *str); 	// assignment concatenate with char array
	T* operator += (std::string str); 	// assignment concatenate with std::string
	T* operator = (const MyString &str); 		//  Mystring assignment
	T* operator = (char *str); 	// char string assignment
	T* operator = (std::string str); 	// std::string assignment
	T* operator = (char simbol); 		// char assignment
	T& operator[](int i) const; 		// index operator, Mystring(“012345”);[5] ->‘5’
	
	bool operator>(char* str) const;
	bool operator>(std::string str) const;
	bool operator>(const MyString &str) const;
	bool operator<(char* str) const;
	bool operator<(std::string str) const;
	bool operator<(const MyString &str) const;
	bool operator>=(char* str) const;
	bool operator>=(std::string str) const;
	bool operator>=(const MyString &str) const;
	bool operator<=(char* str) const;
	bool operator<=(std::string str) const;
	bool operator<=(const MyString &str) const;
	bool operator==(char* str) const;
	bool operator==(std::string str) const;
	bool operator==(const MyString &str) const;
	bool operator!=(char* str) const;
	bool operator!=(std::string str) const;
	bool operator!=(const MyString &str) const;
	
	const char *c_str();		// return a pointer to null-terminated character array
	const T* data() const;		// return a pointer to array data that not required to be null-terminated
	int length() const; 		// same as size 
	int size() const; 		// return the number of char elements in string
	bool empty() const; 		// true if string is empty
	int capacity() const; 	// return the current amount of allocated memory for array
	void clear(); 		// remove all char element in string

	void insert(int index, int count, char simbol); /* insert count of char in index position s = “aaaaa” 
														s.insert(0, 1, ’!’)->“!aaaaa” 
														s.insert(3, 2, ’@’)->“!aa@@aaa” */
	void insert(int index, char *str); /* insert null-terminated char string at index position
														s = “aaaaa” 
														s.insert(1, ”@@@@@”)->“a@@@@@aaaa” */
	void insert(int index, char *str, int l_count); /* insert count of null-terminated char string at index position 
														s = “aaaaa” 
														s.insert(1, ”@@@@@”, 2)->“a@@aaaa” */
	void insert(int index, std::string str); /* insert std::string at index position 
														s = “aaaaa” 
														string = “@@@@@” 
														s.insert(1, std::string(“@@@@@”))->“a@@@@@aaaa” */
	void insert(int index, std::string str, int l_count); /* insert count of std::string at index position 
														s = “aaaaa” 
														s.insert(1, std::string(“@@@@@”)), 2)->“a@@aaaa” */
	void erase(int index, int l_count); /* erase count of char at index position 
														s = “aa@@@@@aaa” 
														s.erase(2, 3)->“a@@aaaa” */
	void append(int count, char simbol); /* append count of char 
														str.clear()->“” 
														str.append(3, ’!’)->“!!!” 
														str.append(3, ’@’)->“!!!@@@” */
	void append(char *str); /* append null-terminated char string 
														str.clear()->“” 
														str.append(“hello ”)->“hello ” 
														str.append(“world”)->“hello world” */
	void append(char *str, int index, int count); /* append a count of null-terminated char string by index position 
														str.clear()->“” 
														str.append(“hello world”, 0, 6)->“hello ” 
														str.append(“hello world”, 6, 5)->“hello world” */
	void append(std::string str); /* append std:: string 
														str.clear()->“” 
														str.append(std::string(“hello ”))->“hello ” 
														str.append(std::string(“world”))->“hello world” */
	void append(std::string str, int index, int count); /* append a count of std:: string by index position 
														str.clear()->“” 
														str.append(std::string(“hello world”), 0, 6)->“hello ” 
														str.append(std::string(“hello world”), 6, 5)->“hello world” */
	void replace(int index, int count, char *str); /* replace a count of char at index by char *str 
														s = “hello amazing world” 
														s.replace(6, 7, ”wonderful”)->“hello wonderful world” */
	void replace(int index, int count, std::string str); /* replace a count of char at index by std::string 
														s = “hello amazing world” 
														s.replace(6, 7, std::string(”wonderful”))->“hello wonderful world” */
	const char * substr(int index); 		/* return a substring starts with index position 
														s = “hello amazing world” 
														s.substr(6)->“amazing world” */
	const char * substr(int index, int count);	/* return a count of substring’s char starts with index position 
														s = “hello amazing world” 
														s.substr(6, 7)->“amazing” */
	int find(char *str) const; // if founded return the index of substring
	int find(char *str, int index) const; // same as find(char *str) but search starts from index position
	int find(std::string str) const; // if founded return the index of substring
	int find(std::string str, int index) const; // same as find(char *str) but search starts from index position
};

// copy constructor
template<typename T>
MyString<T>::MyString(const MyString & str) 
{
	count = str.count;
	elems = new T[count];
	memmove(elems, str.elems, count);
}

// char array constructor
template <typename T>
MyString<T>::MyString(char *str)					// char array constructor
{
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) count++;
		else break;
	}
	elems = new T[count];
	memmove(elems, str, count);	
}

// initializer list constructor 
template<typename T>
MyString<T>::MyString(std::initializer_list<T> list)
{
	count = list.size();
	elems = new T[count];
	T* point = elems;
	for (auto it = list.begin(); it != list.end(); ++it, ++point)
	{
		*point = *(const_cast<T *>(it));
	}
}

// std::string constructor
template<typename T>
MyString<T>::MyString(std::string str)
{
	count = str.length();
	elems = new T[count];
	memcpy(elems, str.c_str(), count);
}

// init class with count characters of  char *str,Constructor(“hello”, 4) -> “hell”
template<typename T>
MyString<T>::MyString(char * str, int count)
{
	this->count = count;
	elems = new T[count];
	memmove(elems, str, count);
}

// any-type array constructor, for own service
template <typename T>
MyString<T>::MyString(T *data, int count, int flag)
{
	this->count = count;
	elems = new T[count];
	memcpy(elems, data, count * sizeof(T));
}

// init class with count of characters	MyString(4, ‘a’)->“aaa”
template<typename T>
MyString<T>::MyString(int count, char simbol)
{
	this->count = count;
	elems = new T[count];
	for (int i = 0; i < count; ++i)
		elems[i] = simbol;
}

template <typename T>
MyString<T>::~MyString()					
{
	if (count != 0)
	{
		delete[] elems;
		if (c_str_elems != NULL) 
			delete[] c_str_elems;
	}
}

// concatenate with MyString
template <typename T>
T* MyString<T>::operator + (const MyString &str)
{
	T* new_elems = new T[count + str.count];
	memcpy(new_elems, elems, count * sizeof(T));
	memcpy(new_elems + count, str.elems, str.count * sizeof(T));
	return new_elems;
}

template<typename T>
T* MyString<T>::operator+(char * str)
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// create new char* new_str
	T* new_str = new T[count + l_count];
	memcpy(new_str, elems, count * sizeof(T));
	memcpy(new_str + count, str, l_count * sizeof(T));
	return new_str;
}

template<typename T>
T* MyString<T>::operator+(std::string str)
{
	// create new char* new_str
	T* new_str = new T[count + str.length()];
	memcpy(new_str, elems, count * sizeof(T));
	memcpy(new_str + count * sizeof(T), str.c_str(), str.length() * sizeof(T));
	return new_str;
}

template<typename T>
T * MyString<T>::operator+=(const MyString & str)
{
	T* new_elems = new T[count + str.count];
	memcpy(new_elems, elems, count * sizeof(T));
	memcpy(new_elems + count * sizeof(T), str.elems, str.count * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count += str.count;
	return new_elems;
}

template<typename T>
T * MyString<T>::operator+=(char * str)
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// expand the elems
	T* new_elems = new T[count + l_count];
	memcpy(new_elems, elems, count * sizeof(T));
	memcpy(new_elems + count * sizeof(T), str, l_count * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count += l_count;
	return new_elems;
}

template<typename T>
T * MyString<T>::operator+=(std::string str)
{
	// expand the elems
	T* new_elems = new T[count + str.length()];
	memcpy(new_elems, elems, count * sizeof(T));
	memcpy(new_elems + count * sizeof(T), str.c_str(), str.length() * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count += str.length();
	return new_elems;
}

template<typename T>
T * MyString<T>::operator=(const MyString & str)
{
	T* new_elems = new T[str.count];
	memcpy(new_elems, str.elems, str.count * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count = str.count;
	return new_elems;
}

template<typename T>
T* MyString<T>::operator=(char * str)
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// expand or narrow the elems
	T* new_elems = new T[l_count];
	memcpy(new_elems, str, l_count * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count = l_count;
	return new_elems;
}

template<typename T>
T * MyString<T>::operator=(std::string str)
{
	// expand or narrow the elems
	T* new_elems = new T[str.length()];
	memcpy(new_elems, str.c_str(), str.length() * sizeof(T));
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count = str.length();
	return new_elems;
}

template<typename T>
T * MyString<T>::operator=(char simbol)
{
	// expand or narrow the elems
	T* new_elems = new T[1];
	new_elems[0] = simbol;
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	count = 1;
	return new_elems;
}

template<typename T>
T & MyString<T>::operator[](int i) const
{
	return elems[i];
}

template<typename T>
bool MyString<T>::operator>(char * str) const
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// compare
	if (count > l_count) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator>(std::string str) const
{
	if (count > str.length()) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator>(const MyString & str) const
{
	if (count > str.count) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator<(char * str) const
{
	return !operator>=(str);
}

template<typename T>
bool MyString<T>::operator<(std::string str) const
{
	
	return !operator>=(str);
}

template<typename T>
bool MyString<T>::operator<(const MyString & str) const
{
	return !operator>=(str);
}

template<typename T>
bool MyString<T>::operator>=(char * str) const
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// compare
	if (count >= l_count) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator>=(std::string str) const
{
	if (count >= str.length()) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator>=(const MyString & str) const
{
	if (count >= str.count) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator<=(char * str) const
{
	return !operator>(str);
}

template<typename T>
bool MyString<T>::operator<=(std::string str) const
{

	return !operator>(str);
}

template<typename T>
bool MyString<T>::operator<=(const MyString & str) const
{
	return !operator>(str);
}

template<typename T>
bool MyString<T>::operator==(char * str) const
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// compare
	if (count == l_count && !strcmp(elems, str)) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator==(std::string str) const
{
	if (count == str.length() && !strcmp(elems, str.c_str())) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator==(const MyString & str) const
{
	if (count == str.count && !strcmp(elems, str.elems)) return true;
	return false;
}

template<typename T>
bool MyString<T>::operator!=(char * str) const
{
	return !operator==(str);
}

template<typename T>
bool MyString<T>::operator!=(std::string str) const
{

	return !operator==(str);
}

template<typename T>
bool MyString<T>::operator!=(const MyString & str) const
{
	return !operator==(str);
}

// return a pointer to null-terminated character array
template<typename T>
const char* MyString<T>::c_str()
{
	if (!c_str_elems)
	{
		c_str_elems = new char[count + 1];
		memcpy(c_str_elems, elems, count);
		c_str_elems[count] = '\0';
	}
	else
	{
		if (strncmp(elems, c_str_elems, count) || count != strlen(c_str_elems))
		{
			delete[] c_str_elems;
			c_str_elems = NULL;
			return c_str();
		}
	}
	return static_cast<const char *> (c_str_elems);
}

// return a pointer to array data that not required to be null-terminated
template<typename T>
const T * MyString<T>::data() const
{
	return elems;
}

template<typename T>
int MyString<T>::length() const
{
	return size();
}

template<typename T>
int MyString<T>::size() const
{
	return count;
}

template<typename T>
bool MyString<T>::empty() const
{
	if (!count) return true;
	return false;
}

// return the current amount of allocated memory for array (in bytes)
template<typename T>
int MyString<T>::capacity() const
{
	return count * sizeof(T);
}

template<typename T>
void MyString<T>::clear()
{
	count = 0;
	delete[] elems;
	if (!c_str_elems) delete[] c_str_elems;

	elems = new T[0];
}

// insert count of char in index position s = “aaaaa” \
														s.insert(0, 1, ’!’)->“!aaaaa” \
														s.insert(3, 2, ’@’)->“!aa@@aaa”
template<typename T>
void MyString<T>::insert(int index, int count, char simbol)
{
	T* new_elems = new T[this->count + count];
	memcpy(new_elems, elems, index);
	for (int i = 0; i < count; ++i)
		new_elems[index + i] = simbol;
	memcpy(new_elems + (index + count) * sizeof(T), elems + index * sizeof(T), this->count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count += count;
}

// insert null-terminated char string at index position\
														s = “aaaaa” \
														s.insert(1, ”@@@@@”)->“a@@@@@aaaa”
template<typename T>
void MyString<T>::insert(int index, char * str)
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// insert
	T* new_elems = new T[count + l_count];
	memcpy(new_elems, elems, index);
	memcpy(new_elems + index * sizeof(T), str, l_count);
	memcpy(new_elems + (index + l_count) * sizeof(T), elems + index * sizeof(T), count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count += l_count;
}

// insert count of null-terminated char string at index position \
														s = “aaaaa” \
														s.insert(1, ”@@@@@”, 2)->“a@@aaaa”
template<typename T>
void MyString<T>::insert(int index, char * str, int l_count)
{
	T* new_elems = new T[count + l_count];
	memcpy(new_elems, elems, index);
	memcpy(new_elems + index * sizeof(T), str, l_count);
	memcpy(new_elems + (index + l_count) * sizeof(T), elems + index * sizeof(T), count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count += l_count;
}

// insert std::string at index position \
														s = “aaaaa” \
														string = “@@@@@” \
														s.insert(1, std::string(“@@@@@”))->“a@@@@@aaaa”
template<typename T>
void MyString<T>::insert(int index, std::string str)
{
	T* new_elems = new T[count + str.length()];
	memcpy(new_elems, elems, index);
	memcpy(new_elems + index * sizeof(T), str.c_str(), str.length());
	memcpy(new_elems + (index + str.length()) * sizeof(T), elems + index * sizeof(T), count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count += str.length();
}

// insert count of std::string at index position \
														s = “aaaaa” \
														s.insert(1, std::string(“@@@@@”)), 2)->“a@@aaaa”
template<typename T>
void MyString<T>::insert(int index, std::string str, int l_count)
{
	T* new_elems = new T[count + l_count];
	memcpy(new_elems, elems, index);
	memcpy(new_elems + index * sizeof(T), str.c_str(), l_count);
	memcpy(new_elems + (index + l_count) * sizeof(T), elems + index * sizeof(T), count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count += l_count;
}

// erase count of char at index position \
														s = “aa@@@@@aaa” \
														s.erase(2, 3)->“a@@aaaa”
template<typename T>
void MyString<T>::erase(int index, int l_count)
{
	T* new_elems = new T[count - l_count];
	memcpy(new_elems, elems, index);
	memcpy(new_elems + index * sizeof(T), elems + (index + l_count) * sizeof(T), count - index);
	T* old_elems = elems;
	elems = new_elems;
	delete[] old_elems;
	this->count -= l_count;
}

// append count of char \
														str.clear()->“” \
														str.append(3, ’!’)->“!!!” \
														str.append(3, ’@’)->“!!!@@@”
template<typename T>
void MyString<T>::append(int count, char simbol)
{
	insert(this->count, count, simbol);
}

// append null-terminated char string \
														str.clear()->“” \
														str.append(“hello ”)->“hello ” \
														str.append(“world”)->“hello world”
template<typename T>
void MyString<T>::append(char * str)
{
	insert(count, str);
}

// append a count of null-terminated char string by index position \
														str.clear()->“” \
														str.append(“hello world”, 0, 6)->“hello ” \
														str.append(“hello world”, 6, 5)->“hello world”
template<typename T>
void MyString<T>::append(char * str, int index, int count)
{
	insert(this->count, str + index, count);
}

// append std:: string \
														str.clear()->“” \
														str.append(std::string(“hello ”))->“hello ” \
														str.append(std::string(“world”))->“hello world”
template<typename T>
void MyString<T>::append(std::string str)
{
	insert(count, str);
}

// append a count of std:: string by index position \
														str.clear()->“” \
														str.append(std::string(“hello world”), 0, 6)->“hello ” \
														str.append(std::string(“hello world”), 6, 5)->“hello world”
template<typename T>
void MyString<T>::append(std::string str, int index, int count)
{
	insert(this->count, str.c_str() + index, count);
}

// replace a count of char at index by char *str \
														s = “hello amazing world” \
														s.replace(6, 7, ”wonderful”)->“hello wonderful world”
template<typename T>
void MyString<T>::replace(int index, int count, char * str)
{
	erase(index, count);
	insert(index, str);
}

// replace a count of char at index by std::string \
														s = “hello amazing world” \
														s.replace(6, 7, std::string(”wonderful”))->“hello wonderful world”
template<typename T>
void MyString<T>::replace(int index, int count, std::string str)
{
	erase(index, count);
	insert(index, str);
}

//return a substring starts with index position \
														s = “hello amazing world” \
														s.substr(6)->“amazing world”
template<typename T>
const char * MyString<T>::substr(int index)
{
	return substr(index, this->count - index);
}

// return a count of substring’s char starts with index position \
														s = “hello amazing world” \
														s.substr(6, 7)->“amazing”
template<typename T>
const char * MyString<T>::substr(int index, int count)
{
	if (!c_str_elems)
	{
		c_str_elems = new char[count + 1];
		memcpy(c_str_elems, elems + index, count);
		c_str_elems[count] = '\0';
	}
	else
	{
		delete[] c_str_elems;
		c_str_elems = NULL;
		return substr(index, count);
	}
	return c_str_elems;
}

// if founded return the index of substring
template<typename T>
int MyString<T>::find(char * str) const
{
	return find(str, 0);
}

// if founded return the index of substring; search starts from index position
template<typename T>
int MyString<T>::find(char * str, int index) const
{
	// determine str size
	int l_count = 0;
	for (int i = 0; ; ++i)
	{
		if (str[i] != 0) l_count++;
		else break;
	}
	// find
	for (int i = index; i <= count - l_count; i++)
	{
		if (!strncmp(elems + i, str, l_count))
			return i;
	}
	return -1;
}

// if founded return the index of substring
template<typename T>
int MyString<T>::find(std::string str) const
{
	return find(const_cast<char *>(str.c_str()));
}

// if founded return the index of substring; search starts from index position
template<typename T>
int MyString<T>::find(std::string str, int index) const
{
	return find(const_cast<char *>(str.c_str()), index);
}

template<typename T>
std::ostream & operator << (std::ostream & s, MyString<T>& str)
{
	s << str.c_str();
	return s;
}