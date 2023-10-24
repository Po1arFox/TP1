#include "Keeper.h"


void removeFirstElement(string*& arr, int size) {
	if (size <= 1) {
		// Если размер массива меньше или равен 1, нет необходимости в удалении.
		return;
	}

	// Создаем новый массив на один элемент меньше
	string* newArr = new string[size - 1];

	// Копируем строки, начиная с второй (индекс 1)
	for (int i = 1; i < size; i++) {
		newArr[i - 1] = arr[i];
	}

	// Удаляем старый массив и обновляем указатель
	delete[] arr;
	arr = newArr;

	// Уменьшаем размер на 1
	size--;
}

Keeper::Keeper()
{
	this->size_p = 0;
	this->size_n = 0;
	this->size_f = 0;
	p = new Poet[1];
	n = new Novelist[1];
	f = new Fantast[1];
}

Keeper::Keeper(int size_p, int size_n, int size_f, Poet* p, Novelist* n, Fantast* f)
{
	this->size_p = size_p;
	this->size_n = size_n;
	this->size_f = size_f;
	this->p = p;
	this->n = n;
	this->f = f;
}

Keeper::Keeper(const Keeper& ref_k)
{
	this->size_p = ref_k.size_p;
	this->size_n = ref_k.size_n;
	this->size_f = ref_k.size_f;
	this->p = ref_k.p;
	this->n = ref_k.n;
	this->f = ref_k.f;
}

Keeper::~Keeper()
{
	delete[] p;
	delete[] n;
	delete[] f;
}

int Keeper::get_size()
{
	return size_p + size_n + size_f;
}

void Keeper::add_poet(string fullname, int year_of_birth, int year_of_death, string* books, int size_b)
{
	size_p++;
	Poet* new_poets = new Poet[size_p];
	for (int i = 0; i < size_p - 1; i++) {
		new_poets[i] = p[i];
	}
	new_poets[size_p - 1].set_fullname(fullname);
	new_poets[size_p - 1].set_years_of_birth(year_of_birth);
	new_poets[size_p - 1].set_years_of_death(year_of_death);
	for (int i = 0; i < size_b; i++)
		new_poets[size_p - 1].add_book(books[i]);

	p = new_poets;
}

void Keeper::delete_poet(int id)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	if (size_p <= 0) throw exception("Не записано ни одного поэта");
	Poet* new_poets = new Poet[size_p - 1];
	for (int i = 0, k = 0; i < size_p, k < size_p - 1; i++) {
		if (i == id) continue;
		new_poets[k] = p[i];
		k++;
	}
	p = new_poets;
	size_p--;
}

void Keeper::add_novelist(string fullname, int year_of_birth, int year_of_death, string* books, int size_b, string biography)
{
	size_n++;
	Novelist* new_novelists = new Novelist[size_n];
	for (int i = 0; i < size_n - 1; i++) {
		new_novelists[i] = n[i];
	}
	new_novelists[size_n - 1].set_fullname(fullname);
	new_novelists[size_n - 1].set_years_of_birth(year_of_birth);
	new_novelists[size_n - 1].set_years_of_death(year_of_death);
	new_novelists[size_n - 1].set_biography(biography);
	for (int i = 0; i < size_b; i++)
		new_novelists[size_n - 1].add_book(books[i]);

	n = new_novelists;
}

void Keeper::delete_novelist(int id)
{
	if (id >= size_n) throw exception("Романиста с данным id не обнаружено");
	if (size_n <= 0) throw exception("Не записано ни одного романиста");
	Novelist* new_novelists = new Novelist[size_n - 1];
	int k = 0;
	for (int i = 0; i < size_n; i++) {
		if (i == id) continue;
		new_novelists[k] = n[i];
		k++;
	}
	n = new_novelists;
	size_n--;
}

void Keeper::add_fantast(string fullname, string* books, int size_b, bool IF)
{
	size_f++;
	Fantast* new_fantast = new Fantast[size_f];
	for (int i = 0; i < size_f - 1; i++) {
		new_fantast[i] = f[i];
	}
	new_fantast[size_f - 1].set_fullname(fullname);
	new_fantast[size_f - 1].set_isFilmed(IF);
	for (int i = 0; i < size_f; i++)
		new_fantast[size_f - 1].add_book(books[i]);

	f = new_fantast;
}

void Keeper::delete_fantast(int id)
{
	if (id >= size_f) throw exception("Фантаста с данным id не обнаружено");
	if (size_f <= 0) throw exception("Не записано ни одного фантаста");
	Fantast* new_fantast = new Fantast[size_f - 1];
	int k = 0;
	for (int i = 0; i < size_f; i++) {
		if (i == id) continue;
		new_fantast[k] = f[i];
		k++;
	}

	f = new_fantast;
	size_f--;
}

