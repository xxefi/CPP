#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
#include "Regex.h"
#include "Wallet.h"
#include "Card.h"
#include "ExpenseCategory.h"
#include "Transaction.h"
#include "ExpenseManager.h"
#include "Reports.h"
#include "PaymentMethod.h"
using namespace std;


void main() {
	setlocale(LC_ALL, "ru");
	ExpenceManager expenceManager;
	Reports reports;
	int choice;
	int paymentChoice;
	int cardChoice;
	time_t date;
	string categories;
	string description;
	string name;
	double amount;
	int walletChoice;
	PaymentMethod paymentMethod;
	Transaction transaction;
	vector<Transaction> transactions;
	vector<Card> cards;
	vector<Wallet> wallets;
	
	string file;
	ofstream out;

	cout << "Введите имя файла: (Файл должен быть расширением .txt)" << endl;
	cin >> file;

	Regex regex;
	regex.getTxt();

	try
	{
		if (file.length() < 4 || file.substr(file.length() - 4) != ".txt") {
			throw invalid_argument("Файл должен иметь расширение .txt");
		}
		else {
			system("cls");
			cout << "Файл создался успешно! Можете продолжить работу." << endl;
			system("pause");
		}
	}
	catch (const invalid_argument& e)
	{
		system("cls");
		cout << "Ошибка: " << e.what() << endl;
		system("pause");
		return;
	}

	out.open(file);
	if (!out) {
		cout << "Не удалось открыть файл! " << endl;
		return;
	}
	while (true) {
		system("cls");
		cout << "---Добро пожаловать в программу!---" << endl;
		cout << "\nВыберите опцию: " << endl;
		cout << "1. Добавить транзакцию" << endl;
		cout << "2. Добавить категорию" << endl;
		cout << "3. Добавить кошелёк" << endl;
		cout << "4. Добавить карту" << endl;
		cout << "5. Сгенерировать дневной отчёт" << endl;
		cout << "6. Сгенерировать недельный отчёт" << endl;
		cout << "7. Сгенерировать месячный отчёт" << endl;
		cout << "8. Сгенерировать Топ 3 Транзакций за неделю" << endl;
		cout << "9. Сгенерировать Топ 3 Транзакций за месяц" << endl;
		cout << "10. Сгенерировать Топ 3 Категории за месяц" << endl;
		cout << "11. Сгенерировать Топ 3 Категории за неделю" << endl;
		cout << "12. Выйти из программы" << endl;
		cout << "Сделайте выбор: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			cout << "Введите сумму транзакции: ";
			cin >> amount;

			cout << "Введите дату транзакции (Год.Месяц.День): ";
			cin >> date;

			cout << "Введите категории транзакции: ";
			cin.ignore();
			getline(cin, categories);

			cout << "Введите описание транзакции: ";
			getline(cin, description);

			cout << "Выберите метод оплаты: " << endl;
			cout << "1. Наличные " << endl;
			cout << "2. Картой " << endl;
			cin >> paymentChoice;

			if (paymentChoice == 1) {
				paymentMethod = PaymentMethod::CASH;
			}
			else if (paymentChoice == 2) {
				paymentMethod = PaymentMethod::CARD;
			}
			else {
				cout << "Непонятный выбор, поэтому будет использоваться метод оплаты по умолчанию (Наличные)." << endl;
				paymentMethod = PaymentMethod::CASH;
			}

			if (paymentMethod == PaymentMethod::CARD) {
				cout << "Выберите карту: " << endl;
				for (size_t i = 0; i < cards.size(); ++i) {
					cout << i + 1 << ". " << cards[i].getCardType() << " (Баланс: " << cards[i].getBalance() << ")\n";
				}
				cin >> cardChoice;

				if (cardChoice <= 0 || cardChoice > cards.size()) {
					cout << "Некорректный выбор карты!" << endl;
					break;
				}

				Card selectedCard = cards[cardChoice - 1];
				if (selectedCard.getBalance() < amount) {
					cout << "У выбранной карты недостаточно средств для выполнения транзакции!" << endl;
					break;
				}

				transaction = Transaction(amount, date, categories, description, paymentMethod);
				expenceManager.addTransaction(transaction);
				selectedCard.updateBalance(-amount); 
			}
			else {
				cout << "Выберите кошелек: " << endl;
				for (size_t i = 0; i < wallets.size(); ++i) {
					cout << i + 1 << ". " << wallets[i].getName() << " (Баланс: " << wallets[i].getBalance() << ")\n";
				}
				cin >> walletChoice;

				if (walletChoice <= 0 || walletChoice > wallets.size()) {
					cout << "Некорректный выбор кошелька!" << endl;
					break;
				}

				Wallet selectedWallet = wallets[walletChoice - 1];
				if (selectedWallet.getBalance() < amount) {
					cout << "У выбранного кошелька недостаточно средств для выполнения транзакции!" << endl;
					break;
				}

				transaction = Transaction(amount, date, categories, description, paymentMethod);
				expenceManager.addTransaction(transaction);
				selectedWallet.updateBalance(-amount); 
			}

			cout << "Транзакция успешно добавлена! " << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Введите название новой категории: ";
			cin.ignore();
			getline(cin, categories);
			expenceManager.addCategory(categories);
			cout << "Категория успешно добавлена!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "Введите название нового кошелька: ";
			cin.ignore();
			getline(cin, name);
			cout << "Введите баланс нового кошелька: ";
			cin >> amount;
			wallets.push_back(Wallet(name, amount));
			expenceManager.addWallet(wallets.back());
			cout << "Ваш кошелёк успешно добавлен!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Выберите новую карту: " << endl;
			cout << "1. Kapital Bank" << endl;
			cout << "2. LeoBank" << endl;
			cout << "3. AccessBank" << endl;
			cout << "4. PasaBank" << endl;
			cout << "5. UniBank" << endl;
			cout << "Ваш выбор: ";
			cin >> cardChoice;
			if (cardChoice >= 1 && cardChoice <= 5) {
				cout << "Отлично! Вы выбрали карту ";
				switch (cardChoice) {
				case 1:
					categories = "Kapital Bank";
					break;
				case 2:
					categories = "LeoBank";
					break;
				case 3:
					categories = "AccessBank";
					break;
				case 4:
					categories = "PasaBank";
					break;
				case 5:
					categories = "UniBank";
					break;
				}
				cout << categories << "." << endl;

				cout << "Введите баланс карты: ";
				cin >> amount;
				cards.push_back(Card(categories, amount));
				expenceManager.addCard(cards.back()); 
				cout << "Вы успешно добавили карту " << categories << "." << endl;
			}
			else {
				cout << "Вы сделали некорректный выбор!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Дневной отчёт: " << endl;
			reports.generateDaysReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Недельный отчёт: " << endl;
			reports.generateWeeksReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Месячный отчёт: " << endl;
			reports.generateMonthsReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "Топ 3 Транзакций за неделю: " << endl;
			reports.generateTopTransactionsByWeeks(transactions, file);
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			cout << "Топ 3 Транзакций за месяц: " << endl;
			reports.generateTopTransactionsByMonths(transactions, file);
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			cout << "Топ 3 Категории за месяц: " << endl;
			reports.generateTopCategoriesByMonths(transactions, file);
			system("pause");
			system("cls");
			break;
		case 11:
			system("cls");
			cout << "Топ 3 Категории за неделю: " << endl;
			reports.generateTopCategoriesByWeeks(transactions, file);
			system("pause");
			system("cls");
			break;
		case 12:
			cout << "Удачи! " << endl;
			return;
		default:
			cout << "Некорректный выбор! " << endl;
			break;
		}
	}
	out.close();
}
