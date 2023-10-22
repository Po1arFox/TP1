#include "Writer.h"
class Novelist : public Writer
{
private:
	int year_of_birth;
	int year_of_death;
	string biography;
public:
	Novelist();
	Novelist(string fullname, int year_of_birth, int year_of_death, string* name_books, int nob, string biography);// конструктор с парам-ми
	Novelist(const Novelist& ref_Novelist); // конструктор копирования
	~Novelist();

	string get_fullname() override;
	int get_years_of_birth();
	int get_years_of_death();
	string get_biography();
	string* get_name_books() override;
	int get_number_of_books()override;

	void set_fullname(string fullname)override;
	void set_years_of_birth(int year_of_birth);
	void set_years_of_death(int year_of_death);

	void set_biography(string biography);

	void add_book(string)override;
	void delete_book()override;
};

