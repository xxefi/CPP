#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Abonent {
private:
    string* fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;
public:
    Abonent(const string& name, const string& home, const string& work, const string& mobile, const string& info)
    : fullName(new string(name)), homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(info){}

    ~Abonent() {
        delete fullName;
    }
    void setFullName(const string& name) {
        *fullName = name;
    }

    const string& getFullName() const{
        return *fullName;
    }

    void setHomePhone(const string& home) {
        homePhone = home;
    }

    const string& getHomePhone() const{
        return homePhone;
    }

    void setWorkPhone(const string& work) {
        workPhone = work;
    }

    const string& getWorkPhone() const{
        return workPhone;
    }

    void setMobilePhone(const string& mobile) {
        mobilePhone = mobile;
    }

    const string& getMobilePhone() const{
        return mobilePhone;
    }

    void setAdditionalInfo(const string& info) {
        additionalInfo = info;
    }

    const string& getAdditionalInfo() const{
        return additionalInfo;
    }

};

void AddContact(vector<Abonent>& abonents) {
    cout << "Введите ФИО: ";
    string fullName;
    getline(cin, fullName);

    cout << "Введите домашний телефон: ";
    string homePhone;
    getline(cin, homePhone);

    cout << "Введите рабочий телефон: ";
    string workPhone;
    getline(cin, workPhone);

    cout << "Введите мобильный телефон: ";
    string mobilePhone;
    getline(cin, mobilePhone);

    cout << "Введите дополнительную информацию: ";
    string additionalInfo;
    getline(cin, additionalInfo);

    Abonent abonent(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
    abonents.push_back(abonent);

    cout << "Контакт успешно добавлен!" << endl;
}

void RemoveContact(vector<Abonent>& abonents) {
    if (abonents.empty()) {
        cout << "Телефонная книга пуста.";
        return;
    }
    cout << "Введите ФИО абонента, которого хотите удалить: ";
    string fullName;
    getline(cin, fullName);

    for (auto i = abonents.begin(); i != abonents.end(); ++i) {
        if (i->getFullName() != fullName){
            abonents.erase(i);
            cout << "Абонент успешно удален!" << endl;
            return;
        }
    }
}

void SearchContact(vector<Abonent>& abonents) {
    if (abonents.empty()) {
        cout << "Телефонная книга пуста.";
        return;
    }

    cout << "Введите ФИО Абонента, которого хотите найти: ";
    string fullName;
    getline(cin, fullName);

    for (const auto& abonent : abonents) {
        if (abonent.getFullName() == fullName) {
            cout << "Информация о контакте: " << endl;
            cout << "ФИО контакта: " << abonent.getFullName() << endl;
            cout << "Рабочий телефон контакта: " << abonent.getWorkPhone() << endl;
            cout << "Домашний телефон контакта: " << abonent.getHomePhone() << endl;
            cout << "Рабочий телефон контакта: " << abonent.getWorkPhone() << endl;
            cout << "Дополнительная информация об контакте: " << abonent.getAdditionalInfo() << endl;
            return;
        }
    }
    cout << "Абонент с указанным ФИО не найден." << endl;
}

void DisplayContact(vector<Abonent>& abonents) {
    if (abonents.empty()) {
        cout << "Телефонная книга пуста.";
        return;
    }
    cout << "Список всех контактов:" << endl;
    for (const auto& abonent : abonents) {
        cout << "Информация о контакте: " << endl;
        cout << "ФИО контакта: " << abonent.getFullName() << endl;
        cout << "Рабочий телефон контакта: " << abonent.getWorkPhone() << endl;
        cout << "Домашний телефон контакта: " << abonent.getHomePhone() << endl;
        cout << "Мобильный телефон контакта: " << abonent.getMobilePhone() << endl;
        cout << "Дополнительная информация об контакте: " << abonent.getAdditionalInfo() << endl;
        system("pause");
        system("cls");
    }
}

void saveContactsToFile(const vector<Abonent>& abonents, const string& filename) {
   ofstream file(filename);
    if (!file) {
        cout << "Ошибка при открытии файла для сохранения." << endl;
        return;
    }

    for (const auto& abonent : abonents) {
        file << abonent.getFullName() << endl;
        file << abonent.getWorkPhone() << endl;
        file << abonent.getHomePhone() << endl;
        file << abonent.getMobilePhone() << endl;
        file << abonent.getAdditionalInfo() << endl;
    }
    file.close();
    cout << "Информация успешно сохранена в файл." << endl;
}

void openContactsToFile(vector<Abonent>& abonents, const string& filename) {
    abonents.clear();
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка при открытии файла для сохранения." << endl;
        return;
    }

    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        ++lineCount;

        if (line.empty()) {
            continue;
        }

        if (line == "-----") {
            Abonent abonent(fullName, homePhone, workPhone, mobilePhone, additionalInfo);
            abonents.push_back(abonent);
            fullName.clear();
            homePhone.clear();
            workPhone.clear();
            mobilePhone.clear();
            additionalInfo.clear();
        } else {
            switch (lineCount % 5) {
                case 1:
                    fullName = line;
                    break;
                case 2:
                    homePhone = line;
                    break;
                case 3:
                    workPhone = line;
                    break;
                case 4:
                    mobilePhone = line;
                    break;
                case 0:
                    additionalInfo = line;
                    break;
            }
        }
    }
    file.close();
    cout << "Информация успешно загружена из файла." << endl;
};

int main() {
    setlocale(LC_ALL, "En");
    vector<Abonent> abonents;
    string filename = "abonents.txt";

    int choice;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Добавить абонента" << endl;
        cout << "2. Удалить абонента" << endl;
        cout << "3. Найти абонента по ФИО" << endl;
        cout << "4. Показать всех абонентов" << endl;
        cout << "5. Сохранить информацию в файл" << endl;
        cout << "6. Загрузить информацию из файла" << endl;
        cout << "7. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                AddContact(abonents);
                break;
            case 2:
                RemoveContact(abonents);
                break;
            case 3:
                SearchContact(abonents);
                break;
            case 4:
                DisplayContact(abonents);
                break;
            case 5:
                saveContactsToFile(abonents, filename);
                break;
            case 6:
                openContactsToFile(abonents, filename);
                break;
            case 7:
                cout << "Выход из программы..." << endl;
                return 0;
            default:
                cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
        cout << endl;
    }
}
