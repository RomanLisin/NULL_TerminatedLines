//NULL_TerminatedLines
#include<iostream>

using namespace std;

int string_length(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l','l', 'o', 0};
	//char str[] = "Hello";
	const int SIZE = 256;
	char str[SIZE];
	cout << "������� ������: "; 
	//cin >> str;
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "������ ������: " << string_length(str) << endl;




}

int string_length(const char str[])
{
	int i = 0; // �������, ������� ������� ������ ������
	for (; str[i]; i++);
	return i;
}