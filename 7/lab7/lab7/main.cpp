#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int N;

	while (true)
	{
		cout << "Введите количество элементов последовательности: ";
		cin >> N;
		if (N > 0)
		{
			break;
		}
	}
	int* sequence = new int[N];

	for (int i = 0;i < N;i++)
	{
		cin >> sequence[i];
	}

	int* lenSeq = new int[N];
	int* prev = new int[N];

	for (int i = 0; i < N;i++)
	{
		lenSeq[i] = 1;
		prev[i] = -1;
	}

	for (int i = 1; i < N; i++) 
	{
		for (int j = 0; j < i; j++)
		{
			if (sequence[i] > sequence[j] && lenSeq[i] <= lenSeq[j])
			{
				lenSeq[i] = lenSeq[j] + 1;
				prev[i] = j;
			}
		}
	}

	int maxLen=0, endIndex = 0;

	for (int i = 0; i < N; ++i) 
	{
		if (lenSeq[i] >= maxLen) 
		{
			maxLen = lenSeq[i];
			endIndex = i;
		}
	}

	int* lSequence = new int[maxLen];  
	int index = maxLen - 1;
	for (int i = endIndex; i != -1; i = prev[i])
	{
		lSequence[index--] = sequence[i];
	}

	cout << "Длина максимальной возрастающей подпоследовательности: " << maxLen << endl;
	cout << "Одна из максимальных возрастающих подпоследовательностей: ";
	for (int i = 0; i < maxLen; i++)
	{
		cout << lSequence[i] << " ";
	}

	cout << endl;

	delete[] sequence;
	delete[] lenSeq;
	delete[] prev;
	delete[] lSequence;

	return 0;
}