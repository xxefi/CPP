#include <iostream>
#include <string>
#include <regex>
using namespace std;

/*
Реализуйте виртуальные деструкторы для класса
Transport, Car, Plane, Boat.
1. перегрузите операторы вывода и сравнения
2. напишите Regex для всех возможных строк.
3. напишите все исключения которые могут быть.
4. записывайте в файл все исключения, которые были проброшены.

Файл должен быть с расширением .csv(гуглите)*/


class Transport {
public:
	virtual ~Transport() {}
	virtual void Display() const = 0;
	virtual bool operator == (const Transport& other) const = 0;
	virtual ostream& operator<< (ostream& os) const = 0;
	virtual string getType() const = 0;
private:
	string model;
	int year;
};

class Car : public Transport {
public:
	Car(const string& model, const int& year) : model(model), year(year){}

	~Car() override {

	}
	

	void Display() const override {
		cout << "Car: " << this->model << endl;
		cout << "Year: " << this->year << endl;
	}


	string getType() const override {
		return model;
	}

	ostream& operator << (ostream& os) const override {
		os << "Car: " << endl;
		os << "Year: " << endl;
		return os;
	}


private:
	string model;
	int year;
};

class Plane : public Transport {
public:
	Plane(const string& airline, const int& capacity) : airline(airline), capacity(capacity){}

	~Plane() override {

	}

	void Display() const override {
		cout << "Plane: " << this->airline << endl;
		cout << "Capacity: " << this->capacity << endl;
	}

	string getType() const override {
		return airline;
	}

	
	ostream& operator << (ostream& os) const override {
		os << "Plane: " << endl;
		os << "Capacity: " << endl;
		return os;
	}
private:
	string airline;
	int capacity;
};

class Boat : public Transport {
public:
	Boat(const string& name, const int& length) : name(name), length(length){}

	~Boat() override{

	}

	void Display() const override {

	}

	bool operator == (const Transport& other) const override {

	}

	ostream& operator << (ostream& os) const override {
		os << "Boat: " << endl;
		return os;
	}
private:
	string name;
	int length;
};

const regex car_regex(R"(Car\d+)");
const regex plane_regex(R"(Plane\d+)");
const regex boat_regex(R"(Boat\d+)");





int main() {

}
