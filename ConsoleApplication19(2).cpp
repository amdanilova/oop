// ConsoleApplication19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <cstring>
#include"time.h"
#include <iostream>

using namespace std;
template <class T>
class StationaryAnother
{
protected:
	char* name = new char[20];
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
	StationaryAnother<T>& operator+(const StationaryAnother<T>& x);
	StationaryAnother<T>& operator=(const StationaryAnother<T>& y);

	StationaryAnother<T>& operator+=(const StationaryAnother<T>& z);
};


template <class T> class Pen : public virtual StationaryAnother<T> {
protected:
	T size;
	char* color2 = new char[25];
public:
	/*Pen(void);*/
	Pen();
	~Pen();
	void print(void);
	Pen<T>& operator=(const Pen<T>& y);
	Pen<T>& operator+(const Pen<T>& x);
	Pen(const Pen<T>& copir);
};
template <class T> class Pencil : public virtual StationaryAnother<T> {
protected:
	T size2;
	char* color3 = new char[25];
public:
	/*Pencil(void);*/
	Pencil();
	~Pencil();
	void print();
	Pencil<T>& operator=(const Pencil<T>& y);
	Pencil<T>& operator+(const Pencil<T>& x);
	Pencil(const Pencil<T>& copir);
};
template <class T> class nabor : public Pen<T>, public Pencil<T> {
protected:
	T priceofnabor;
	char* size = new char[25];
public:
	nabor();
	nabor(const nabor<T>& copir);
	~nabor();
	void print(void);
};

template <class T>
nabor<T>::nabor(const nabor<T>& copir) : StationaryAnother<T>::StationaryAnother(copir) {

	size = copir.size;
	delete[] Pen<T>::color2;
	delete[] Pencil<T>::color3;

	Pencil<T>::color3 = new char[strlen(copir.color3) + 1];

	strcpy(Pencil<T>::color3, copir.color3);
	Pen<T>::color2 = new char[strlen(copir.color2) + 1];

	strcpy(Pen<T>::color2, copir.color2);

}

template<class T> nabor<T>::~nabor() {
	delete[]size;
	cout << "Memory is clear";
	cout << endl;
}


template<class T> nabor<T>::nabor() : StationaryAnother<T>::StationaryAnother() {
	priceofnabor = (T)(rand() % 20000) / 10;

	strcpy(size, "standart");

}

template<class T> 
void nabor<T>::print() {
	cout << "Print from Nabor size: " << size << endl << "Include:" << endl;
	Pen<T>::print();
	Pencil<T>::print();
}

template<class T> Pencil<T>::Pencil() : StationaryAnother<T>::StationaryAnother() {
	size2 = (T)(rand() % 200) / 10;

	strcpy(color3, "blue");

}
template <class T> void Pencil<T>::print() {
	StationaryAnother<T>::print();

	/*cout << " " << "name etogo objecta:" << StationaryAnother<T>::name << endl;

	cout << " " << "stoimost etogo objecta:" << StationaryAnother<T>::stoimost << endl;
	cout << " " << "kolvo shtuk etogo objecta:" << StationaryAnother<T>::kolvo << endl;*/
	cout << " " << "color etogo objecta:" << color3 << endl;
	cout << " " << "Size etogo objecta:" << size2 << endl;

	cout << endl;
}
template<class T> Pencil<T>::~Pencil() {
	delete[]color3;
	cout << "Memory is clear";
	cout << endl;
}
template <class T> Pencil<T>& Pencil<T>::operator+(const Pencil<T>& x) {
	Pencil n1;
	n1.kolvo = this->kolvo + x.kolvo;
	n1.stoimost = this->stoimost + x.stoimost;
	n1.size2 = this->size + x.size;
	cout << "Itogovoe kolvo:" << n1.kolvo << endl;
	cout << "Itogovaya stoimost:" << n1.stoimost << endl;
	cout << "Itogovyi size:" << n1.size << endl;
	return *this;
}
template <class T> Pencil<T>& Pencil<T>::operator=(const Pencil<T>& y) {
	StationaryAnother<T>& StationaryAnother<T>::operator=(const StationaryAnother<T> & y);
	delete[]color3;
	color3 = new char[strlen(y.color3) + 1];
	strcpy(color3, y.color3);
	return*this;
}
template <class T>
Pencil<T>::Pencil(const Pencil<T>& copir) : StationaryAnother<T>::StationaryAnother(copir) {

	size2 = copir.size2;

	delete[] color3;

	color3 = new char[strlen(copir.color3) + 1];

	strcpy(color3, copir.color3);

}
template<class T> Pen<T>::Pen() : StationaryAnother<T>::StationaryAnother() {
	size = (T)(rand() % 200) / 10;

	strcpy(color2, "red");
}

