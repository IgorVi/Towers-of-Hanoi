#include"Hanoi.h"

void main()
{
	system("color 20");
	SetConsoleTitleA("Hanoiskie bachni");
	system("mode con cols = 51 lines = 31");
	int disc = 7;
	int const size = 7;
	int from, to;
	cout << "\n\n\n\tDOBRO POJALOVAT!\n\n\n";
	cout << "Vvedite " << endl;
	cout << "From: ";
	cin >> from;
	cout << "To: ";
	cin >> to;
	int ar[size][3] = { 0 };
	Init(ar, size, from);

	OutputScreen(ar, size);
	Hanoi(ar, size, disc, from, to);
	system("pause");
}