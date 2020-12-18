// Laba2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

short int menu();
void massiv();
void Task1();
void Task2();
void Task3_unsort();
void Task3_sort();
void Task4();
void Task5();
void Task6();
void Task7();
void Task8();

int main() // ����
{
	setlocale(LC_ALL, "Russian");
	short int choose_menu, exit = 0;

	while (1)
	{
		choose_menu = menu();
		switch (choose_menu)
		{
		case 1:
			Task1(); massiv(); system("pause"); system("cls");
			break;
		case 2:
			Task1(); Task2(); massiv(); system("pause"); system("cls");
			break;
		case 3:
			Task3_unsort(); Task3_sort(); system("pause"); system("cls");
			break;
		case 4:
			Task4(); massiv(); system("pause"); system("cls");
			break;
		case 5:
			Task5(); system("pause"); system("cls");
			break;
		case 6:
			Task6(); system("pause"); system("cls");
			break;
		case 7:
			Task7(); system("pause"); system("cls");
			break;
		case 8:
			Task8(); system("pause"); system("cls");
			break;
		case 9:return 0;
			break;
		}
		cout << endl;
	}
}

int arr[100];
short int menu() // ����, ����� �������
{
	setlocale(LC_ALL, "Russian");
	short int i;
	cout << "������������ ������ �2 \n\n";
	cout << "������� ����� �� 1 �� 9, ����� ��������� ��������������� ������:\n";
	cout << "1) ������� ������������� ������ ����������� N = 100. �������� ������� ������ ��������� ��������� �������� � ��������� �� - 99 �� 99\n";
	cout << "2) ������������� �������� � ������ 1 ������ [�] ����������� (�� �������� � ��������). ���������� �����, ����������� �� ����������, ��������� ���������� chrono.\n";
	cout << "3) ����� ������������ � ����������� ������� �������. ����������� ����� ������ ���� ��������� � ��������������� ������� � �����������������, ��������� ���������� chrono.\n";
	cout << "4) ������� ������� �������� (���� ����������, ����� ����� ���������) ������������� � ������������ ��������. ������� ������� ���� ���������, ������� ����� ����� ��������, � �� ����������.\n";
	cout << "5) ������� ���������� ��������� � ��������������� �������, ������� ������ ����� a, ������� ���������������� �������������.\n";
	cout << "6) ������� ���������� ��������� � ��������������� �������, ������� ������ ����� b, ������� ���������������� �������������.\n";
	cout << "7) ������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� �������. ���������� �������� ��������� ������. �������� �������� ��� ������ � ������� ���������. (*)\n";
	cout << "8) ������ ������� �������� �������, ������� ������� ������ ������������. �������� �������� ������, ��������� ���������� chrono.\n";
	cout << "9) �����\n" << endl;
	cout << "������� � ������: ";

	while (1)
	{
		cin >> i;
		if ((i > 0) & (i <= 9))
			break;
		else
			cout << "������������ ����, ��������� �������.\n";
	}
	cout << "\n";
	return i;
}

void Task1() // ���������� ������� ���������� ������� �� -99 �� 99
{
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 199 - 99;
	}
}

void massiv() // ����� �������
{
	for (int i = 0; i < 100; i++)
	{
		cout << '[' << i << ']' << arr[i] << " ";
	}
	cout << endl;
}

void Task2() // ���������� �������
{
	system_clock::time_point start = system_clock::now();

	int iRight = 99;
	int iLeft = 0;
	int iSwap = iRight;

	for (int g = 0; g < 100; g++)
	{
		for (int i = iLeft; i < iRight; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				iSwap = i;
			}
		}
		iRight = iSwap;

		for (int i = iRight; i > iLeft; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				std::swap(arr[i], arr[i - 1]);
				iSwap = i;
			}
		}
		iLeft = iSwap;

		if (iLeft >= iRight) break;
	}

	system_clock::time_point end = system_clock::now();
	duration<double> sort = end - start;

	cout << "����� ����������: " << std::fixed << sort.count() << "���" << endl << endl;
}

void Task3_unsort() // ������������ � ����������� �������� ������������������ �������. ����� ������.
{
	auto startMaxMinUnsort = system_clock::now();

	Task1();
	massiv();
	int min = 100, max = -100;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	auto endMaxMinUnsort = system_clock::now();
	duration<double> sortMaxMinUnsort = endMaxMinUnsort - startMaxMinUnsort;

	cout << std::fixed << "����� ������ ������������� � ������������ ��������� � ����������������� �������: " << sortMaxMinUnsort.count() << "���" << endl << endl;
	cout << "������������ �������: " << max << endl << endl;
	cout << "����������� �������:" << min << endl << endl;
}

