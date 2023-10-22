#include "Writer.h"

void Writer::add_book(string book)
{
	number_of_books++;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books - 1; i++) {
		new_books[i] = name_books[i];
	}
	new_books[number_of_books - 1] = book;
	name_books = new_books;
}

void Writer::delete_book()
{
	number_of_books--;
	string* new_books = new string[number_of_books];
	for (int i = 0; i < number_of_books; i++) {
		new_books[i] = name_books[i];
	}
	delete[] name_books;
	name_books = new_books;
}


string Writer::get_fullname()
{
	return fullname;
}

string* Writer::get_name_books()
{
	return name_books;
}

int Writer::get_number_of_books()
{
	return number_of_books;
}

void Writer::set_fullname(string fullname)
{
	this->fullname = fullname;
}


