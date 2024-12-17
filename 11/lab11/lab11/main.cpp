#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

bool firstAlg(int N, int** room)
{
	bool isGood = true;
	int box;
	for (int i = 1; i <= 100; i++)
	{
		isGood = false;
		box = i;
		for (int j = 0; j < 50; j++)
		{
			if (room[(box - 1) / 10][(box - 1) % 10] == i)
			{
				isGood = true;
				break;
			}
			box = room[(box - 1) / 10][(box - 1) % 10];
		}

		if (!isGood)
		{
			break;
		}
	}
	return isGood;
}

bool secondAlg(int N, int** room)
{
	bool isGood = true;
	for (int i = 1; i <= 100; i++)
	{
		int visited[10][10] = { 0 };
		isGood = false;
		for (int j = 0; j < 50; j++)
		{
			int k;
			int n;
			while (true)
			{
				k = rand() % 10;
				n = rand() % 10;
				if (visited[k][n] == 0)
				{	
					visited[k][n] = 1;
					break;
				}
			}

			if (room[k][n] == i)
			{
				isGood = true;
				break;
			}
			
		}

		if (!isGood)
		{
			return false;
		}
	}
	return isGood;
}



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));


	int** room = new int* [10];
	for (int i = 0; i < 10;i++)
	{
		room[i] = new int[10];
	}

	int counter = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			room[i][j] = ++counter;
		}
	}

	int N;

	while (true)
	{
		cout << "Введите число попыток: ";
		cin >> N;
		if (N <= 0)
		{
			cout << "Вы ввели неправильное значение!" << endl;
			continue;
		}
		break;
	}


	int countF = 0;
	int countS = 0;
	for (int i = 0;i < N;i++)
	{
		for (int a = 0; a < 10; a++)
		{
			for (int j = 0; j < 10; j++)
			{
				int k = rand() % 10;
				int t = rand() % 10;
				int temp = room[a][j];
				room[a][j] = room[k][t];
				room[k][t] = temp;
			}
		}

		if (firstAlg(N, room))
		{
			countF++;
		}
		if (secondAlg(N, room))
		{
			countS++;
		}
	}
	cout << "Успешные исходы случайным способом: " << countS <<endl;
	cout << "Успешные исходы выбором номера в коробке: " << countF;



	return 0;
}