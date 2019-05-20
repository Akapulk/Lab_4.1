#include <iostream>
#include <locale>
#include <ctime>
#include <string>
#include <exception>

using namespace std;

template <typename T>
void average(T* ptr, int size);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int size;
	try {
		size = rand() % 101 - 20;
		if (size <= 0) {
			exception ex("������ ������� �� ����� ���� ������������� ��� ����� 0");
			throw ex;
		}
	}
	catch(exception & ex){
		while (size <= 0)
		{
			cout << ex.what() << endl << endl;
			cout << "������� ���������� ������ �������: ";
			cin >> size;
		}
		system("pause");
	}

	//�������� ��������
	int* int_mass = new int[size];
	char* char_mass = new char[size];
	float* float_mass = new float[size];
	double* double_mass = new double[size];
    string* string_mass = new string[size];

	//������������ ��������� �������� ��������� ��������
	for (int i = 0; i < size; ++i) {
		int_mass[i] = rand() % 101;
		char_mass[i] = rand() % 26 + 65;
		float_mass[i] = (float)(rand()) / RAND_MAX * 100;
		double_mass[i] = (double)(rand()) / RAND_MAX * 100;
		string_mass[i] = rand() % 26 + 65;
	}

	int menu;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "������ �������: " << size << endl << endl;
		cout << "�������� ���" << endl << endl;
		cout << "1 - int" << endl;
		cout << "2 - char" << endl;
		cout << "3 - float" << endl;
		cout << "4 - double" << endl;
		cout << "5 - string" << endl;
		cout << "0 - �����" << endl << endl;
		cout << "�������� ���: ";
		cin >> menu;
		if (cin.fail()) {
			menu = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (menu) {
		case 1: average(int_mass, size); break;
		case 2: average(char_mass, size); break;
		case 3: average(float_mass, size); break;
		case 4: average(double_mass, size); break;
		case 5: average(string_mass, size); break;
		case 0: flag = false;
		}
	}

	delete[] int_mass;
	delete[] char_mass;
	delete[] float_mass;
	delete[] double_mass;
	delete[] string_mass;

	return 0;
}

template <typename T>
void average(T* ptr, int size)
{
	//���� ��� ������� string
	if (typeid(T) == typeid(string))
	{
		//������� ���������� ���������
		int sum = 0;
		for (int i = 0; i < size; ++i)
			++sum;

		cout << "����� ���������� ������ � ������� stirng: " << sum << endl << endl; 
	}
	else
	{
		T sum = 0;
		cout << "������: ";
		for (int i = 0; i < size; ++i)
		{
			cout << ptr[i] << " ";
			sum = sum + ptr[i];
		}
		//����� �������� �� "sum / size", ��� ��� ����� string ���������� 
		//cout << endl << endl << "������� ��������: " << sum / size << endl;

		//��� ��� ��������
		cout << endl << endl << "����� ���������: " << sum << endl;
	}

	system("pause");
}