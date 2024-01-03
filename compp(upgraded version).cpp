#include <iostream>
using namespace std;


class Component {
public:
	Component(const string& name) {
		this->name = name;
	}

	string getName() const {
		return name;
	}

private:
	string name;
};


class Processor : public Component {
public:
	Processor(const string& model, const double& frequency)
		: Component(model), frequency(frequency) {}

	double getFrequency() const {
		return frequency;
	}


private:
	double frequency;
};

class RAM : public Component {
public:
	RAM(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}


	int getCapacity() const {
		return capacity;
	}
private:
	int capacity;
};

class VideoCard : public Component {
public:
	VideoCard(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}


	int getCapacity() const {
		return capacity;
	}
private:
	int capacity;
};

class MotherBoard : public Component {
public:
	MotherBoard(const string& model)
		: Component(model) {}

};


class HDD : public Component {
public:
	HDD(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}

	int getCapacity() const {
		return capacity;
	}
private:
	int capacity;
};

class SSD : public Component {
public:
	SSD(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}


	int getCapacity() const {
		return capacity;
	}
private:
	int capacity;
};

class PowerInit : public Component {
public:
	PowerInit(const string& model, const int& W)
		: Component(model), W(W) {}

	int getW() const {
		return W;
	}
private:
	int W;
};

class Case : public Component {
public:
	Case(const string& typeCase)
		: Component(typeCase) {}

};

class AudioAdapter : public Component {
public:
	AudioAdapter(const string& model)
		: Component(model) {}
};

class NetworkAdapter : public Component {
public:
	NetworkAdapter(const string& model)
		: Component(model) {}

};

class Monitor : public Component {
public:
	Monitor(const string& model, const int& Hz)
		: Component(model), Hz(Hz) {}

	int getHZ() const {
		return Hz;
	}

private:
	int Hz;
};

class Computer {
public:
	Computer(const Processor& processor1, const RAM& ram1, const VideoCard& videoCard1,
		const MotherBoard& motherBoard1, const HDD& hdd1, const SSD& ssd1, const PowerInit& powerInit1,
		const Case& case1, const AudioAdapter& audioAdapter1, const NetworkAdapter& networkAdapter1, const Monitor& monitor1)
		: processor(processor1), ram(ram1), videoCard(videoCard1), motherBoard(motherBoard1),
		hdd(hdd1), ssd(ssd1), powerInit(powerInit1), casee(case1), audioAdapter(audioAdapter1), networkAdapter(networkAdapter1),
		monitor(monitor1) {}

	void PrintInfo() const {
		cout << "Все компоненты: \n";
		cout << "===================================================\n";
		cout << "Процессор: " << processor.getName() << " " << processor.getFrequency() << " GHz" << endl;
		cout << "Оперативная память: " << ram.getName() <<  " " << ram.getCapacity() << " GB" << endl;
		cout << "Видеокарта: " << videoCard.getName() << " " << videoCard.getCapacity() << " GB" << endl;
		cout << "Материнская плата: " << motherBoard.getName() << endl;
		cout << "Жёсткий диск: " << hdd.getName() << " " << hdd.getCapacity() << endl;
		cout << "SSD диск: " << ssd.getName() << " " << ssd.getCapacity() << endl;
		cout << "Блок питания: " << powerInit.getName() << " " << powerInit.getW() << " W" << endl;
		cout << "Корпус: " << casee.getName() << " " << endl;
		cout << "Звуковой адаптер: " << audioAdapter.getName() << " " << endl;
		cout << "Сетевой адаптер: " << networkAdapter.getName() << " " << endl;
		cout << "Монитор: " << monitor.getName() << " " << monitor.getHZ() << " Hz" << endl;
		cout << "===================================================\n";
	}
private:
	Processor processor;
	RAM ram;
	VideoCard videoCard;
	MotherBoard motherBoard;
	HDD hdd;
	SSD ssd;
	PowerInit powerInit;
	Case casee;
	AudioAdapter audioAdapter;
	NetworkAdapter networkAdapter;
	Monitor monitor;
};

void main() {
	setlocale(LC_ALL, "ru");
	Processor processor("Intel Core i9-9900K", 3.6);
	RAM ram("HyperX", 16);
	VideoCard videoCard("NVIDIA Geforce GTX 1650 SUPER", 4);
	MotherBoard motherBoard("MSI-23K23N424");
	HDD hdd("Seagate S2-8234F2", 750);
	SSD ssd("Kingson FG83KDNF", 1000);
	PowerInit powerInit("DeepCool A2-G3U", 640);
	Case casee("DeepCool");
	AudioAdapter audioAdapter("Realtek Sound A2-GD4KS5AS");
	NetworkAdapter networkAdapter("Ethernet Network A5-VKDFGSDGKS");
	Monitor monitor("ASUS TUF GAMING T2-9412", 144);
	Computer computer11(processor, ram, videoCard, motherBoard, hdd, ssd, powerInit, casee, audioAdapter, networkAdapter, monitor);
	int choice;
	while (true)
	{
		cout << "Выберите, какой компонент хотите видеть: " << endl;
		cout << "1. Процессор " << endl;
		cout << "2. Оперативная память " << endl;
		cout << "3. Видеокарта " << endl;
		cout << "4. Материнская плата " << endl;
		cout << "5. Жёсткий диск " << endl;
		cout << "6. SSD диск " << endl;
		cout << "7. Блок питания " << endl;
		cout << "8. Корпус " << endl;
		cout << "9. Звуковой адаптер " << endl;
		cout << "10. Сетевой адаптер " << endl;
		cout << "11. Монитор " << endl;
		cout << "12. Все компоненты " << endl;
		cout << "0. Выйти из программы " << endl;
		cout << "Сделайте выбор: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			cout << "Процессор: " << processor.getName() << " " << processor.getFrequency() << " GHz" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Оперативная память: " << ram.getName() << " " << ram.getCapacity() << " GB" << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			cout << "Видеокарта: " << videoCard.getName() << " " << videoCard.getCapacity() << " GB" << endl;
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			cout << "Материнская плата: " << motherBoard.getName() << endl;
			system("pause");
			system("cls");
			break;

		case 5:
			system("cls");
			cout << "Жёсткий диск: " << hdd.getName() << " " << hdd.getCapacity() << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			system("cls");
			cout << "Жёсткий диск: " << hdd.getName() << " " << hdd.getCapacity() << endl;
			system("pause");
			system("cls");
			break;

		case 7:
			system("cls");
			cout << "Блок питания: " << powerInit.getName() << " " << powerInit.getW() << " W" << endl;
			system("pause");
			system("cls");
			break;

		case 8:
			system("cls");
			cout << "Корпус: " << casee.getName() << " " << endl;
			system("pause");
			system("cls");
			break;

		case 9:
			system("cls");
			cout << "Звуковой адаптер: " << audioAdapter.getName() << " " << endl;
			system("pause");
			system("cls");
			break;

		case 10:
			system("cls");
			cout << "Сетевой адаптер: " << networkAdapter.getName() << " " << endl;
			system("pause");
			system("cls");
			break;

		case 11:
			system("cls");
			cout << "Монитор: " << monitor.getName() << " " << monitor.getHZ() << " Hz" << endl;
			system("pause");
			system("cls");
			break;

		case 12:
			system("cls");
			computer11.PrintInfo();
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			cout << "До свидания! " << endl;
			return;
			break;
		}
	}
}
