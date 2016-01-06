#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

// Инициализация
void Init(int ar[][3], int size, int from)
{
	for (int i = 0; i < size; i++)
	{
		ar[i][from - 1] = i + 1;
	}
}

void Line(int nstars)
{
	unsigned char a = 186, b = 219;
	(nstars % 2 == 0) ? b = 176 : b == 219;
	int i; 
	if (!nstars)
	{ 
		for (i = 0; i < 6; i++)
			cout << ' ';
		cout << a;
		for (i = 0; i < 6; i++)
			cout << ' ';
	}
	else{
		int nspaces = 7 - nstars;
		nstars += (nstars - 1);
		for (i = 0; i < nspaces; i++)
			cout << ' ';
		for (i = 0; i < nstars; i++)
			cout << b;
		for (i = 0; i < nspaces; i++)
			cout << ' ';
	}
}

void OutputScreen(int mas[][3], int size)
{
	system("cls"); // ochistka ekrana
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < 3; j++)
		{
			Line(mas[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	Sleep(1500); 
}



void move(int mas[][3], int str, int from, int to)
{
	from--;
	to--;
	int temp;
	for (int i = 0; i < str; i++)
	{
		if (mas[i][from] > 0)
		{
			temp = mas[i][from];
			mas[i][from] = 0;
			break;
		}
	}

	for (int i = 0; i < str; i++)
	{
		if (mas[str - 1][to] == 0)
		{
			mas[str - 1][to] = temp;
			break;
		}
		if (mas[i][to] > 0)
		{
			mas[i - 1][to] = temp;
			break;
		}
	}
	OutputScreen(mas, str);
}

void Hanoi(int mas[][3], int size, int disc, int from, int to)
{
	if (disc == 0)
	{
		return;
	}
	else if (disc == 1)
	{
		move(mas, size, from, to);
	}
	else if (disc > 1)
	{
		Hanoi(mas, size, disc - 1, from, 6 - (from + to));
		move(mas, size, from, to);

		Hanoi(mas, size, disc - 1, 6 - (from + to), to);
	}
}