Poet Keeper::get_poet(int id)
{
	if (id >= size_p) { return p[0]; }
	return p[id];
}

Novelist Keeper::get_novelist(int id)
{
	if (id >= size_n) { return n[0]; }
	return n[id];
}

Fantast Keeper::get_fantast(int id)
{
	if (id >= size_f) { return f[0]; }
	return f[id];
}


void Keeper::Save()
{
	ofstream out;          // поток для записи
	out.open("data.txt");  // окрываем файл для записи
	bool firstIteration = true;   // проверка на первую строку в сохранение (избежание первого \n)
	if (out.is_open())
	{
		//записываем поэтов
		for (int i = 0; i < size_p; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";

			out << "Poet" << endl;
			out << p[i].get_fullname() << endl;
			out << p[i].get_years_of_birth() << endl;
			out << p[i].get_years_of_death() << endl;

			//записываем количество книг
			out << p[i].get_number_of_books();
			for (int j = 0; j < p[i].get_number_of_books(); j++) {
				out << ";" << p[i].get_name_books()[j];
			}
		}
		//записываем новелистов
		for (int i = 0; i < size_n; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Novelist" << endl;
			out << n[i].get_fullname() << endl;
			out << n[i].get_years_of_birth() << endl;
			out << n[i].get_years_of_death() << endl;

			//записываем количество книг
			out << n[i].get_number_of_books();
			for (int j = 0; j < n[i].get_number_of_books(); j++) {
				out << ";" << n[i].get_name_books()[j];
			}
			out << '\n' << n[i].get_biography();
		}
		// записываем фантастов
		for (int i = 0; i < size_f; i++) {
			if (firstIteration == true) firstIteration = false;
			else out << "\n";
			out << "Fantast" << endl;
			out << f[i].get_fullname() << endl;
			//записываем количество книг
			out << f[i].get_number_of_books();
			for (int j = 0; j < f[i].get_number_of_books(); j++) {
				out << ";" << f[i].get_name_books()[j];
			}
			out << '\n' << f[i].get_isFilmed();
		}
	}
	out.close();
}

void Keeper::Read()
{
	string fn;//новое ФИО
	int yob;//года
	int yod;//года
	string new_name_of_book;
	ifstream in("data.txt");
	if (in.is_open())
	{
		while (!in.eof()) {
			string c;
			getline(in, c);
			if (c == "Poet") {
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				removeFirstElement(new_books, size_books + 1);
				//присваиваем новые значения
				add_poet(fn, yob, yod, new_books, size_books);
			}
			else if (c == "Novelist") {
				getline(in, fn);
				in >> yob;
				in >> yod;
				getline(in, new_name_of_book);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				removeFirstElement(new_books, size_books + 1);
				string bio; getline(in, bio);
				//присваиваем новые значения
				add_novelist(fn, yob, yod, new_books, size_books, bio);
			}
			else if (c == "Fantast") {
				getline(in, fn);
				getline(in, new_name_of_book);
				string* new_books = split(new_name_of_book, ';');
				int size_books = stoi(new_books[0]);
				removeFirstElement(new_books, size_books + 1);
				bool isFilmed; in >> isFilmed;

				//присваиваем новые значения
				add_fantast(fn, new_books, size_books, isFilmed);
			}
		}
	}
	in.close(); // закрываем файл
}

void Keeper::print_poet()
{
	for (int i = 0; i < size_p; i++) {
		cout << "\nПоэт " << i + 1 << ": " << endl;
		print_poet(i);
	}
}

void Keeper::print_poet(int id)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	cout << "ФИО: " << p[id].get_fullname() << endl;
	cout << "Годы жизни: " << p[id].get_years_of_birth() << " - " << p[id].get_years_of_death() << endl;
	if (p[id].get_number_of_books() == 0)
	{
		cout << "Нет книг" << endl;
	}
	else {
		for (int i = 0; i < p[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << p[id].get_name_books()[i] << endl;
		}
	}
}

void Keeper::ch_p_fio(int id, string fullname)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	p[id].set_fullname(fullname);
}

void Keeper::ch_n_fio(int id, string fullname)
{
	if (id >= size_n) throw exception("Романист с данным id не обнаружено");
	n[id].set_fullname(fullname);
}

void Keeper::ch_f_fio(int id, string fullname)
{
	if (id >= size_f) throw exception("Фантаст с данным id не обнаружено");
	f[id].set_fullname(fullname);
}

void Keeper::ch_p_yob(int id, int year_of_birth)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	p[id].set_years_of_birth(year_of_birth);
}

