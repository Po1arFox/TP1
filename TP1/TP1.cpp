#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <codecvt>
#include "Keeper.h"

using namespace std;

Keeper k;

const string RED = "\033[31m";
const string RESET_COLOR = "\033[0m";
const string GREEN = "\033[32m";

void pause()
{
	std::system("pause");
}

void clear()
{
	system("cls");
}

string readLine()
{
	string result;

	while (result.empty()) {
		getline(cin, result);
	}

	return result;
}

void printMenu(string* menuItems, int itemCount) {
	clear();
	cout << 0 << ". " << "Выйти" << endl;

	for (int i = 0; i < itemCount; i++)
		cout << i + 1 << ". " << menuItems[i] << endl;
}

namespace AddRemoveWriter
{
	void add_a_poet()
	{
		int year_of_birth, year_of_death;
		string fullname;
		string* books = new string[1];

		cout << "Введите ФИО поэта*: ";
		fullname = readLine();
		cout << "Год рождения поэта*: ";
		cin >> year_of_birth;
		cout << "Год смерти поэта*: ";
		cin >> year_of_death;
		cout << "Название одного произведения: ";
		books[0] = readLine();

		k.add_poet(fullname, year_of_birth, year_of_death, books, 1);
	}
	void delete_a_poet()
	{
		cout << "Введите id поэта для удаления: ";
		int id;
		cin >> id;
		try
		{
			cout << GREEN;
			k.delete_poet(id);
			cout << RESET_COLOR << "Поэт удален";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void add_a_novelist()
	{
		string fullname;
		int year_of_birth, year_of_death; string yob, yod;
		string* books = new string[1];
		string biography;

		cout << "Введите ФИО романиста*: ";
		fullname = readLine();
		cout << "Год рождения романиста*: ";
		cin >> year_of_birth;
		cout << "Год смерти романиста*: ";
		cin >> year_of_death;
		cout << "Название одного произведения: ";
		books[0] = readLine();
		cout << "Краткая биография романиста*: ";
		biography = readLine();

		k.add_novelist(fullname, year_of_birth, year_of_death, books, 1, biography);
	}
	void delete_a_novelist()
	{
		cout << "Введите id романиста для удаления: ";
		int id;
		cin >> id;

		try
		{
			cout << GREEN;
			k.delete_novelist(id);
			cout << RESET_COLOR << "Новелист удален";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void add_a_fantast()
	{
		string fullname;
		string* books = new string[1];
		int isFilmed;

		cout << "Введите ФИО романиста*: ";
		fullname = readLine();
		cout << "Название одного произведения: ";
		books[0] = readLine();
		cout << "1 - если снят фильм, 0 если не снят: ";
		cin >> isFilmed;

		k.add_fantast(fullname, books, 1, isFilmed);
	}
	void delete_a_fantast()
	{
		cout << "Введите id фантаста для удаления: ";
		int id;
		cin >> id;
		try
		{
			cout << GREEN;
			k.delete_fantast(id);
			cout << RESET_COLOR << "Фантаст удален";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void menu()
	{
		std::string menuItems[] = {
			"Добавить поэта",
			"Добавить романиста",
			"Добавить фантаста",
			"Удалить поэта",
			"Удалить романиста",
			"Удалить фантаста"
		};
		int choise;
		while (true)
		{
			printMenu(menuItems, 6);

			cin >> choise;

			switch (choise)
			{
			case 0:
				return;
			case 1:
				add_a_poet();
				break;
			case 2:
				add_a_novelist();
				break;
			case 3:
				add_a_fantast();
				break;
			case 4:
				delete_a_poet();
				break;
			case 5:
				delete_a_novelist();
				break;
			case 6:
				delete_a_fantast();
				break;
			}
			pause();
		}
	}
}

namespace AddRemoveBook
{
	void add_book_poet()
	{
		string new_book; string idStr; int id;
		cout << "Введите название книги: ";
		new_book = readLine();
		cout << "Введите id поэта: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.add_book_poet(new_book, id);
			cout << RESET_COLOR << "Книга " << new_book << " добавлена к поэту с id - " << id;
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}
	void delete_book_poet()
	{
		int id;
		cout << "Введите id поэта последнюю книгу которого нужно удалить" << endl;
		cin >> id;

		try
		{
			cout << GREEN;
			k.delete_book_poet(id);
			cout << RESET_COLOR << "Книга поэта с id - " << id << " удалена";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void add_book_novelist()
	{
		string new_book;
		int id;
		cout << "Введите название книги: ";
		new_book = readLine();
		cout << "Введите id романиста: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.add_book_novelist(new_book, id);
			cout << RESET_COLOR << "Книга " << new_book << " добавлена к поэту с id - " << id;
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void delete_book_novelist()
	{
		int id;
		cout << "Введите id романиста последнюю книгу которого нужно удалить" << endl;
		cin >> id;
		try
		{
			cout << GREEN;
			k.delete_book_novelist(id);
			cout << RESET_COLOR << "Книга романиста с id - " << id << " удалена";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void add_book_fantast()
	{
		string new_book;
		int id;
		cout << "Введите название книги: ";
		new_book = readLine();
		cout << "Введите id романиста: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.add_book_fantast(new_book, id);
			cout << RESET_COLOR << "Книга " << new_book << " добавлена к фантасту с id - " << id;
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void delete_book_fantast()
	{
		int id;
		cout << "Введите id фантаста последнюю книгу которого нужно удалить" << endl;
		cin >> id;
		try
		{
			cout << GREEN;
			k.delete_book_fantast(id);
			cout << RESET_COLOR << "Книга фантаста с id - " << id << " удалена";
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void menu()
	{
		string menuItems[] = {
			"Добавить книгу поэту",
			"Добавить книгу романисту",
			"Добавить книгу фантасту",
			"Удалить книгу поэту",
			"Удалить книгу романисту",
			"Удалить книгу фантасту"
		};
		int choise;

		while (true)
		{
			printMenu(menuItems, 6);

			cin >> choise;

			switch (choise) {
			case 0: //Назад
				return;
			case 1: //Добавить книгу поэта
				add_book_poet();
				break;
			case 2: //Добавить книгу романиста
				add_book_novelist();
				break;
			case 3: //Добавить книгу фантаста
				add_book_fantast();
				break;
			case 4: //Удалить книгу поэта
				delete_book_poet();
				break;
			case 5: //Удалить книгу романиста
				delete_book_novelist();
				break;
			case 6: //Удалить книгу фантаста
				delete_book_fantast();
				break;
			}
			pause();
		}
	}
}

namespace OutputWriters
{
	void output_poet_by_id()
	{
		int id;
		cout << "Введите id поэта: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.print_poet(id);
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void output_novelist_by_id()
	{
		int id;
		cout << "Введите id романиста: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.print_novelist(id);
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void output_fantast_by_id()
	{
		int id;
		cout << "Введите id поэта: ";
		cin >> id;

		try
		{
			cout << GREEN;
			k.print_fantast(id);
		}
		catch (exception e)
		{
			cout << RED << e.what() << RESET_COLOR << endl;
		}
	}

	void menu()
	{
		string menuItems[] = {
	"Вывод поэта по id",
	"Вывод романиста по id",
	"Вывод фантаста по id",
	"Вывод всех поэтов",
	"Вывод всех романистов",
	"Вывод всех фантастов",
	"Вывод всех писателей"
		};

		int choise;

		while (true)
		{
			printMenu(menuItems, 7);

			cin >> choise;

			switch (choise) {
			case 0: //Назад
				return;
			case 1:
				output_poet_by_id();
				break;
			case 2:
				output_novelist_by_id();
				break;
			case 3:
				output_fantast_by_id();
				break;
			case 4:
				k.print_poet();
				break;
			case 5: //Удалить книгу романиста
				k.print_novelist();
				break;
			case 6: //Удалить книгу фантаста
				k.print_fantast();
				break;
			case 7:
				k.print_all();
				break;
			}
			pause();
		}
	}
}

namespace ChangeData
{
	void change_p(int id)
	{
		string menuItems[] = {
			"Изменить ФИО поэта",
			"Изменить дату рождения поэта",
			"Изменить дату смерти поэта",
		};
		printMenu(menuItems, 3);

		int choise;
		cin >> choise;
		string fullname;
		int year_of_birth;
		int year_of_death;

		switch (choise) {
		case 0:
			return;
		case 1:
			cout << "Введите новое ФИО" << endl;
			fullname = readLine();
			k.ch_p_fio(id, fullname);
			cout << "Данные изменены" << endl;
			_getch();
			break;
		case 2:
			cout << "Введите новую дату рождения" << endl;
			cin >> year_of_birth;
			k.ch_p_yob(id, year_of_birth);
			cout << "Данные изменены" << endl;
			_getch();
			break;
		case 3:
			cout << "Введите новую дату смерти" << endl;
			cin >> year_of_death;
			k.ch_p_yod(id, year_of_death);
			cout << "Данные изменены" << endl;
			_getch();
			break;
		}
	}

	void change_n(int id)
	{
		string menuItems[] = {
	"Изменить ФИО романиста",
	"Изменить дату рождения романиста",
	"Изменить дату смерти романиста",
	"Изменить биографию романиста",
		};
		printMenu(menuItems, 4);
		int choise;
		string fullname, bio;
		int year_of_birth;
		int year_of_death;

		cin >> choise;
		switch (choise) {
		case 0:
			return;
		case 1:
			cout << "Введите новое ФИО" << endl;
			fullname = readLine();
			k.ch_n_fio(id, fullname);
			cout << "Данные изменены" << endl;
			break;
		case 2:
			cout << "Введите новую дату рождения" << endl;
			cin >> year_of_birth;
			k.ch_n_yob(id, year_of_birth);
			cout << "Данные изменены" << endl;
			break;
		case 3:
			cout << "Введите новую дату смерти" << endl;
			cin >> year_of_death;
			k.ch_n_yod(id, year_of_death);
			cout << "Данные изменены" << endl;
			break;
		case 5:
			cout << "Введите новую биографию для романиста" << endl;
			bio = readLine();
			k.ch_n_bio(id, bio);
			cout << "Данные изменены" << endl;
			break;
		}
	}

	void change_f(int id)
	{
		string menuItems[] = {
	"Изменить ФИО поэта",
	"Изменить дату рождения поэта",
	"Изменить дату смерти поэта",
		};
		printMenu(menuItems, 3);
		int choise;
		string fullname;
		cin >> choise;
		switch (choise) {
		case 0:
			return;
		case 1:
			cout << "Введите новое ФИО" << endl;
			fullname = readLine();
			k.ch_f_fio(id, fullname);
			cout << "Данные изменены" << endl;
			break;
		case 2:
			cout << "Введите 1 если фильм снят, если не снят - введите 0";
			int isFilmed;
			cin >> isFilmed;
			break;
		}
	}

	void menu()
	{
		string menuItems[] = {
			"Изменить данные поэта по id",
			"Изменить данные романиста по id",
			"Изменить данные фантаста по id",
		};
		int choise;

		while (true)
		{
			printMenu(menuItems, 3);

			cin >> choise;


			switch (choise) {
			case 0:
				return;
			case 1:
				cout << "Введите id поэта: ";
				int id1;
				cin >> id1;
				try {
					k.check_p_id(id1);
					change_p(id1);
				}
				catch (exception e) {
					cout << RED << e.what() << RESET_COLOR << endl;
				}
				break;
			case 2:
				cout << "Введите id романиста: ";
				int id2;
				cin >> id2;
				try {
					k.check_n_id(id2);
					change_n(id2);
				}
				catch (exception e) {
					cout << RED << e.what() << RESET_COLOR << endl;
				}
				break;
			case 3:
				cout << "Введите id фантаста: ";
				int id3;
				cin >> id3;
				try {
					k.check_f_id(id3);
					change_f(id3);
				}
				catch (exception e) {
					cout << RED << e.what() << RESET_COLOR << endl;
				}
				break;
			}
			pause();
		}
	}
}

namespace MainMenu
{
	void menu()
	{
		string menuItems[] = {
		"Добавить или удалить писателя",
		"Добавить книгу в список произведений или удалить её",
		"Вывести писателя",
		"Изменить данные",
		"Сохранить данные",
		"Прочитать данные",
		};
		int choise;
		while (true)
		{
			printMenu(menuItems, 6);

			cin >> choise;

			switch (choise)
			{
			case 0:
				return;
			case 1:
				AddRemoveWriter::menu();
				break;
			case 2:
				AddRemoveBook::menu();
				break;
			case 3:
				OutputWriters::menu();
				break;
			case 4:
				ChangeData::menu();
				break;
			case 5: //сохранить данные
				k.Save();
				cout << "Данные сохранены" << endl;
				_getch();
				break;
			case 6: // прочитать данные
				k.Read();
				cout << "Данные загруженны" << endl;
				_getch();
				break;
			}
		}
	}

}

string convert_to_rus(string line)
{
	char* result = new char[line.size()];
	for(int i = 0; i < line.size(); i++)
	{
		if(!(line[i] > 'а' && line[i] < 'я'))
			result[i] = line[i] + 64;
	}
	result[line.size()] = '\0';
	return string(result);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");	

	MainMenu::menu();

	return 0;
}
