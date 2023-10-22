#include "Fantast.h"

Fantast::Fantast()
{
	this->fullname = "NULL";
	this->name_books = new string[0];
	this->number_of_books = 0;
	this->isFilmed = NULL;
}

Fantast::Fantast(string fullname, string* name_books, int nob, bool isFilmed)
{
	this->fullname = fullname;
	this->name_books = name_books;
	this->number_of_books = nob;
	this->isFilmed = isFilmed;
}

Fantast::Fantast(const Fantast& ref_Fantast)
{
	fullname = ref_Fantast.fullname;
	name_books = ref_Fantast.name_books;
	number_of_books = ref_Fantast.number_of_books;
	isFilmed = ref_Fantast.isFilmed;
}

Fantast::~Fantast()
{
	delete[] name_books;
	cout << "Вызван деструктор ~Fantast" << endl;
}

string Fantast::get_fullname()
{
	return Writer::get_fullname();
}

string* Fantast::get_name_books()
{
	return Writer::get_name_books();
}

void Fantast::set_fullname(string fullname)
{
	Writer::set_fullname(fullname);
}

void Fantast::set_isFilmed(bool isFilmed)
{
	this->isFilmed = isFilmed;
}

void Fantast::add_book(string new_book)
{
	Writer::add_book(new_book);
}

void Fantast::delete_book()
{
	Writer::delete_book();
}

int Fantast::get_number_of_books()
{
	return Writer::get_number_of_books();
}

bool Fantast::get_isFilmed()
{
	return this->isFilmed;
}

