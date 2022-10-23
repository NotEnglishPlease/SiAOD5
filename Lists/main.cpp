#include <iostream>
#include <clocale>
#include "List.cpp"
#include <vector>

using namespace std;

template<typename T>
void inputList(List<T>& l); // ���� ������ � ����������

template<typename T>
void outList(List<T>& L); // ����� ������

template<typename T>
bool lIn(List<T>& L1, List<T>& L2); // ��������, ���������� �� L2 � L1 ��� ��������

template<typename T>
vector<size_t> formArr(List<T>& L1, List<T>& L2); // ������������ ������� ������� ��������� L2, �� ������������ � L1

template<typename T>
void delEl(List<T>& L, vector<size_t> arr); // �������� �� ������ �����, ������� ������� �������� � �������

template<typename T>
void swapEl(List<T>& L);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	string stop = "\n----------------------------------------------------------------------------\n";
	int problem, flag = 1, num = 0;
	List<int> L1;
	List<int> L2;
	vector<size_t>arr;


	while (flag)
	{
		system("cls");
		cout << "������������ ������ �5 ����-33-21 �������� �.�. ������� 29" << "\n\n"
			"����\n"
			"1) ���� L1 � L2 � ����������.\n"
			"2) ����� L1 � L2.\n"
			"3) ����������, �������� �� L1 � ���� L2 ��� ��������.\n"
			"4) ������������ ������ ������� ��������� ������ L2, ������� �� ���������� � L1.\n"
			"5) ������� �� L2 ����, ������ ������� ��������� � �������.\n"
			"6) ����������� ����� ������ � ������.\n";
		cout << "��� �����: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "������� ����� ������, ������� ���������� ��������� (1 ��� 2): ";
			cin >> num;
			switch (num)
			{
			case 1:
				inputList(L1);
				break;
			case 2: 
				inputList(L2);
				break;
			default:
				cout << "�������� ����, ������� 1 ��� 2\n";
				break;
			}
			system("pause");
			break;
		case 2:
			cout << "������� ����� ������, ������� ���������� ������� (1 ��� 2): ";
			cin >> num;
			switch (num)
			{
			case 1:
				outList(L1);
				break;
			case 2:
				outList(L2);
				break;
			default:
				cout << "�������� ����, ������� 1 ��� 2\n";
				break;
			}
			system("pause");
			break;
		case 3:
			num = lIn(L1, L2);
			if (num == 1)
				cout << "������ L1 �������� ������ L2 ��� ���������\n";
			else
				cout << "������ L1 �� �������� ������ L2 ��� ���������\n";
			system("pause");
			break;
		case 4:
			arr = formArr(L1, L2);
			for (int i = 0; i < arr.size(); i++) {
				cout << arr[i]<<" ";
			}
			cout << endl;
			system("pause");
			break;
		case 5:
			delEl(L2, arr);
			system("pause");
			break;
		case 6:
			swapEl(L1);
			break;
		default:
			cout << "��������, � �� ������ �������, ��� �� ������ �������. ���������� � ������ ���." << stop;
			system("pause");
		}
	}
	return 0;
}

template<typename T>
void swapEl(List<T>& L)
{
	List<int> tempL;
	int x, y, Size = L.getSize();
	cout << "\n������� x: ";
	cin >> x;
	cout << "\n������� y: ";
	cin >> y;
	for (int i = x; i <= y; i++) {
		tempL.pushFront(L[i]);
	}
	for (int i = y; i >= x; i--) {
		L.earase(i);
	}
	int currSize = L.getSize();
	for (int i = 0; i < Size-currSize; i++) {
		L.pushFront(tempL[i]);
	}
}

template<typename T>
void inputList(List<T>& l)
{
	size_t size;
	T x;
	cout << "������� ���������� �������� �����: ";
	cin >> size;
	cout << "������� " << size << " ��������: ";
	for (size_t i = 0; i < size; i++)
	{
		cin >> x;
		l.pushFront(x);
	}
}

template<typename T>
void outList(List<T>& L)
{
	if (L.getSize())
	{
		size_t size = L.getSize();
		for (size_t i = 0; i < size; i++)
		{
			cout << L[i] << " ";
		}
	}
	else
	{
		cout << "����o"<<endl;
	}
}

template<typename T>
bool lIn(List<T>& L1, List<T>& L2) {
	size_t size1 = L1.getSize();
	size_t size2 = L2.getSize();
	if (size1 >= size2) {
		bool flag = 1;
		for (size_t i = 0; i < size2; i++) 
			if (L1.lFind(L2[i]) == -1) {
				flag = 0;
				break;
			}
		return flag;
	}
	else {
		return 0;
	}
}

template<typename T>
vector<size_t> formArr(List<T>& L1, List<T>& L2) {
	size_t size1 = L1.getSize();
	size_t size2 = L2.getSize();
	vector<size_t>arr;
	if (size1 >= size2) {
		for (size_t i = 0; i < size2; i++)
			if (L1.lFind(L2[i]) == -1)
				arr.push_back(i);
	}
	return arr;
}

template<typename T>
void delEl(List<T>& L, vector<size_t> arr) {
	for (int i = (arr.size()-1); i >= 0; i--) {
		L.earase(arr[i]);
	}
}