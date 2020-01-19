#include "funkcje.h"
#include <iostream>
#include <random>
#include <Windows.h>
#include <string>
#include <cstdlib>
using namespace std;
int licznik_1 = {};
int licznik_2 = {};
int plansza1[10][10] = {};
int plansza2[10][10] = {};
void ustawstatki(int plansza[10][10], int rm)
{

	int x, y, k;

	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> losowa(0, 9);
	uniform_int_distribution<int> losowa1(1, 4);

	//losowanie po³o¿enia
start:
	x = losowa(generator);
	y = losowa(generator);
	//losowanie kierunku
	//1-góra
	//2-prawo
	//3-dó³
	//4-lewo
	k = losowa1(generator);
	if (k == 1)
		if (x - rm >= 0 && plansza[x][y] == 0 && plansza[x - rm][y] == 0)
			for (int h = 0; h < rm; h++)
			{
				if (plansza[x - h][y] == 0)
					plansza[x - h][y] = rm;
				if (y != 9 && plansza[x - h][y + 1] == 0)
					plansza[x - h][y + 1] = -1;
				if (y != 0 && plansza[x - h][y - 1] == 0)
					plansza[x - h][y - 1] = -1;
				if (x != 9 && plansza[x + 1][y] == 0)
					plansza[x + 1][y] = -1;
				if (x != 9 && y != 9 && plansza[x + 1][y + 1] == 0)
					plansza[x + 1][y + 1] = -1;
				if (x != 9 && y != 0 && plansza[x + 1][y - 1] == 0)
					plansza[x + 1][y - 1] = -1;
				if (x != 0 && plansza[x - rm][y] == 0)
					plansza[x - rm][y] = -1;
				if (x != 0 && y != 9 && plansza[x - rm][y + 1] == 0)
					plansza[x - rm][y + 1] = -1;
				if (x != 0 && y != 0 && plansza[x - rm][y - 1] == 0)
					plansza[x - rm][y - 1] = -1;

			}
		else
			goto start;
	if (k == 2)
		if (y + rm < 10 && plansza[x][y] == 0 && plansza[x][y + rm] == 0)

			for (int g = 0; g < rm; g++)
			{
				if (plansza[x][y + g] == 0)
					plansza[x][y + g] = rm;
				if (x != 0 && plansza[x - 1][y + g] == 0)
					plansza[x - 1][y + g] = -1;
				if (x != 9 && plansza[x + 1][y + g] == 0)
					plansza[x + 1][y + g] = -1;
				if (y != 0 && plansza[x][y - 1] == 0)
					plansza[x][y - 1] = -1;
				if (y != 0 && x != 0 && plansza[x - 1][y - 1] == 0)
					plansza[x - 1][y - 1] = -1;
				if (y != 0 && x != 9 && plansza[x + 1][y - 1] == 0)
					plansza[x + 1][y - 1] = -1;
				if (y != 9 && plansza[x][y + rm] == 0)
					plansza[x][y + rm] = -1;
				if (y != 9 && x != 9 && plansza[x + 1][y + rm] == 0)
					plansza[x + 1][y + rm] = -1;
				if (y != 9 && x != 0 && plansza[x - 1][y + rm] == 0)
					plansza[x - 1][y + rm] = -1;
			}
		else
			goto start;

	if (k == 3)
		if (x + rm < 10 && plansza[x][y] == 0 && plansza[x + rm][y] == 0)
			for (int z = 0; z < rm; z++)
			{
				if (plansza[x + z][y] == 0)
					plansza[x + z][y] = rm;
				if (y != 0 && plansza[x + z][y - 1] == 0)
					plansza[x + z][y - 1] = -1;
				if (y != 9 && plansza[x + z][y + 1] == 0)
					plansza[x + z][y + 1] = -1;
				if (x != 0 && plansza[x - 1][y] == 0)
					plansza[x - 1][y] = -1;
				if (x != 0 && y != 0 && plansza[x - 1][y - 1] == 0)
					plansza[x - 1][y - 1] = -1;
				if (x != 0 && y != 9 && plansza[x - 1][y + 1] == 0)
					plansza[x - 1][y + 1] = -1;
				if (x != 9 && plansza[x + rm][y] == 0)
					plansza[x + rm][y] = -1;
				if (x != 9 && y != 9 && plansza[x + rm][y + 1] == 0)
					plansza[x + rm][y + 1] = -1;
				if (x != 9 && y != 0 && plansza[x + rm][y - 1] == 0)
					plansza[x + rm][y - 1] = -1;
			}
		else
			goto start;
	if (k == 4)
		if (y - rm >= 0 && plansza[x][y] == 0 && plansza[x][y - rm] == 0)

			for (int v = 0; v < rm; v++)
			{
				if (plansza[x][y - v] == 0)
					plansza[x][y - v] = rm;
				if (x != 0 && plansza[x - 1][y - v] == 0)
					plansza[x - 1][y - v] = -1;
				if (x != 9 && plansza[x + 1][y - v] == 0)
					plansza[x + 1][y - v] = -1;
				if (y != 9 && plansza[x][y + 1] == 0)
					plansza[x][y + 1] = -1;
				if (y != 9 && x != 9 && plansza[x + 1][y + 1] == 0)
					plansza[x + 1][y + 1] = -1;
				if (y != 9 && x != 0 && plansza[x - 1][y + 1] == 0)
					plansza[x - 1][y + 1] = -1;
				if (y != 0 && plansza[x][y - rm] == 0)
					plansza[x][y - rm] = -1;
				if (y != 0 && x != 0 && plansza[x - 1][y - rm] == 0)
					plansza[x - 1][y - rm] = -1;
				if (y != 0 && x != 9 && plansza[x + 1][y - rm] == 0)
					plansza[x + 1][y - rm] = -1;
			}
		else
			goto start;
}

