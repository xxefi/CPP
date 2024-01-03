#include <iostream>
using namespace std;
/*
В домашнем задании с компьютерами, сделайте конструктор копирования для компьютера и его элементов

*/

class Processor {
private:
    string model;
    int Ghz;
public:
    Processor(const string& model, const int& Ghz) : Ghz(Ghz), model(model) {}
    Processor(const Processor& other) : Ghz(other.Ghz), model(other.model) {}

    int getGhz() const {
        return Ghz;
    }

    string getModel() const {
        return model;
    }
};

class Memory {
private:
    int size;
public:
    Memory(const int& size) : size(size) {}
    Memory(const Memory& other) : size(other.size) {}

    int getSize() const {
        return size;
    }
};

class HardDisk {
private:
    int capacityDisk;
    string model;
public:
    HardDisk(const string& model, const int& capacityDisk) : capacityDisk(capacityDisk), model(model) {}
    HardDisk(const HardDisk& other) : capacityDisk(other.capacityDisk), model(other.model) {}

    string getModelDisk() const {
        return model;
    }

    int getSizeDisk() const {
        return capacityDisk;
    }

};

class VideoDrive {
private:
    string model;
    int capacityVideoDrive;
public:
    VideoDrive(const string& model, const int& capacityVideoDrive) 
    : model(model), capacityVideoDrive(capacityVideoDrive){}
    VideoDrive(const VideoDrive& other) : model(other.model), capacityVideoDrive(other.capacityVideoDrive){}

    string getModelVideoDrive() const {
        return model;
    }

    int getcapacityVideoDrive() const {
        return capacityVideoDrive;
    }
};

class Computer {
private:
    Processor processor;
    Memory memory;
    HardDisk hardDisk;
    VideoDrive videodrive;
public:
    Computer(const Processor& processor, const Memory& memory, const HardDisk& hardDisk, const VideoDrive& videodrive)
        : processor(processor), memory(memory), hardDisk(hardDisk), videodrive(videodrive) {}
    Computer(const Computer& other)
        : processor(other.processor), memory(other.memory), hardDisk(other.hardDisk), videodrive(other.videodrive) {}

    void printInfo() const {
        cout << "Процессор: " << processor.getModel() << " " << processor.getGhz() << " GHz" << endl;
        cout << "Оперативная Память: " << memory.getSize() << " GB" << endl;
        cout << "Жёсткий диск: " << hardDisk.getModelDisk() << " " << hardDisk.getSizeDisk() << " GB" << endl;
        cout << "Видеокарта: " << videodrive.getModelVideoDrive() << " " << videodrive.getcapacityVideoDrive() << " GB" << endl;
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Processor processor("Intel Core i9-9900K", 3200);
    Memory memory(16);
    HardDisk hardDisk("Seagate Skyhawk ST1000VX005", 500);
    VideoDrive videodrive("Geforce GTX 1650 SUPER", 4);
    Computer computer(processor, memory, hardDisk, videodrive);
    computer.printInfo();

    Computer computer2(computer);
    computer.printInfo();
}
