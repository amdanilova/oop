// ConsoleApplication19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cstring>
#include <string.h>
#include "time.h"
#include <iostream>
#include <new>

using namespace std;

class InvalidKolvo : public exception {};
class InvalidStoimost : public exception {
public:
	string message;
	InvalidStoimost() {}
	InvalidStoimost(string message) : message(message) {}
};


template <class T>
class StationaryAnother
{
protected:
	char* name;
	int kolvo;
	T stoimost;

public:
	StationaryAnother();
	StationaryAnother(const char* a, int kolvo, T c);
	~StationaryAnother();
	void input();


	virtual void print();
	StationaryAnother(const StationaryAnother<T>& copir);
	void showkolvo();
	void operator>(const StationaryAnother<T>& m);
	StationaryAnother<T> operator+(const StationaryAnother<T>& x);
	StationaryAnother<T>& operator=(const StationaryAnother<T>& y);

	StationaryAnother<T>& operator+=(const StationaryAnother<T>& z);
};


template <class T>
StationaryAnother<T>::StationaryAnother()
{
	name = new char[25];
	if (name == NULL) {
		throw bad_alloc();
	}
	strcpy(name, "ErichKrause");
	srand(time(0));
	kolvo = (rand() % 200) + 1;
	stoimost = (T)(rand() % 200) / 10;
}


template <class T>
StationaryAnother<T>::StationaryAnother(const char* a, int kolvo, T c) {
	if (kolvo < 0) {
		throw InvalidKolvo();
	}
	if (c < 0) {
		throw InvalidStoimost("Stoimost < 0");
	}

	this->kolvo = kolvo;
	stoimost = c;
	name = new char[strlen(a) + 1];
	if (name == NULL /* || kolvo == 13 */) {
		throw bad_alloc();
	}
	strcpy(name, a);
}


template <class T>
StationaryAnother<T>::StationaryAnother(const StationaryAnother<T>& copir) {
	cout << "Copy constructor StationaryAnother(other)" << endl;
	kolvo = copir.kolvo;
	stoimost = copir.stoimost;
	name = new char[strlen(copir.name) + 1];
	if (name == NULL) {
		throw bad_alloc();
	}
	strcpy(name, copir.name);
}


template <class T>
StationaryAnother<T>::~StationaryAnother() {
	cout << "Destructor ~StationaryAnother()" << endl;
	delete[] name;
}


template <class T>
void StationaryAnother<T>::showkolvo()
{
	cout << "kolvo shtuk etogo objecta" << " " << kolvo << endl;
}


template <class T>
void StationaryAnother<T>::input()
{
	T stoimost;
	int kolvo;

	cout << "Input name:" << endl;
	cin >> name;
	cout << "Input kolvo:" << endl;
	cin >> kolvo;
	if (kolvo < 0) {
		throw InvalidKolvo();
	}
	this->kolvo = kolvo;
	cout << "Input stoimost:" << endl;
	cin >> stoimost;
	if (stoimost < 0) {
		throw InvalidStoimost("Stoimost < 0");
	}
	this->stoimost = stoimost;
	cout << endl;
}


template <class T>
void StationaryAnother<T>::print() {
	cout << name;
	cout << " " << "Kolvo:" << kolvo << endl;
	cout << " " << "Stoimost:" << stoimost << endl;
	cout << endl;
}


template <class T>
void StationaryAnother<T>::operator>(const StationaryAnother<T>& m) {
	if ((this->kolvo * this->stoimost) > (m.kolvo * m.stoimost)) {
		cout << "First is more expensive!" << endl;
	}
	else if ((this->kolvo * this->stoimost) == (m.kolvo * m.stoimost))
	{
		cout << "Same cost!" << " ";
		cout << endl;
	}
	else {
		cout << "Second is cheaper!" << " ";
		cout << endl;
	}
}


template <class T>
StationaryAnother<T> StationaryAnother<T>::operator+(const StationaryAnother<T>& x) {
	cout << "StationaryAnother::operator+()" << endl;
	StationaryAnother<T> obj;
	obj.kolvo = this->kolvo + x.kolvo;
	obj.stoimost = this->stoimost + x.stoimost;
	obj.size = this->size + x.size;

	obj.print();
	return obj;
}


template <class T>
StationaryAnother<T>& StationaryAnother<T>::operator=(const StationaryAnother<T>& other) {
	cout << "StationaryAnother::operator=()" << endl;
	kolvo = other.kolvo;
	stoimost = other.stoimost;
	delete[] name;
	name = new char[strlen(other.name) + 1];
	if (name == NULL) {
		throw bad_alloc();
	}
	strcpy(name, other.name);
	return *this;
}


template <class T>
StationaryAnother<T>& StationaryAnother<T>::operator+=(const StationaryAnother<T>& other) {
	kolvo += other.kolvo;
	stoimost += other.stoimost;

	char* name2 = new char[strlen(other.name) + 1 + strlen(name)];
	if (name2 == NULL) {
		throw bad_alloc();
	}
	strcpy(name2, name);
	delete[] name;
	name = name2;
	strcat(name, other.name);

	return *this;
}


template <class T>
class Pen : public virtual StationaryAnother<T> {
protected:
	T size;
	char* color2;
public:
	Pen();
	~Pen();
	void print(void);
	Pen<T>& operator=(const Pen<T>& y);
	Pen<T> operator+(const Pen<T>& x);
	Pen(const Pen<T>& copir);
};


template<class T> Pen<T>::Pen() : StationaryAnother<T>::StationaryAnother() {
	size = (T)(rand() % 20);
	color2 = new char[25];
	if (color2 == NULL) {
		throw bad_alloc();
	}
	strcpy(color2, "red");
}


