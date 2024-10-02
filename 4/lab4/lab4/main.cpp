#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	int const N = 6;
	
	int D[N][N] = {
		{0, 28, 21, 59, 12, 27},
		{7, 0, 24, INT_MAX, 21, 9},
		{9, 32, 0, 13, 11,INT_MAX},
		{8,INT_MAX,5,0,16,INT_MAX},
		{14,13,15,10,0,22},
		{15,18,INT_MAX,INT_MAX,6,0}
	};
	
	int S[N][N] = {
		{0,2,3,4,5,6},
		{1,0,3,4,5,6},
		{1,2,0,4,5,6},
		{1,2,3,0,5,6},
		{1,2,3,4,0,6},
		{1,2,3,4,5,0}
	};

	for (int m = 0; m < N; m++)
	{
		for (int i = 0; i < N;i++)
		{
			for (int j = 0; j < N;j++)
			{
				if (D[i][j] > D[i][m] + D[m][j])
				{
					D[i][j] = D[i][m] + D[m][j];
					S[i][j] = m + 1;
				}
			}
		}
	}

	cout << "Матрица D" << endl;

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << D[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "Матрица S" << endl;

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << S[i][j] << " ";
		}
		cout << endl;
	}


	int choice1;
	int choice2;

	while (true)
	{
		cout << "Введите начальную вершину: ";
		cin >> choice1;
		if (choice1 >= 1 && choice1 <= 6)
		{
			break;
		}
	}


	while (true)
	{
		cout << "Введите конечуню вершину: ";
		cin >> choice2;
		if (choice2 >= 1 && choice2 <= 6)
		{
			break;
		}
	}

	choice1--;
	choice2--;

		cout << "Кратчайший путь из вершины " << choice1 + 1 << " в вершину " << choice2 + 1 << " имеет длину: " << D[choice1][choice2] << endl;

		cout << "Путь: " << choice1 + 1 << " ";
		int cur1 = choice1;
		int cur2 = choice2;

		int buf = S[cur1][cur2] - 1;

		while (buf!=cur2)
		{ 
			cout << S[cur1][cur2]<< " ";
			cur1 = cur2;
			cur2 = buf;

		}
		cout << choice2 + 1 << " ";
		cout << endl;
	return 0;
}