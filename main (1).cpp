#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

bool vowel(char letter) {
	if (letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'o' || letter == 'O' || letter == 'i' || letter == 'I' || letter == 'u' || letter == 'U')
		return true;
	else
		return false;
}

int main() {
	setlocale(LC_ALL, "");
	string str;
	bool flag = true;										/* Флаг наличия подходящего слова */
	try {
		ifstream fin("File.txt", ios::in);
		if (!fin)
			throw exception("Файл не открылся.");
		while (!fin.eof()) {								/* Пока не закончился файл */
			fin >> str;										/* Считываем слово (считывается последовательность символов до пробела) */
			if (vowel(str[0])) {							/* Проверяем первый символ слова */
				flag = false;								/* Нашли слово, меняем флаг наличия нужного слова */
				for (int i = 0; i < str.length(); ++i) {	/* Выводим строку, пока идут буквы (нужно для того, чтобы не выводились, например, точки, запятые и т.д.) */
					if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
						cout << str[i];
					else                                    /* Если не буква, то заканчиваем цикл */
						break;
				}
				cout << endl;								/* Разделитель между словами (переход на следующую строку) */
			}
		}
		if (flag)
			cout << "Подходящих слов нет." << endl;
		fin.close();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}