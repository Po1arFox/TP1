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

	virtual void add_book(string) = 0;
	virtual void delete_book() = 0;
public:
	virtual string get_fullname() = 0;
	virtual string* get_name_books() = 0;
	virtual int get_number_of_books() = 0;

	virtual void set_fullname(string fullname) = 0;
	virtual void set_name_books(string* name_books) = 0;
	virtual void set_number_of_books(int new_nob) = 0;

	virtual void set_book(string, int old_book_id) = 0;
};