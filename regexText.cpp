#include <iostream>
#include <regex>
using namespace std;

class RegexTexts {
public:
	RegexTexts(const string& URL, const string& date, const string& HTML) {
		this->urlText = URL;
		this->dateText = date;
		this->htmlText = HTML;

		regex urlRegex("\\b((?:https?|ftp)://[^\\s/$.?#].[^\\s]*)\\b");
		regex dateRegex("^(0?[1-9]|[1-2]\\d|3[0-1])\\.(0?[1-9]|1[0-2])\\.\\d{4}$");
		regex htmlRegex("<[^>]*>");

		if (!regex_search(URL, urlRegex)) {
			throw invalid_argument("Недействительный URL.");
		}

		else if (!regex_search(date, dateRegex)) {
			throw invalid_argument("Недействительная Дата.");
		}

		else if (!regex_search(HTML, htmlRegex)) {
			throw invalid_argument("Недействительный HTML.");
		}

		else {
			cout << "Всё правильно! " << endl;
			return;
		}
	}

	string geturlText() const {
		return urlText;
	}

	string getdateText() const {
		return dateText;
	}

	string gethtmlText() const {
		return htmlText;
	}
private:
	string urlText;
	string dateText;
	string htmlText;
};

int main() {
	setlocale(LC_ALL, "RU");
	try
	{

		RegexTexts regexTexts("https://www.google.com", "26.07.2023", "Visit our website <a href=\"https://www.example.com\">here</a>");
		cout << regexTexts.geturlText() << endl;
		cout << regexTexts.getdateText() << endl;
		cout << regexTexts.gethtmlText() << endl;
	}
	catch (const invalid_argument e)
	{
		cout << "Ошибка: " << e.what() << endl;
	} 
	


}
