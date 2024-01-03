#include <iostream>
#include <cstdint>
using namespace std;



#if 0
/*
Задание 1
Создайте класс Student, который будет содержать информацию о студенте.
С помощью механизма наследования, реализуйте класс
Aspirant (аспирант – студент, который готовится к защите
кандидатской работы) производный от Student.*/
class Student {
private:
	string name;
	string surname;
	uint16_t age;
public:
	Student(const string& name, const string& surname, const uint16_t& age) : name(name), surname(surname), age(age) {}

	void Print() const {
		cout << "Имя студента: " << this->name << endl;
		cout << "Фамилия студента: " << this->surname << endl;
		cout << "Возраст студента: " << this->age << endl;
	}
};

class Aspirant : public Student {
private:
	string researchtopic;
public:
	Aspirant(const string& name, const string& surname, const uint16_t& age, const string& researchtopic) : Student(name, surname, age), researchtopic(researchtopic) {}

	void Print() const {
		Student::Print();
		cout << "Тема исследования: " << researchtopic << endl;
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	Student student1("Efi", "Huseynov", 16);
	student1.Print();
	cout << "====================================" << "\n";
	Aspirant student2("Efi", "Huseynov", 16, "Step IT Academy");
	student2.Print();
}
#endif // 1;

#if 0
//==================================================================================================================================================================================
/*
Задание 2
Создайте класс Passport (паспорт), который будет содержать
паспортную информацию о гражданине Азербайджана.
С помощью механизма наследования, реализуйте класс*/

class Passport {
private:
	string country;
	string name;
	string surname;
	string patronymic;
	string dateofbirth;
	string placeofbirth;
	string floor;
	uint16_t age;
public:
	Passport(const string& country, const string& name, const string& surname, const string& patronymic, const string& dateofbirth, const string& placeofbirth, const string& floor, const uint16_t& age)
		: country(country), name(name), surname(surname), patronymic(patronymic), dateofbirth(dateofbirth), placeofbirth(placeofbirth), floor(floor), age(age) {}

	void Print() const {
		cout << "Страна: " << country << endl;
		cout << "Имя Гражданина: " << name << endl;
		cout << "Фамилия Гражданина: " << surname << endl;
		cout << "Отчество Гражданина: " << patronymic << endl;
		cout << "Дата рождения Гражданина: " << dateofbirth << endl;
		cout << "Горож рождения Гражданина: " << placeofbirth << endl;
		cout << "Пол: " << floor << endl;
		cout << "Возраст гражданина: " << age << endl;
	}
};


class ForeignPassport : public Passport {
private:
	uint16_t visaData;
	uint16_t passportNumber;
public:
	ForeignPassport(const string& country, const string& name, const string& surname, const string& patronymic, const string& dateofbirth, const string& placeofbirth, const string& floor, const uint16_t& age, const uint16_t& visaData, const uint16_t& passportNumber)
		:Passport(country, name, surname, patronymic, dateofbirth, placeofbirth, floor, age), visaData(visaData), passportNumber(passportNumber) {}
	void Print() const {
		Passport::Print();
		cout << "Данные о визах: " << visaData << endl;
		cout << "Номер заграничного паспорта: " << passportNumber << endl;
	}

};

int main() {
	setlocale(LC_ALL, "ru");
	Passport passport1("Азербайджан", "Афган", "Магсудлу", "Гафгаз", "25.01.2007", "Баку", "Мужской", 16);
	passport1.Print();
	cout << "==================================" << "\n";
	ForeignPassport passport2("Азербайджан", "Афган", "Магсудлу", "Гафгаз", "25.01.2007", "Баку", "Мужской", 16, 4444654, 416973);
	passport2.Print();

}
#endif // 1