template <class T>
Pen<T>::Pen(const Pen<T>& copir) : StationaryAnother<T>::StationaryAnother(copir) {
	cout << "Copy constructor Pen(other)" << endl;

	size = copir.size;
	color2 = new char[strlen(copir.color2) + 1];
	if (color2 == NULL) {
		throw bad_alloc();
	}
	strcpy(color2, copir.color2);
}


template <class T>
void Pen<T>::print() {
	StationaryAnother<T>::print();
	cout << " " << "color etogo objecta:" << color2 << endl;
	cout << " " << "Size etogo objecta:" << size << endl;
	cout << endl;
}

template <class T>
Pen<T>::~Pen() {
	cout << "Destructor ~Pen()" << endl;
	delete[] color2;
	StationaryAnother<T>::~StationaryAnother();
}

template <class T>
Pen<T> Pen<T>::operator+(const Pen<T>& x) {
	cout << "Pen::operator+()" << endl;
	Pen<T> pen;
	pen.kolvo = this->kolvo + x.kolvo;
	pen.stoimost = this->stoimost + x.stoimost;
	pen.size = this->size + x.size;

	pen.print();
	return pen;
}

template <class T>
Pen<T>& Pen<T>::operator=(const Pen<T>& other) {
	cout << "Pen::operator=()" << endl;
	this->kolvo = other.kolvo;
	this->stoimost = other.stoimost;

	delete[] this->name;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	size = other.size;

	delete[] color2;
	color2 = new char[strlen(other.color2) + 1];
	if (color2 == NULL) {
		throw bad_alloc();
	}
	strcpy(color2, other.color2);

	return *this;
}


template <class T>
class Pencil : public virtual StationaryAnother<T> {
protected:
	T size2;
	char* color3;
public:
	Pencil();
	~Pencil();
	void print();
	Pencil<T>& operator=(const Pencil<T>& y);
	Pencil<T> operator+(const Pencil<T>& x);
	Pencil(const Pencil<T>& copir);
};

template<class T>
Pencil<T>::Pencil() : StationaryAnother<T>::StationaryAnother() {
	size2 = (T)(rand() % 200) / 10;
	color3 = new char[25];
	if (color3 == NULL) {
		throw bad_alloc();
	}
	strcpy(color3, "blue");
}

template <class T>
void Pencil<T>::print() {
	StationaryAnother<T>::print();

	cout << " " << "color etogo objecta:" << color3 << endl;
	cout << " " << "Size etogo objecta:" << size2 << endl;
	cout << endl;
}


template<class T>
Pencil<T>::~Pencil() {
	cout << "Destructor ~Pencil()" << endl;
	delete[] color3;

	StationaryAnother<T>::~StationaryAnother();
}


template <class T>
Pencil<T> Pencil<T>::operator+(const Pencil<T>& x) {
	cout << "Pencil::operator+()" << endl;
	Pencil<T> pencil;
	pencil.kolvo = this->kolvo + x.kolvo;
	pencil.stoimost = this->stoimost + x.stoimost;
	pencil.size2 = this->size + x.size;

	return pencil;
}


template <class T>
Pencil<T>& Pencil<T>::operator=(const Pencil<T>& other) {
	cout << "Pencil::operator=()" << endl;

	size2 = other.size2;
	delete[] color3;
	color3 = new char[strlen(other.color3) + 1];
	if (color3 == NULL) {
		throw bad_alloc();
	}
	strcpy(color3, other.color3);
	return *this;
}


template <class T>
Pencil<T>::Pencil(const Pencil<T>& copir) : StationaryAnother<T>::StationaryAnother(copir) {
	cout << "Copy constructor Pencil(other)" << endl;

	size2 = copir.size2;
	delete[] color3;
	color3 = new char[strlen(copir.color3) + 1];
	if (color3 == NULL) {
		throw bad_alloc();
	}
	strcpy(color3, copir.color3);
}



template <class T>
class Nabor : public Pen<T>, public Pencil<T> {
protected:
	T priceofnabor;
	char* size;
public:
	Nabor();
	Nabor(const Nabor<T>& copir);
	~Nabor();
	void print(void);
};

template<class T>
Nabor<T>::Nabor() : Pen<T>::Pen(), Pencil<T>::Pencil() {
	priceofnabor = (T)(rand() % 20000) / 10;
	size = new char[25];
	if (size == NULL) {
		throw bad_alloc();
	}
	strcpy(size, "standart");
}

template <class T>
Nabor<T>::Nabor(const Nabor<T>& copir) : Pen<T>::Pen(copir), Pencil<T>::Pencil(copir) {
	cout << "Copy constructor Nabor(other)" << endl;

	size = new char[strlen(copir.size) + 1];
	if (size == NULL) {
		throw bad_alloc();
	}
	strcpy(size, copir.size);
}

template<class T> Nabor<T>::~Nabor() {
	cout << "Destructor ~Nabor()" << endl;
	delete[] size;

	Pen<T>::~Pen();
	Pencil<T>::~Pencil();
	StationaryAnother<T>::~StationaryAnother();
}


template<class T>
void Nabor<T>::print() {
	cout << "Print from Nabor size: " << size << endl << "Include:" << endl;
	Pen<T>::print();
	Pencil<T>::print();
}




int main() {
	try {
		StationaryAnother<int> pen1;

		while (true) {
			try {

				pen1.input();
				break;
			}
			catch (InvalidKolvo) {
				cout << "Catch Exception InvalidKolvo" << endl;
				cout << "Try again" << endl;
			}
			catch (InvalidStoimost & e) {
				cout << "Catch Exception with message: " << e.message << endl;
				cout << "Try again" << endl;
			}
		}
		pen1.print();

	}
	catch (bad_alloc & ba) {
		cerr << ba.what() << endl;
	}
	system("pause");
	return 0;
}


