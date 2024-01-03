#include <iostream>
#include <string>
using namespace std;

/*Реализуйте следующую игру.
У вас должны быть классы.
Персонаж, Вид, человек, эльф, орк

При этом каждый персонаж может быть:
лучником, магом, танком(силовик)

Персонаж - абстрактный класс.
Человек, Эльф, Орк - это персонажи

Вид - абстрактный класс.
Лучник, Маг, Танк - это Вид

Поля персонажа:
Имя
Пол
Методы персонажа:
Сменить имя (чистый виртуальный метод)
Вывести информацию на экран (чистый виртуальный метод)

Поля Видов:
Сила
Физ.атака
Физ.защита
Ловкость

Каждый подкласс наследуется от вида.
Например:

class Archer : public PlayerType {
public:
	void attackWithBow() {

	}
}*/


class Person {
protected:
	string gender;
	string name;
public:
	Person(const string& newname, const string& newgender) : name(newname), gender(newgender) {}
	virtual void changeName(const string& newName) = 0;
	virtual void printInfo() const = 0;
};

class Human : public Person {
public:
	Human(const string& newname, const string& newgender) : Person(newname, newgender) {}
	void changeName(const string& newName) override {
		name = newName;
	}

	void printInfo() const override {
		cout << "Человеческий характер: " << endl;
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
	}
};

class Elf : public Person {
public:
	Elf(const string& newname, const string& newgender) : Person(newname, newgender) {}
	void changeName(const string& newName) override {
		name = newName;
	}

	void printInfo() const override {
		cout << "Эльф характер: " << endl;
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
	}

};

class Orc : public Person {
public:
	Orc(const string& newname, const string& newgender) : Person(newname, newgender) {}
	void changeName(const string& newName) override {
		name = newName;
	}

	void printInfo() const override {
		cout << "Орк характер: " << endl;
		cout << "Имя: " << name << endl;
		cout << "Пол: " << gender << endl;
	}
};

class PlayerType {
protected:
	string power;
	string physicalProtection;
	string physicalAttack;
	string dexterity;
public:
	virtual void attack() = 0;
};

class Archer : public PlayerType {
public:
	void attack() override {
		cout << "Идёт атака Archer!" << endl;
	}
};

class Mag : public PlayerType {
	void attack() override {
		cout << "Идёт атака Mag!" << endl;
	}
};

class Tank : public PlayerType {
	void attack() override {
		cout << "Идёт атака с Tank!" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	Person* human = new Human("Efi", "Male\n");
	Person* elf = new Elf("Baxa", "Male\n");
	Person* orc = new Orc("Isa", "Male\n");
	PlayerType* archer = new Archer();
	PlayerType* mag = new Mag();
	PlayerType* tank = new Tank();

	human->printInfo();
	archer->attack();
	elf->printInfo();
	mag->attack();
	orc->printInfo();
	tank->attack();

	delete human;
	delete elf;
	delete orc;
	delete archer;
	delete mag;
	delete tank;

}
