#include "Writer.h"
class Poet : public Writer
{
private:
	//годы жизни
	int year_of_birth;
	int year_of_death;
public:
	Poet();
	Poet(string fullname, int year_of_birth, int year_of_death, string* name_books, int nob);// конструктор с парам-ми
	Poet(const Poet& ref_Poet); // конструктор копирования
	~Poet();

	string get_fullname() override;
	int get_years_of_birth();
	int get_years_of_death();
	string* get_name_books() override;
	int get_number_of_books()override;

	void set_fullname(string fullname)override;
	void set_years_of_birth(int year_of_birth);
	void set_years_of_death(int year_of_death);

	//изменение данных
	void add_book(string book)override;
	void delete_book()override;
};