void Keeper::ch_n_yob(int id, int year_of_birth)
{
	if (id >= size_n) throw exception("Романист с данным id не обнаружено");
	n[id].set_years_of_birth(year_of_birth);
}

void Keeper::ch_p_yod(int id, int year_of_death)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	p[id].set_years_of_death(year_of_death);
}

void Keeper::ch_n_yod(int id, int year_of_death)
{
	if (id >= size_n) throw exception("Романист с данным id не обнаружено");
	n[id].set_years_of_death(year_of_death);
}

void Keeper::ch_n_bio(int id, string bio)
{
	if (id >= size_n) throw exception("Романист с данным id не обнаружено");
	n[id].set_biography(bio);
}



void Keeper::print_novelist()
{
	for (int i = 0; i < size_n; i++) {
		cout << "\nРоманист " << i + 1 << ": " << endl;
		print_novelist(i);
	}
}

void Keeper::print_novelist(int id)
{
	if (id >= size_n) throw exception("Романиста с данным id не обнаружено");
	cout << "ФИО: " << n[id].get_fullname() << endl;
	cout << "Годы жизни: " << n[id].get_years_of_birth() << " - " << n[id].get_years_of_death() << endl;
	if (n[id].get_number_of_books() == 0) { cout << "Нет книг" << endl; }
	else if (!have_word(n[0].get_name_books()[0])) {
		for (int i = 1; i <= n[id].get_number_of_books(); i++) {
			cout << "Книга " << i << ": ";
			cout << n[id].get_name_books()[i] << endl;
		}
	}
	else {
		for (int i = 0; i < n[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << n[id].get_name_books()[i] << endl;
		}
	}
	cout << "Краткая биография: " << n[id].get_biography() << endl;
}

void Keeper::print_fantast()
{
	for (int i = 0; i < size_f; i++) {
		cout << "\nФантаст " << i + 1 << ": " << endl;
		print_fantast(i);
	}
}

void Keeper::print_fantast(int id)
{
	if (id >= size_f) throw exception("Фантаст с данным id не обнаружено");
	cout << "ФИО: " << f[id].get_fullname() << endl;
	if (f[id].get_number_of_books() == 0) { cout << "Нет книг" << endl; }

	else {
		for (int i = 0; i < f[id].get_number_of_books(); i++) {
			cout << "Книга " << i + 1 << ": ";
			cout << f[id].get_name_books()[i] << endl;
		}
	}
	f[id].get_isFilmed() ? cout << "Снят по крайней мере 1 фильм" : cout << "Не снимались фильмы";
	cout << endl;
}

void Keeper::print_all()
{
	print_poet();
	print_novelist();
	print_fantast();
}

void Keeper::add_book_poet(string book, int id)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	p[id].add_book(book);
}

void Keeper::delete_book_poet(int id)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
	if (p[id].get_number_of_books() == 0) throw exception("У данного поэта нет книг");
	else p[id].delete_book();
}

void Keeper::add_book_novelist(string book, int id)
{
	if (id >= size_n) throw exception("Романиста с данным id не обнаружено");
	n[id].add_book(book);
}

void Keeper::delete_book_novelist(int id)
{
	if (id >= size_n) throw exception("Романиста с данным id не обнаружено");
	if (p[id].get_number_of_books() == 0) throw exception("У данного романиста нет книг");
	else n[id].delete_book();
}

void Keeper::add_book_fantast(string book, int id)
{
	if (id >= size_f) throw exception("Фантаста с данным id не обнаружено");
	f[id].add_book(book);
}

void Keeper::delete_book_fantast(int id)
{
	if (id >= size_f) throw exception("Фантаста с данным id не обнаружено");
	if (p[id].get_number_of_books() == 0) throw exception("У данного фантаста нет книг");
	else f[id].delete_book();
}
string* Keeper::split(string str, char ch)
{
	int count = 1; // Изначально предполагаем, что есть хотя бы одна подстрока
	for (char c : str) {
		if (c == ch) {
			count++;
		}
	}

	string* result = new string[count];
	int partIndex = 0;

	for (char c : str) {
		if (c != ch) {
			result[partIndex] += c;
		}
		else {
			partIndex++;
		}
	}

	return result;
}

bool Keeper::have_word(string s)
{
	for (int i = 0; i < s.length(); i++) { // идем по символам
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
			return true;
	}
	return false;
}

void Keeper::check_p_id(int id)
{
	if (id >= size_p) throw exception("Поэта с данным id не обнаружено");
}

void Keeper::check_n_id(int id)
{
	if (id >= size_n) throw exception("Романист с данным id не обнаружено");
}

void Keeper::check_f_id(int id)
{
	if (id >= size_f) throw exception("Фантаста с данным id не обнаружено");
}