template <class T>
void Pen<T>::print() {

	StationaryAnother<T>::print();
	/*cout << " " << "name etogo objecta:" << StationaryAnother<T>::name << endl;

	cout << " " << "stoimost etogo objecta:" << StationaryAnother<T>::stoimost << endl;
	cout << " " << "kolvo shtuk etogo objecta:" << StationaryAnother<T>::kolvo << endl;*/
	cout << " " << "color etogo objecta:" << color2 << endl;
	cout << " " << "Size etogo objecta:" << size << endl;
	cout << endl;
}
template <class T>
Pen<T>::~Pen() {
	delete[]color2;
	cout << "Memory is clear";
	cout << endl;
}
template <class T> Pen<T>& Pen<T>::operator+(const Pen<T>& x) {
	Pen n1;
	n1.kolvo = this->kolvo + x.kolvo;
	n1.stoimost = this->stoimost + x.stoimost;
	n1.size = this->size + x.size;
	cout << "Itogovoe kolvo:" << n1.kolvo << endl;
	cout << "Itogovaya stoimost:" << n1.stoimost << endl;
	cout << "Itogovyi size:" << n1.size << endl;
	return *this;
}
template <class T> Pen<T>& Pen<T>::operator=(const Pen<T>& y) {
	StationaryAnother<T>& StationaryAnother<T>::operator=(const StationaryAnother<T> & y);
	delete[]color2;
	color2 = new char[strlen(y.color2) + 1];
	strcpy(color2, y.color2);
	return*this;
}
template <class T>
Pen<T>::Pen(const Pen<T>& copir) : StationaryAnother<T>::StationaryAnother(copir) {

	size = copir.size;

	delete[] color2;

	color2 = new char[strlen(copir.color2) + 1];

	strcpy(color2, copir.color2);

}

