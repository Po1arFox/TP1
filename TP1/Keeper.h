#pragma once
#include <iostream>
#include <fstream>
#include "Poet.h"
#include "novelist.h"
#include "fantast.h"
#include <sstream>    

/*Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writer
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/

class Keeper
{
private:
	int size_p;
	int size_n;
	int size_f;
	Poet* p;
	Novelist* n;
	Fantast* f;

	string* split(string str, char ch);
	bool have_word(string s);

public:
	void check_p_id(int id);
	void check_n_id(int id);
	void check_f_id(int id);

	//конструкторы
	Keeper();
	Keeper(int size_p, int size_n, int size_f, Poet* p, Novelist* n, Fantast* f);
	Keeper(const Keeper&);
	~Keeper();

	//void add_poet(const Poet &new_p);
	void add_poet(string fullname, int year_of_birth, int year_of_death, string* books, int size_b);
	void delete_poet(int id);

	void add_novelist(string fullname, int year_of_birth, int year_of_death, string* books, int size_b, string biography);
	void delete_novelist(int id);

	void add_fantast(string fullname, string* books, int size_b, bool IF);
	void delete_fantast(int id);


	//template <typename T>
	//void add(T newT) { if (std::is_same<T, Poet>::value) p[size_p++] = newT; }

	int get_size();

	Poet get_poet(int id);
	Novelist get_novelist(int id);
	Fantast get_fantast(int id);
	//вывод 
	void print_poet();// все поэты
	void print_poet(int id); // поэты по id

	void print_novelist();
	void print_novelist(int id);

	void print_fantast();
	void print_fantast(int id);

	void print_all();

	void ch_p_fio(int id, string fullname);
	void ch_p_yob(int id, int year_of_birth);
	void ch_p_yod(int id, int year_of_death);

	void ch_n_fio(int id, string fullname);
	void ch_n_yob(int id, int year_of_birth);
	void ch_n_yod(int id, int year_of_death);
	void ch_n_bio(int id, string bio);

	void ch_f_fio(int id, string fullname);


	//добавление и удаление книг
	void add_book_poet(string, int id);
	void delete_book_poet(int);

	void add_book_novelist(string, int id);
	void delete_book_novelist(int id);

	void add_book_fantast(string, int id);
	void delete_book_fantast(int id);


	//сохранение и чтение файла
	void Save();
	void Read();
};