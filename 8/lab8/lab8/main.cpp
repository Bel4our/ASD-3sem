#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 0; 

	while (true)
	{
		cout << "������� ����������� �������: "; cin >> N;
		if (N <=0)
		{
			cout << "����������� �� ����� ���� ������������� ��� ������ ����!"<< endl;
			continue;
		}
		break;
	}

	cout << endl;

	int goodsCount = 0;

	while (true)
	{
		cout << "������� ���������� �������: "; cin >> goodsCount;
		if (goodsCount <= 0)
		{
			cout << "�� ����� ������������ ��������!" << endl;
			continue;
		}
		break;
	}

	struct Good {
		string name;
		int weight;
		int cost;
	};

	Good *goods = new Good [goodsCount];
	for (int i = 0;i < goodsCount;i++)
	{
		Good buf;
		cin.ignore();
		cout << "������� �������� ������: ";
		getline(cin, buf.name);
		while (true)
		{
			cout << "������� ��� ������: ";
			cin >> buf.weight;
			if (buf.weight <= 0)
			{
				cout << "�� ����� ������������ ��������!" << endl;
				continue;
			}
			break;
		}
		while (true)
		{
			cout << "������� ��������� ������: ";
			cin >> buf.cost;
			if (buf.cost <= 0)
			{
				cout << "�� ����� ������������ ��������!" << endl;
				continue;
			}
			break;
		}
		goods[i] = buf;
		cout << endl;
	}


	int** D = new int *[goodsCount+1];
	for (int i = 0; i < goodsCount+1; i++)
	{
		D[i] = new int[N+1];
	}

	for (int i = 0; i < goodsCount;i++)
	{
		for (int j = 0;j < N;j++)
		{
			D[i][j] = 0;
		}
	}



	for (int i = 1; i <= goodsCount; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			if (goods[i - 1].weight <= j)
			{
				D[i][j] = max(D[i - 1][j], D[i - 1][j - goods[i - 1].weight] + goods[i - 1].cost);
			}
			else
			{
				D[i][j] = D[i - 1][j];
			}
		}
	}

	int maxCost = max(D[goodsCount][N],0);
	cout << "������������ ��������� ������� � �������: " << maxCost << endl;
	

	cout << "�������� �������: " <<endl;
	int w = N;
	for (int i = goodsCount; i > 0 && maxCost > 0; i--) 
	{
		if (maxCost != D[i - 1][w]) 
		{
			cout << (goods[i - 1].name) << endl;
			maxCost -= goods[i - 1].cost;
			w -= goods[i - 1].weight;
		}
	}
	return 0;
	
}