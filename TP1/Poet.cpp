#include "Poet.h"

Poet::Poet()
{
	this->fullname = "NULL";
	this->year_of_birth = NULL;
	this->year_of_death = NULL;
	this->name_books = new string[0];
	this->number_of_books = 0;
}

Poet::Poet(string fullname, int year_of_birth, int year_of_death, string* name_books, int nob)
{
	this->fullname = fullname;
	this->year_of_birth = year_of_birth;
	this->year_of_death = year_of_death;
	this->name_books = name_books;
	this->number_of_books = nob;
}

Poet::Poet(const Poet& ref_Poet)
{
	fullname = ref_Poet.fullname;
	year_of_birth = ref_Poet.year_of_birth;
	year_of_death = ref_Poet.year_of_death;
	name_books = ref_Poet.name_books;
	number_of_books = ref_Poet.number_of_books;
}

Poet::~Poet()
{
	delete[] name_books;
}

string Poet::get_fullname()
{
	return Writer::get_fullname();
}

int Poet::get_years_of_birth()
{
	return year_of_birth;
}

int Poet::get_years_of_death()
{
	return year_of_death;
}

string* Poet::get_name_books()
{
	return Writer::get_name_books();
}

void Poet::set_fullname(string fullname)
{
	Writer::set_fullname(fullname);
}

void Poet::set_years_of_birth(int year_of_birth)
{
	this->year_of_birth = year_of_birth;
}

void Poet::set_years_of_death(int year_of_death)
{
	this->year_of_death = year_of_death;
}

void Poet::add_book(string new_book)
{
	Writer::add_book(new_book);
}

void Poet::delete_book()
{
	Writer::delete_book();
}

int Poet::get_number_of_books()
{
	return Writer::get_number_of_books();
}