void wyswietlstatki(int plansza[10][10])
{
	char litera = 65;
	for (int i = 0; i < 10; i++)
	{
		cout.width(2);
		cout << " " << litera;
		litera++;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.width(1);
		cout << i;
		for (int j = 0; j < 10; j++)
		{

			if (plansza1[i][j] == 0)

				cout << " . ";
			if (plansza1[i][j] == -1)

				cout << " . ";
			if (plansza1[i][j] == 1)

				cout << " # ";
			if (plansza1[i][j] == 2)

				cout << " # ";
			if (plansza1[i][j] == 3)

				cout << " # ";
			if (plansza1[i][j] == 4)

				cout << " # ";


		}
		cout << endl;
	}
}

void wyswietlstatkiwroga(int plansza[10][10])
{
	char litera1 = 65;
	for (int i = 0; i < 10; i++)
	{
		cout.width(2);
		cout << " " << litera1;
		litera1++;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.width(1);
		cout << i;
		for (int j = 0; j < 10; j++)
		{

			if (plansza2[i][j] == 0)

				cout << " . ";
			if (plansza2[i][j] == -1)

				cout << " . ";
			if (plansza2[i][j] == 1)

				cout << " . ";
			if (plansza2[i][j] == 2)

				cout << " . ";
			if (plansza2[i][j] == 3)

				cout << " . ";
			if (plansza2[i][j] == 4)

				cout << " . ";


		}
		cout << endl;
	}
}

void twojstrzal(int plansza[10][10], int iks, int igrek)
{
	if (plansza2[iks][igrek] == 0)
	{
		plansza2[iks][igrek] = 5;
		cout << " PUDLO " << endl;
	}
	if (plansza2[iks][igrek] == -1)
	{
		plansza2[iks][igrek] = 5;
		cout << " PUDLO " << endl;
	}
	if (plansza2[iks][igrek] == 1)
	{
		plansza2[iks][igrek] = 6;
		cout << " TRAFIONY I ZATOPIONY " << endl;
		licznik_2++;
	}
	if (plansza2[iks][igrek] == 2)
	{
		plansza2[iks][igrek] = 7;
		cout << " TRAFIONY " << endl;
		zatapianie(plansza2, 2, 7, licznik_2);
	}
	if (plansza2[iks][igrek] == 3)
	{
		plansza2[iks][igrek] = 8;
		cout << " TRAFIONY " << endl;
		zatapianie(plansza2, 3, 8, licznik_2);
	}
	if (plansza2[iks][igrek] == 4)
	{
		plansza2[iks][igrek] = 9;
		cout << " TRAFIONY " << endl;
		zatapianie(plansza2, 4, 9, licznik_2);

	}
}

