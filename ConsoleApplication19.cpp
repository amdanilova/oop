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


	void print();
	StationaryAnother(const StationaryAnother<T>& copir);
	void showkolvo();
	void operator>(const StationaryAnother<T>& m);
	StationaryAnother<T>& operator+(const StationaryAnother<T>& x);
	StationaryAnother<T>& operator=(const StationaryAnother<T>& y);

	StationaryAnother<T>& operator+=(const StationaryAnother<T>& z);
};

template <class T> class Pen : public StationaryAnother<T> {
protected:
	T size;
	char* color2 = new char[25];
public:
	Pen();
	~Pen();
	void print();

	Pen<T>& operator+(const Pen<T>& x);
};
template<class T> Pen<T>::Pen() {
	StationaryAnother<T>::StationaryAnother();
	size = (double)(rand() % 200) / 10;

	strcpy(color2, "red");
}
template <class T>
void Pen<T>::print() {


	cout << " " << "name etogo objecta:" << StationaryAnother<T>::name << endl;

	cout << " " << "stoimost etogo objecta:" << StationaryAnother<T>::stoimost << endl;
	cout << " " << "kolvo shtuk etogo objecta:" << StationaryAnother<T>::kolvo << endl;
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
	stoimost = y.kolvo;
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
	object8.print();
	cout << "Object 8 proizvodnogo klassa slozheniye 6 7 jbjecta" << endl;
	Pen<double> object9;//проверка на тип double 
	cout << "Object 9 proizvodnogo klassa tip double" << endl;
	object9.print();

	system("pause");

	return 0;
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