void Task3_sort() // ������������ � ����������� �������� � ��������������� �������.
{
	auto startMaxMinSort = system_clock::now();

	Task1();
	Task2();
	massiv();

	system_clock::time_point endMaxMinSort = system_clock::now();
	duration<double> sortMaxMin = endMaxMinSort - startMaxMinSort;
	cout << endl;
	cout << "����� ������ ������������� � ������������ ��������� � ��������������� �������: " << std::fixed << sortMaxMin.count() << "���" << endl << endl;
	cout << "������������ �������: " << arr[99] << endl << endl;
	cout << "����������� �������:" << arr[0] << endl << endl;
}


void Task4() // ������� �������� ������������ � ������������� ���������. ���-�� ��������� �������, ������ �������� �������� � �� ������
{
	Task1();

	int min = 100, max = -100, average;
	for (int i = 0; i < 100; i++) // ����� ������������ � ������������� ��������
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	average = (min + max) / 2; // ����� �������� ��������

	cout << endl;
	cout << "������������ �������: " << max << endl << endl;
	cout << "����������� �������:" << min << endl << endl;
	cout << "������� �������� ������������� � ������������ ��������� ������� = " << average << endl << endl;

	int count = 0;

	for (int i = 0; i < 100; i++) // ������ �������� ��������
	{
		if (arr[i] == average)
		{
			cout << "[" << i << "]" << arr[i] << endl;
			count += 1;
		}
	}
	cout << endl;
	if (count == 0)
		cout << "� ������� ��� ���������, ������ �������� ��������." << endl << endl;

	else if (count == 1)
		cout << "������ ���� �������, ������ �������� ��������." << endl << endl;
	else if (count >= 2 && count <= 4) cout << "������� " << count << " ��������, ������ �������� ��������." << endl << endl;
	else cout << "�������" << count << "���������, ������ �������� ��������." << endl << endl;
}

void Task5() // ���������� ��������� �������, ������ ���������� �����
{
	Task1();
	Task2();
	massiv();

	int a, z = 0;
	cout << endl;
	cout << "������� ����� a: ";
	cin >> a;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] < a) z++;
	}
	cout << endl;
	cout << "���������� ��������� ������� ������ ���������� �����: " << z << endl << endl;
}

void Task6() // ���������� ��������� �������, ������ ���������� �����
{
	Task1();
	Task2();
	massiv();

	int b, x = 0;
	cout << endl;
	cout << "������� ����� b: ";
	cin >> b;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] > b) x++;
	}
	cout << endl;
	cout << "���������� ��������� ������� ������ ���������� �����: " << x << endl << endl;
}

void Task7() // �������� �����
{
	Task1();
	Task2();
	massiv();
	int bin, min = 0, max = 100, mid;
	bool key = false;
	cout << endl;
	cout << "������� ������� �����: ";
	cin >> bin;
	cout << endl;

	system_clock::time_point start1 = system_clock::now();

	while (min <= max) // �������� �����
	{
		mid = (min + max) / 2;
		if (arr[mid] == bin) break;
		if (arr[mid] < bin) min = mid + 1;
		if (arr[mid] > bin) max = mid - 1;
	}
	if (arr[mid] == bin) {
		cout << "��������� ������� ���� � �������, ������: " << mid << endl << endl;
	}
	else {
		cout << "���������� �������� ��� � �������." << endl << endl;
	}
	system_clock::time_point end1 = system_clock::now();
	duration<double> sort1 = end1 - start1;

	system_clock::time_point start2 = system_clock::now();
	for (int i = 0; i < 100; i++) { // ����� ���������
		if (arr[i] == bin) {
			key = true;
		}
	}
	system_clock::time_point end2 = system_clock::now();
	duration<double> sort2 = end2 - start2;

	cout << fixed << "������� ����� �������� ������� � ���������: " << sort1.count() - sort2.count() << " ������." << endl;
	cout << endl;
}

void Task8() // ������ ������� �������� �������, ������� ������� ������ ������������
{
	int one, two;
	cout << "������� ������� ��-��� �������, ������� �� ������ �������� �������: " << endl;
	cin >> one >> two;
	cout << endl;
	Task1();
	massiv();
	cout << endl;
	system_clock::time_point start = system_clock::now();

	swap(arr[one], arr[two]);

	system_clock::time_point end = system_clock::now();
	duration<double> sort = end - start;

	cout << "�������� ������������ = " << std::fixed << sort.count() << " ���." << endl << endl;

	massiv();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