void strzalwroga(int plansza[10][10], int iks1, int igrek1)
{
	if (plansza1[iks1][igrek1] == 0)
	{
		plansza1[iks1][igrek1] = 5;
		cout << " PUDLO " << endl;
	}
	if (plansza1[iks1][igrek1] == -1)
	{
		plansza1[iks1][igrek1] = 5;
		cout << " PUDLO " << endl;
	}
	if (plansza1[iks1][igrek1] == 1)
	{
		plansza1[iks1][igrek1] = 6;
		cout << " TWOJ TRAFIONY I ZATOPIONY " << endl;
		licznik_1++;
	}
	if (plansza1[iks1][igrek1] == 2)
	{
		plansza1[iks1][igrek1] = 7;
		cout << " TWOJ TRAFIONY " << endl;
		zatapianie(plansza1, 2, 7, licznik_1);
	}
	if (plansza1[iks1][igrek1] == 3)
	{
		plansza1[iks1][igrek1] = 8;
		cout << " TWOJ TRAFIONY " << endl;
		zatapianie(plansza1, 3, 8, licznik_1);
	}
	if (plansza1[iks1][igrek1] == 4)
	{
		plansza1[iks1][igrek1] = 9;
		cout << "TWOJ TRAFIONY " << endl;
		zatapianie(plansza1, 4, 9, licznik_1);
	}
}

void refresh1(int plansza[10][10])
{
	char litera1 = 65;
	for (int i = 0; i < 10; i++)
	{
		cout.width(2);
		cout << " " << litera1;
		litera1++;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.width(1);
		cout << i;
		for (int j = 0; j < 10; j++)
		{

			if (plansza1[i][j] == 0)

				cout << " . ";
			if (plansza1[i][j] == -1)

				cout << " . ";
			if (plansza1[i][j] == 1)

				cout << " # ";
			if (plansza1[i][j] == 2)

				cout << " # ";
			if (plansza1[i][j] == 3)

				cout << " # ";
			if (plansza1[i][j] == 4)

				cout << " # ";
			if (plansza1[i][j] == 5)

				cout << " X ";
			if (plansza1[i][j] == 6 || plansza1[i][j] == 7 || plansza1[i][j] == 8 || plansza1[i][j] == 9)

				cout << " Y ";

		}
		cout << endl;
	}
}

void refresh2(int plansza[10][10])
{
	char litera1 = 65;
	for (int i = 0; i < 10; i++)
	{
		cout.width(2);
		cout << " " << litera1;
		litera1++;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.width(1);
		cout << i;
		for (int j = 0; j < 10; j++)
		{

			if (plansza2[i][j] == 0)

				cout << " . ";
			if (plansza2[i][j] == -1)

				cout << " . ";
			if (plansza2[i][j] == 1)

				cout << " . ";
			if (plansza2[i][j] == 2)

				cout << " . ";
			if (plansza2[i][j] == 3)

				cout << " . ";
			if (plansza2[i][j] == 4)

				cout << " . ";
			if (plansza2[i][j] == 5)

				cout << " X ";
			if (plansza2[i][j] == 6 || plansza2[i][j] == 7 || plansza2[i][j] == 8 || plansza2[i][j] == 9)

				cout << " Y ";

		}
		cout << endl;
	}
}

void zatapianie(int plansza[10][10], int masztowiec, int numer, int& licznik)
{
	int licznik1 = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (plansza[i][j] == numer)
			{
				licznik1++;
			}
		}

	}
	if (licznik1 % masztowiec == 0)
	{
		cout << " I ZATOPIONY" << endl;
		licznik++;
	}

}

void wynik(int plansza[10][10], int plansza2[10][10])
{
	int licznik = 0;
	int licznik2 = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (plansza[i][j] == 6 || plansza[i][j] == 7 || plansza[i][j] == 8 || plansza[i][j] == 9)
			{
				licznik++;
			}
			if (plansza2[i][j] == 6 || plansza2[i][j] == 7 || plansza2[i][j] == 8 || plansza2[i][j] == 9)
			{
				licznik2++;
			}
		}

	}
	if (licznik < licznik2)
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;
	}
	if (licznik == licznik2)
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;

	}
	else
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;

	}
}

void wynik2(int plansza[10][10], int plansza2[10][10])
{
	int licznik = 0;
	int licznik2 = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (plansza[i][j] == 6 || plansza[i][j] == 7 || plansza[i][j] == 8 || plansza[i][j] == 9)
			{
				licznik++;
			}
			if (plansza2[i][j] == 6 || plansza2[i][j] == 7 || plansza2[i][j] == 8 || plansza2[i][j] == 9)
			{
				licznik2++;
			}
		}

	}
	if (licznik < licznik2)
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;
		cout << "WYGRALES" << endl;
	}
	if (licznik == licznik2)
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;
		cout << "REMIS " << endl;
	}
	else
	{
		cout << "TWOJ WYNIK: " << licznik2 << " " << "WYNIK PRZECIWNIKA: " << licznik << endl;
		cout << "PRZEGRALES" << endl;
	}
}

void status(int licznik1, int licznik2)
{
	cout << "Twoje zbite statki: " << licznik1 << endl;
	cout << "Zbite statki wroga: " << licznik2 << endl;
}
