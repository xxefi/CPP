#include <iostream>
using namespace std;
/*
Домашнее задание.

Реализуйте класс компьютер.
Сложные компоненты как процессор должны быть отдельными структурами.
Не забудьте про инкапсуляцию.
Реализуйте методы создания(конструкторы) и метод для вывода. */

struct Proc {
	string proc;
	int freq;
};

struct Brend {
	string brend;
};

struct Memory {
	int memory{};
};

struct HDD {
	string HardDisk;
	int size{};
};

struct SSD {
	string SSD;
	int size{};
};

struct PowerUnit {
	string powerunitt;
};

class Comp {
public:

	Comp(string NewBrend, int NewMemory, string NewProc, int NewFreq, string NewHardDisk, int sizeHardDisk, string NewPowerUnit, string NewSSDDisk, int sizeSSD) {
		brendd.brend = NewBrend;
		memoryy.memory = NewMemory;
		procc.proc = NewProc;
		procc.freq = NewFreq;
		hdd.HardDisk = NewHardDisk;
		hdd.size = sizeHardDisk;
		powerr.powerunitt = NewPowerUnit;
		ssdDisk.SSD = NewSSDDisk;
		ssdDisk.size = sizeSSD;
	}

	void Print() {
		cout << "Бренд: " << brendd.brend << endl;
		cout << "Процессор: " << procc.proc << endl;
		cout << "Частота процессора: " << procc.freq << endl;
		cout << "Оперативная память: " << memoryy.memory << " Гб" << endl;
		cout << "Жёсткий диск: " << hdd.HardDisk << " " << hdd.size << " Гб" << endl;
		cout << "Блок Питания: " << powerr.powerunitt << endl;
		cout << "SSD: " << ssdDisk.SSD << " " << ssdDisk.size << " ТБ" << endl;

	}

private:
	Brend brendd;
	Memory memoryy;
	Proc procc;
	HDD hdd;
	PowerUnit powerr;
	SSD ssdDisk;
};




int main() {
	setlocale(LC_ALL, "ru");
	Comp comp("ThinkCentre", 16, "Intel Core i9-9900K", 3200, "Seagate 9GB 3.5 2MB 80Pin SCSI 10000RPM For ST39103LC", 500, "be quiet! Dark Power Pro 13", "Samsung SATA MZ-77E1T0BW", 1);
	comp.Print();
}
