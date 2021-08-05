#define BOOST_PYTHON_STATIC_LIB
#include "Sourñe.h"
#include <string>
#include <iostream>
#include <boost/python.hpp>
#include "MyString.h"

using namespace boost::python;

// type conversion
template< typename T >
struct type_into_python
{
	static PyObject* convert(T const&);
};
PyObject* type_into_python<char *>::convert(char * const& t)
{
	const char* src = (strlen(t) == 0) ? "" : reinterpret_cast<const char*>(&t);
	return PyBytes_FromStringAndSize(src, strlen(t));
}


template <typename T>
void TemplateFunc()
{
	class_<MyString<T>>("MyString")
		.def(init<>())
		.def(init<const MyString<T> &>())
		.def(init<std::initializer_list<T> >())
		.def(init<std::string >())
		.def(init<char *, int >())
		.def(init<int, char >())

		.def(self + self)
		.def(self + std::string())
		.def(self += self)
		.def(self += std::string())
		.def("__getitem__", static_cast< T& (MyString<T>::*)(int) const > (&MyString<T>::operator[]), args("i"), return_value_policy<return_by_value>())

		.def(self > std::string())
		.def(self > self)
		.def(self < std::string())
		.def(self < self)
		.def(self >= std::string())
		.def(self >= self)
		.def(self <= std::string())
		.def(self <= self)
		.def(self == std::string())
		.def(self == self)
		.def(self != std::string())
		.def(self != self)

		.def("c_str", &MyString<T>::c_str)
		.def("data", &MyString<T>::data, return_value_policy<return_by_value>())
		.def("length", &MyString<T>::length)
		.def("size", &MyString<T>::size)
		.def("empty", &MyString<T>::empty)
		.def("capacity", &MyString<T>::capacity)
		//.def("shrink_to_fit", &MyString<T>::shrink_to_fit)
		.def("clear", &MyString<T>::clear)

		.def("insert", static_cast< void (MyString<T>::*)(int, int, char) > (&MyString<T>::insert), args("index", "count", "symbol"))
		.def("insert", static_cast< void (MyString<T>::*)(int, std::string) > (&MyString<T>::insert), args("index", "str"))
		.def("insert", static_cast< void (MyString<T>::*)(int, std::string, int) > (&MyString<T>::insert), args("index", "str", "l_count"))
		.def("erase", &MyString<T>::erase, args("index", "l_count"))
		.def("append", static_cast< void (MyString<T>::*)(int, char) > (&MyString<T>::append), args("count", "symbol"))
		.def("append", static_cast< void (MyString<T>::*)(std::string) > (&MyString<T>::append), args("str"))
		.def("append", static_cast< void (MyString<T>::*)(std::string, int, int) > (&MyString<T>::append), args("str", "index", "count"))
		.def("replace", static_cast< void (MyString<T>::*)(int, int, std::string) > (&MyString<T>::replace), args("index", "count", "str"))
		.def("substr", static_cast< const char * (MyString<T>::*)(int) > (&MyString<T>::substr), args("index"), return_value_policy<return_by_value>())
		.def("substr", static_cast< const char * (MyString<T>::*)(int, int) > (&MyString<T>::substr), args("index", "xount"), return_value_policy<return_by_value>())
		.def("find", static_cast< int (MyString<T>::*)(std::string) const > (&MyString<T>::find), args("str"))
		.def("find", static_cast< int (MyString<T>::*)(std::string, int) const> (&MyString<T>::find), args("str", "index"))
		
		;

}

BOOST_PYTHON_MODULE(MyPyLib)
{
	to_python_converter< char *, type_into_python<char *> >();
	TemplateFunc<char>();
}
