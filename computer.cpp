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

	string getModel() const {
		return model;
	}

	double getFrequency() const {
		return frequency;
	}

private:
	string model;
	double frequency;
};

class RAM : public Component {
public:
	RAM(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}

	string getModel() const {
		return model;
	}

	int getCapacity() const {
		return capacity;
	}
private:
	string model;
	int capacity;
};

class VideoCard : public Component {
public:
	VideoCard(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}

	string getModel() const {
		return model;
	}

	int getCapacity() const {
		return capacity;
	}
private:
	string model;
	int capacity;
};

class MotherBoard : public Component {
public:
	MotherBoard(const string& model)
		: Component(model) {}

	string getModel() const {
		return model;
	}
private:
	string model;
};


class HDD : public Component {
public:
	HDD(const string& model, const int& capacity) 
		: Component(model), capacity(capacity) {}

	string getModel() const {
		return model;
	}

	int getCapacity() const {
		return capacity;
	}
private:
	string model;
	int capacity;
};

class SSD : public Component {
public:
	SSD(const string& model, const int& capacity)
		: Component(model), capacity(capacity) {}

	string getModel() const {
		return model;
	}

	int getCapacity() const {
		return capacity;
	}
private:
	string model;
	int capacity;
};

class PowerInit : public Component {
public:
	PowerInit(const string& model, const int& W)
		: Component(model), W(W){}

	string getModel() const {
		return model;
	}

	int getW() const {
		return W;
	}
private:
	string model;
	int W;
};

class Case : public Component {
public:
	Case(const string& typeCase)
		: Component(typeCase) {}

	string gettypeCase() const {
		return typeCase;
	}
private:
	string typeCase;
};

class AudioAdapter : public Component {
public:
	AudioAdapter(const string& model)
		: Component(model) {}

	string getModel() const {
		return model;
	}
private:
	string model;
};

class NetworkAdapter : public Component {
public:
	NetworkAdapter(const string& model)
		: Component(model) {}

	string getModel() const {
		return model;
	}
private:
	string model;
};

class Monitor : public Component {
public:
	Monitor(const string& model, const int& Hz)
		: Component(model), Hz(Hz) {}
private:
	string model;
	int Hz;
};

class Computer {
public:
	Computer(const Processor& processor1, const RAM& ram1, const VideoCard& videoCard1,
		const MotherBoard& motherBoard1, const HDD& hdd1, const SSD& ssd1, const PowerInit& powerInit1,
		const Case& case1, const AudioAdapter& audioAdapter1, const NetworkAdapter& networkAdapter1, const Monitor& monitor1)
		: processor1(processor1), ram1(ram1), videoCard1(videoCard1), motherBoard1(motherBoard1),
		hdd1(hdd1), ssd1(ssd1), powerInit1(powerInit1), case1(case1), audioAdapter1(audioAdapter1), networkAdapter1(networkAdapter1),
		monitor1(monitor1) {}

	void PrintInfo() const {
		
	}
private:
	Processor processor1;
	RAM ram1;
	VideoCard videoCard1;
	MotherBoard motherBoard1;
	HDD hdd1;
	SSD ssd1;
	PowerInit powerInit1;
	Case case1;
	AudioAdapter audioAdapter1;
	NetworkAdapter networkAdapter1;
	Monitor monitor1;
};

int main() {
	setlocale(LC_ALL, "ru");

}