template <class T>
StationaryAnother<T>::StationaryAnother()
{
	//name = new char[strlen("ErichKrause") + 1];
	strcpy(name, "ErichKrause");
	srand(time(0));
	kolvo = (rand() % 200) + 1;
	stoimost = (T)(rand() % 200) / 10;
}
template <class T>
StationaryAnother<T>::StationaryAnother(const char* a, int kolvo, T c) {

	this->kolvo = kolvo;
	stoimost = c;
	delete[]name;
	name = new char[strlen(a) + 1];
	strcpy(name, a);
}
template <class T>
StationaryAnother<T>::~StationaryAnother() {
	delete[]name;
	cout << "Memory is clear";
	cout << endl;
}
template <class T>
void StationaryAnother<T>::showkolvo()
{
	cout << "kolvo shtuk etogo objecta" << " " << kolvo << endl;
}
template <class T>
void StationaryAnother<T>::input()
{
	cout << "Input name:" << endl;
	cin >> name;
	cout << "Input kolvo:" << endl;
	cin >> kolvo;
	cout << "Input stoimost:" << endl;
	cin >> stoimost;
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
StationaryAnother<T>::StationaryAnother(const StationaryAnother<T>& copir) {
	kolvo = copir.kolvo;
	stoimost = copir.stoimost;
	delete[] name;

	name = new char[strlen(copir.name) + 1];

	strcpy(name, copir.name);

}
template <class T>
void StationaryAnother<T>::operator>(const StationaryAnother<T>& m) {
	if ((this->kolvo * this->stoimost) > (m.kolvo * m.stoimost)) {
		cout << "First is more expensive!";
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
template <class T> StationaryAnother<T>& StationaryAnother<T>::operator+(const StationaryAnother<T>& x) {
	StationaryAnother n1;
	n1.kolvo = this->kolvo + x.kolvo;
	n1.stoimost = this->stoimost + x.stoimost;
	cout << "Itogovoe kolvo:" << n1.kolvo << endl;
	cout << "Itogovaya stoimost:" << n1.stoimost << endl;
	return *this;
}
template <class T> StationaryAnother<T>& StationaryAnother<T>::operator=(const StationaryAnother<T>& y) {

	kolvo = y.kolvo;
	stoimost = y.stoimost;
	delete[] name;

	name = new char[strlen(y.name) + 1];

	strcpy(name, y.name);
	return*this;
}
template <class T> StationaryAnother<T>& StationaryAnother<T>::operator+=(const StationaryAnother<T>& z) {
	kolvo += z.kolvo;
	stoimost += z.stoimost;

	char* name2 = new char[strlen(z.name) + 1 + strlen(name)];
	strcpy(name2, name);
	delete[]name;
	name = new char[strlen(z.name) + 1 + strlen(name)];
	strcpy(name, strcat(name2, z.name));
	delete[]name2;


	return *this;

}

int main() {


	StationaryAnother<double> object1;//объект базового класса
	object1.print();//метод базового класса
	StationaryAnother<double> object2("berlingo", 5, 24.8);
	cout << "Object 2" << endl;
	object2.print();
	StationaryAnother<double> object3;
	cout << "Object 3" << endl;
	object3.print();
	object2 > object1;//метод базового класса
	StationaryAnother<double> object4 = object1 + object2;//метод базового класса
	cout << "Object 4" << endl;
	object4.print();
	cout << "Object 5" << endl;
	StationaryAnother<double> object5;

	object5 += object3;//метод базового класса
	object5.print();
	Pen<int> object6;//объект производного класса + вызывается конструктор базового класса
	cout << "Object 6 proizvodnogo klassa" << endl;
	object6.print();//метод производного класса
	object6.showkolvo();//метод базового класса
	Pen<int> object7;//объект производного класса  + вызывается конструктор базового класса
	cout << "Object 7 proizvodnogo klassa" << endl;
	object7.print();//метод производного класса

	Pen<int> object8 = object6 + object7;//метод сложения производного класса
	cout << "Object 8 proizvodnogo klassa slozheniye 6 i 7 objecta" << endl;
	object8.print();
	Pen<double> object9;//проверка на тип double 
	cout << "Object 9 proizvodnogo klassa tip double" << endl;
	object9.print();
	Pen<double> object10;
	cout << "Object 10 proizvodnogo klassa tip double" << endl;
	object10 = object9;
	object10.print();
	Pencil<int> object11;
	cout << "Object 11 proizvodnogo klassa" << endl;
	object11.print();
	Pencil<double> object12;//проверка на тип double 
	cout << "Object 12 proizvodnogo klassa tip double" << endl;
	object12.print();
	Pencil<double> object13;
	cout << "Object 13 proizvodnogo klassa tip double" << endl;
	object13 = object12;
	object13.print();

	nabor<double> object14;
	StationaryAnother<double>& aPen = object10;
	StationaryAnother<double>& aPencil = object12;
	StationaryAnother<double>& aNabor = object14;

	aPen.print();
	aPencil.print();
	aNabor.print();

	system("pause");
	return 0;
}