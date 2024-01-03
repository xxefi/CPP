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

	cout << "������� ��� �����: (���� ������ ���� ����������� .txt)" << endl;
	cin >> file;

	Regex regex;
	regex.getTxt();

	try
	{
		if (file.length() < 4 || file.substr(file.length() - 4) != ".txt") {
			throw invalid_argument("���� ������ ����� ���������� .txt");
		}
		else {
			system("cls");
			cout << "���� �������� �������! ������ ���������� ������." << endl;
			system("pause");
		}
	}
	catch (const invalid_argument& e)
	{
		system("cls");
		cout << "������: " << e.what() << endl;
		system("pause");
		return;
	}

	out.open(file);
	if (!out) {
		cout << "�� ������� ������� ����! " << endl;
		return;
	}
	while (true) {
		system("cls");
		cout << "---����� ���������� � ���������!---" << endl;
		cout << "\n�������� �����: " << endl;
		cout << "1. �������� ����������" << endl;
		cout << "2. �������� ���������" << endl;
		cout << "3. �������� ������" << endl;
		cout << "4. �������� �����" << endl;
		cout << "5. ������������� ������� �����" << endl;
		cout << "6. ������������� ��������� �����" << endl;
		cout << "7. ������������� �������� �����" << endl;
		cout << "8. ������������� ��� 3 ���������� �� ������" << endl;
		cout << "9. ������������� ��� 3 ���������� �� �����" << endl;
		cout << "10. ������������� ��� 3 ��������� �� �����" << endl;
		cout << "11. ������������� ��� 3 ��������� �� ������" << endl;
		cout << "12. ����� �� ���������" << endl;
		cout << "�������� �����: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			cout << "������� ����� ����������: ";
			cin >> amount;

			cout << "������� ���� ���������� (���.�����.����): ";
			cin >> date;

			cout << "������� ��������� ����������: ";
			cin.ignore();
			getline(cin, categories);

			cout << "������� �������� ����������: ";
			getline(cin, description);

			cout << "�������� ����� ������: " << endl;
			cout << "1. �������� " << endl;
			cout << "2. ������ " << endl;
			cin >> paymentChoice;

			if (paymentChoice == 1) {
				paymentMethod = PaymentMethod::CASH;
			}
			else if (paymentChoice == 2) {
				paymentMethod = PaymentMethod::CARD;
			}
			else {
				cout << "���������� �����, ������� ����� �������������� ����� ������ �� ��������� (��������)." << endl;
				paymentMethod = PaymentMethod::CASH;
			}

			if (paymentMethod == PaymentMethod::CARD) {
				cout << "�������� �����: " << endl;
				for (size_t i = 0; i < cards.size(); ++i) {
					cout << i + 1 << ". " << cards[i].getCardType() << " (������: " << cards[i].getBalance() << ")\n";
				}
				cin >> cardChoice;

				if (cardChoice <= 0 || cardChoice > cards.size()) {
					cout << "������������ ����� �����!" << endl;
					break;
				}

				Card selectedCard = cards[cardChoice - 1];
				if (selectedCard.getBalance() < amount) {
					cout << "� ��������� ����� ������������ ������� ��� ���������� ����������!" << endl;
					break;
				}

				transaction = Transaction(amount, date, categories, description, paymentMethod);
				expenceManager.addTransaction(transaction);
				selectedCard.updateBalance(-amount); 
			}
			else {
				cout << "�������� �������: " << endl;
				for (size_t i = 0; i < wallets.size(); ++i) {
					cout << i + 1 << ". " << wallets[i].getName() << " (������: " << wallets[i].getBalance() << ")\n";
				}
				cin >> walletChoice;

				if (walletChoice <= 0 || walletChoice > wallets.size()) {
					cout << "������������ ����� ��������!" << endl;
					break;
				}

				Wallet selectedWallet = wallets[walletChoice - 1];
				if (selectedWallet.getBalance() < amount) {
					cout << "� ���������� �������� ������������ ������� ��� ���������� ����������!" << endl;
					break;
				}

				transaction = Transaction(amount, date, categories, description, paymentMethod);
				expenceManager.addTransaction(transaction);
				selectedWallet.updateBalance(-amount); 
			}

			cout << "���������� ������� ���������! " << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "������� �������� ����� ���������: ";
			cin.ignore();
			getline(cin, categories);
			expenceManager.addCategory(categories);
			cout << "��������� ������� ���������!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "������� �������� ������ ��������: ";
			cin.ignore();
			getline(cin, name);
			cout << "������� ������ ������ ��������: ";
			cin >> amount;
			wallets.push_back(Wallet(name, amount));
			expenceManager.addWallet(wallets.back());
			cout << "��� ������ ������� ��������!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "�������� ����� �����: " << endl;
			cout << "1. Kapital Bank" << endl;
			cout << "2. LeoBank" << endl;
			cout << "3. AccessBank" << endl;
			cout << "4. PasaBank" << endl;
			cout << "5. UniBank" << endl;
			cout << "��� �����: ";
			cin >> cardChoice;
			if (cardChoice >= 1 && cardChoice <= 5) {
				cout << "�������! �� ������� ����� ";
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

				cout << "������� ������ �����: ";
				cin >> amount;
				cards.push_back(Card(categories, amount));
				expenceManager.addCard(cards.back()); 
				cout << "�� ������� �������� ����� " << categories << "." << endl;
			}
			else {
				cout << "�� ������� ������������ �����!" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "������� �����: " << endl;
			reports.generateDaysReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "��������� �����: " << endl;
			reports.generateWeeksReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "�������� �����: " << endl;
			reports.generateMonthsReport(transactions, file);
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "��� 3 ���������� �� ������: " << endl;
			reports.generateTopTransactionsByWeeks(transactions, file);
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			cout << "��� 3 ���������� �� �����: " << endl;
			reports.generateTopTransactionsByMonths(transactions, file);
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			cout << "��� 3 ��������� �� �����: " << endl;
			reports.generateTopCategoriesByMonths(transactions, file);
			system("pause");
			system("cls");
			break;
		case 11:
			system("cls");
			cout << "��� 3 ��������� �� ������: " << endl;
			reports.generateTopCategoriesByWeeks(transactions, file);
			system("pause");
			system("cls");
			break;
		case 12:
			cout << "�����! " << endl;
			return;
		default:
			cout << "������������ �����! " << endl;
			break;
		}
	}
	out.close();
}
