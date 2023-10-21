#pragma once
#include <iostream>
#include <string>

using namespace std;

class Writer
{
protected:
	string fullname;
	string* name_books;
	int number_of_books;

	virtual void add_book(string book);
	virtual void delete_book();
public:
	virtual string get_fullname();
	virtual string* get_name_books();
	virtual int get_number_of_books();

	virtual void set_fullname(string fullname);
};