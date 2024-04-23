//NULL_TerminatedLines
#define _CRT_SECURE_NO_WARNINGS   // ����� �� ����������� ������ C4996, ����������� ������ ���� � ����� �����
#include<iostream>
#include<Windows.h>  // 48:00

using namespace std;

int string_length(const char str[]);
char* to_upper(char str[]);
char* to_lower(char str[]);
char* shrink(char str[]);
bool is_palindrom(const char str[]);

void main()
{
	for (int i = 0; i < 256; i++) cout << i << "\t" << (char)i << endl;  // ASCII table
	cout << 'a' - 'A' << endl;
	cout << (int)'a' << endl;
	cout << (int)'A' << endl;
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l','l', 'o', 0};
	//char str[] = "Hello";
	const int SIZE = 256;
	char str[SIZE] = " ������         ����     ��        �����      �����      ���";
	cout << "������� ������: "; 
	//cin >> str;
	SetConsoleCP(1251);   // cout ������� ������� � ��������� CP866, � cin ������������ ������� � ��������� 1251, ������� ������� ������������� 1251, ���� ���������� � CP866
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << shrink(str) << endl;
	cout << "������" << (is_palindrom(str) ? "" : " ��") << " ���������" << endl;
	//cout << "������� ������: "; 
	////cin >> str;
	//SetConsoleCP(1251);   // cout ������� ������� � ��������� CP866, � cin ������������ ������� � ��������� 1251, ������� ������� ������������� 1251, ���� ���������� � CP866
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	//cout << str << endl << "������ ������: " << string_length(str) << endl;
	//cout << "������ � ������� ��������: " << to_upper(str) << endl;
	//cout << "������ � ������ ��������: " << to_lower(str) <<  endl;
	




}

int string_length(const char str[])
{
	int i = 0; // �������, ������� ������� ������ ������
	for (; str[i]; i++);
	return i;
}
char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '�')str[i] -= 16;
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		
	}
	return str;
}
char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{

		str[i] = tolower(str[i]); // �������� ������ ���������� � ������ ��������

	//https://legacy.cplusplus.com/reference/cctype/tolower/

		/*if (str[i] == '�')str[i] += 16;
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += ' ';
		if (str[i] >= '�' && str[i] <= '�')str[i] += ' ';*/

	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_palindrom(const char str[])
{
	bool is_palindrom = true;
	int n = strlen(str);

	char* buffer = new char[n+1];
	strcpy(buffer, str);
	to_lower(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])is_palindrom= false;
	}
	delete[] buffer;
	return is_palindrom;
}