#include <iostream>
using namespace std;

/*
Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция = =).
2. Операцию присваивания одного объекта в другой
(операция =).
3. Сравнение по цене двух пальто одного типа (операция>).*/


class Overcoat {
private:
	string tipodejdi;
	double price;
public:
	Overcoat(const string& tipodejdi, const double& price) : tipodejdi(tipodejdi), price(price){}
	bool operator == (const Overcoat& other) const {
		return tipodejdi == other.tipodejdi;
	}
	bool operator > (const Overcoat& other) const {
		return tipodejdi == other.tipodejdi;
		return price > other.price;
	}
	void operator = (const Overcoat& other) {
		tipodejdi = other.tipodejdi;
		price = other.price;
	}
};

/*Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция
==).
2. Операцию присваивания одного объекта в другой
(операция =).
3. Сравнение двух квартир по цене (операция>).*/

class Flat {
private:
	string flat;
	double square;
public:
	Flat(const string& flat, const double& square) : flat(flat), square(square){}
	bool operator == (const Flat& other) const {
		return flat == other.flat;
	}
	void operator = (const Flat& other) {
		flat = other.flat;
		square = other.square;
	}
	bool operator > (const Flat& other) const {
		return flat == other.flat;
		return square > other.square;
	}
};



int main() {
	setlocale(LC_ALL, "ru");
	Overcoat overcoat1("Adidas", 50.6);
	Overcoat overcoat2("Salvar", 100);
	if (overcoat1 > overcoat2) {
		cout << "Adidas стоит дешевле чем ""Salvar\n";
	}
	else {
		cout << "Adidas стоит дороже чем ""Salvar\n";
	}
	Flat flat1("Yasamaldaki evim", 5.7);
	Flat flat2("Badamdardaki evim", 7.6);
	if (flat1 > flat2) {
		cout << "Ваш дом из ясамал больше чем из бадамдар\n";
	}
	else {
		cout << "Ваш дом из ясамал меньше чем из бадамдар\n";
	}
}