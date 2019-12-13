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
	bool flag = true;										/* ���� ������� ����������� ����� */
	try {
		ifstream fin("File.txt", ios::in);
		if (!fin)
			throw exception("���� �� ��������.");
		while (!fin.eof()) {								/* ���� �� ���������� ���� */
			fin >> str;										/* ��������� ����� (����������� ������������������ �������� �� �������) */
			if (vowel(str[0])) {							/* ��������� ������ ������ ����� */
				flag = false;								/* ����� �����, ������ ���� ������� ������� ����� */
				for (int i = 0; i < str.length(); ++i) {	/* ������� ������, ���� ���� ����� (����� ��� ����, ����� �� ����������, ��������, �����, ������� � �.�.) */
					if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
						cout << str[i];
					else                                    /* ���� �� �����, �� ����������� ���� */
						break;
				}
				cout << endl;								/* ����������� ����� ������� (������� �� ��������� ������) */
			}
		}
		if (flag)
			cout << "���������� ���� ���." << endl;
		fin.close();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}