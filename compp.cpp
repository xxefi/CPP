
#include <iostream>
#include <string>
using namespace std;

class Component {
private:
	string model;
public:
	Component(const string& model) : model(model){}
	string getModel() const {
		return model;
	}
};

class Processor : public Component {
private:
	double frequency;
public:
	Processor(const string& model, const double& frequency) : Component(model), frequency(frequency){}
	double getFrequency() const {
		return frequency;
	}
};

class Memory : public Component {
private:
	int capacity;
	int frequency;
	string DDR;
public:
	Memory(const string& model, const int& capacity, const int& frequency, const string& DDR) : Component(model), capacity(capacity), frequency(frequency), DDR(DDR) {}
	int getCapacity() const {
		return capacity;
	}
	int getFrequency() const {
		return frequency;
	}
	string getDDR() const {
		return DDR;
	}
};

class Storage : public Component {
private:
	int volume;
public:
	Storage(const string& model, const int& volume) : Component(model), volume(volume) {}
	int getVolume() const {
		return volume;
	}
};


class SSD : public Component {
private:
	int volumessd;
public:
	SSD(const string& model, const int& volumessd) : Component(model), volumessd(volumessd) {}
	int getVolume() const {
		return volumessd;
	}
};

class PowerUnit : public Component {
private:
	int WAT;
public:
	PowerUnit(const string& model, const int& WAT) : Component(model), WAT(WAT) {}
	int getW() const {
		return WAT;
	}
};


class BIOS : public Component {
private:
	int modelVersion;
public:
	BIOS(const string& model, const int& modelVersion) : Component(model), modelVersion(modelVersion) {}
	int getmodelVersion() const {
		return modelVersion;
	}
};

class Windows : public Component {
private:
	string modelW;
	int version;
public:
	Windows(const string& modelW, const int& version) : Component(modelW), modelW(modelW), version(version) {}
	string getModel() const {
		return modelW;
	}
	int getVersion() const {
		return version;
	}
};


class DirectX : public Component {
private:
	int version;
public:
	DirectX(const string& model, const int& version) : Component(model), version(version){}
	int getVersion() const {
		return version;
	}
};


class Computer{
private:
	Processor processor;
	Memory memory;
	Storage storage;
	SSD ssd;
	PowerUnit powerunit;
	BIOS bios;
	Windows windows;
	DirectX directX;
public:
	Computer(const Processor& processor, const Memory& memory, const Storage& storage, const SSD& ssd, const PowerUnit& powerunit, const BIOS& bios, const Windows& windows, const DirectX& directX) : processor(processor), memory(memory), storage(storage), ssd(ssd), powerunit(powerunit), bios(bios), windows(windows), directX(directX) {}
	void getConfig() {
		cout << "Характеристики пк: " << endl;
		cout << "Процессор: " << processor.getModel() << " " << processor.getFrequency() << " GHz " << endl;
		cout << "Оперативная память: " << memory.getModel() << " " << memory.getCapacity() << " GB " << memory.getFrequency() << " MHz " << memory.getDDR() << endl;
		cout << "Жёсткий диск: " << storage.getModel() << " " << storage.getVolume() << " GB" << endl;
		cout << "SSD диск: " << ssd.getModel() << " " << ssd.getVolume() << " GB" << endl;
		cout << "Блок питания: " << powerunit.getModel() << " " << powerunit.getW() << " W" << endl;
		cout << "Операционная система: " << windows.getModel() << " " << windows.getVersion() << endl;
		cout << "BIOS: " << bios.getModel() << " " << bios.getmodelVersion() << endl;
		cout << "DirectX: " << directX.getModel() << " " << directX.getVersion() << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Processor processor("Intel Core i9-9900K", 2700);
	Memory memory("Kingston FURY", 8, 3200, "DDR4");
	Storage storage("WD BLUE", 500);
	SSD ssd("KingSpec", 960);
	PowerUnit powerunit("Deepcool DE600 v2", 600);
	BIOS bios("BIOS", 1203);
	Windows windows("Windows", 10);
	DirectX directX("DirectX", 12);
	Computer computer(processor, memory, storage, ssd, powerunit, bios, windows, directX);
	computer.getConfig();
}
