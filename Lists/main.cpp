#include <iostream>
#include <clocale>
#include "List.cpp"
#include <vector>

using namespace std;

template<typename T>
void inputList(List<T>& l); // ввод списка с клавиатуры

template<typename T>
void outList(List<T>& L); // вывод списка

template<typename T>
bool lIn(List<T>& L1, List<T>& L2); // проверка, содержится ли L2 в L1 как подписок

template<typename T>
vector<size_t> formArr(List<T>& L1, List<T>& L2); // формирование массива номеров элементов L2, не содержащихся в L1

template<typename T>
void delEl(List<T>& L, vector<size_t> arr); // удаление из списка узлов, индексы которых записаны в массиве

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
		cout << "Практическая работа №5 ИКБО-33-21 Эрднеева Н.Д. Варинат 29" << "\n\n"
			"Меню\n"
			"1) Ввод L1 и L2 с клавиатуры.\n"
			"2) Вывод L1 и L2.\n"
			"3) Определить, содержит ли L1 в себе L2 как подписок.\n"
			"4) Сформировать массив номеров элементов списка L2, которые не содержатся в L1.\n"
			"5) Удалить из L2 узлы, номера которых сохранены в массиве.\n"
			"6) Переместить часть списка в начало.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 1:
			cout << "Введите номер списка, который необходимо заполнить (1 или 2): ";
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
				cout << "Неверный ввод, введите 1 или 2\n";
				break;
			}
			system("pause");
			break;
		case 2:
			cout << "Введите номер списка, который необходимо вывести (1 или 2): ";
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
				cout << "Неверный ввод, введите 1 или 2\n";
				break;
			}
			system("pause");
			break;
		case 3:
			num = lIn(L1, L2);
			if (num == 1)
				cout << "Список L1 содержит список L2 как подсписок\n";
			else
				cout << "Список L1 не содержит список L2 как подсписок\n";
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
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз." << stop;
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
	cout << "\nВВедите x: ";
	cin >> x;
	cout << "\nВВедите y: ";
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
	cout << "Введите количество вводимых ячеек: ";
	cin >> size;
	cout << "Введите " << size << " значений: ";
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
		cout << "Пустo"<<endl;
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