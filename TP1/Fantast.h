#include "Writer.h"
class Fantast : public Writer
{
private:
	bool isFilmed;
public:
	Fantast();
	Fantast(string fullname, string* name_books, int nob, bool isFilmed);// конструктор с парам-ми
	Fantast(const Fantast& ref_Fantast); // конструктор копирования
	~Fantast();

	string get_fullname() override;
	string* get_name_books() override;
	int get_number_of_books()override;

	bool get_isFilmed();

	void set_fullname(string fullname)override;

	void set_isFilmed(bool isFilmed);

	//изменение данных
	void add_book(string)override;
	void delete_book()override;
};

