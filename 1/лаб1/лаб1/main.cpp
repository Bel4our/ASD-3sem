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
		cout << "Переместить диск " << N << " с " << i << " на " << k << " стержень"<< endl;
		
	}
	else
	{
		int temp = 6 - i - k;
		hanoy(N - 1, i, temp);
		cout << "Переместить диск " << N << " с " << i << " на " << k << " стержень"<<endl;
		hanoy(N - 1, temp, k); 
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int N, k = 0, i = 1;

	cout << "Введите количество дисков: "; cin >> N;
	bool f1 = true;
	while (f1)
	{
		if (N<=0)
		{
			cout << "Вы ввели не правильное значение!" << endl;
			cout << "Введите количество дисков: "; cin >> N;
			continue;
		}
		f1 = false;
	}
	
	
	f1 = true;

	cout << "Введите начальную позицию: "; cin >> i;
	while (f1)
	{
		if (i < 1 || i>3)
		{
			cout << "Вы ввели не правильное число!!!!" << endl;
			cout << "Введите начальную позицию: "; cin >> i;
			continue;
		}
		f1 = false;
	}


	f1 = true;

	cout << "Введите конечную позицию: "; cin >> k;
	while (f1)
	{
		if (k < 1 || k>3)
		{
			cout << "Вы ввели не правильное число!!!!" << endl;
			cout << "Введите конечную позицию: "; cin >> k;
			continue;
		}
		f1 = false;
	}


	if (i == k)
	{
		cout << "Башню двигать не надо!";
	}
	else
	{
		auto start = high_resolution_clock::now();
		hanoy(N, i, k);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		cout << "Время выполнения: " << duration.count() << " миллисекунд" << endl;
		cout << "Количество шагов: " << counter;
	}



	return 0;
}