#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void hanoy(int N, int i, int k);

int counter=0;

void hanoy(int N, int i, int k)
{
	counter++;

	if (N == 1)
	{
		cout << "����������� ���� " << N << " � " << i << " �� " << k << " ��������"<< endl;
		
	}
	else
	{
		int temp = 6 - i - k;
		hanoy(N - 1, i, temp);
		cout << "����������� ���� " << N << " � " << i << " �� " << k << " ��������"<<endl;
		hanoy(N - 1, temp, k); 
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int N, k = 0, i = 1;

	cout << "������� ���������� ������: "; cin >> N;
	bool f1 = true;
	while (f1)
	{
		if (N<=0)
		{
			cout << "�� ����� �� ���������� ��������!" << endl;
			cout << "������� ���������� ������: "; cin >> N;
			continue;
		}
		f1 = false;
	}
	
	
	f1 = true;

	cout << "������� ��������� �������: "; cin >> i;
	while (f1)
	{
		if (i < 1 || i>3)
		{
			cout << "�� ����� �� ���������� �����!!!!" << endl;
			cout << "������� ��������� �������: "; cin >> i;
			continue;
		}
		f1 = false;
	}


	f1 = true;

	cout << "������� �������� �������: "; cin >> k;
	while (f1)
	{
		if (k < 1 || k>3)
		{
			cout << "�� ����� �� ���������� �����!!!!" << endl;
			cout << "������� �������� �������: "; cin >> k;
			continue;
		}
		f1 = false;
	}


	if (i == k)
	{
		cout << "����� ������� �� ����!";
	}
	else
	{
		auto start = high_resolution_clock::now();
		hanoy(N, i, k);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		cout << "����� ����������: " << duration.count() << " �����������" << endl;
		cout << "���������� �����: " << counter;
	}



	return 0;
}