#include <iostream>
#include <random>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include "funkcje.h"
using namespace std;

int main()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN|FOREGROUND_RED);

	ustawstatki(plansza1,4);
	for (int l = 0; l < 2; l++)
	{
		ustawstatki(plansza1,3);
	}
	for (int p = 0; p < 3; p++)
	{
		ustawstatki(plansza1,2);
	}
	for (int q = 0; q < 4; q++)
	{
		ustawstatki(plansza1,1);
	}

	wyswietlstatki(plansza1);
	cout << "______________________________" << endl;

	ustawstatki(plansza2,4);
	for (int l = 0; l < 2; l++)
	{
		ustawstatki(plansza2,3);
	}
	for (int p = 0; p < 3; p++)
	{
		ustawstatki(plansza2,2);
	}
	for (int q = 0; q < 4; q++)
	{
		ustawstatki(plansza2,1);
	}
	cout <<  endl;
	
	wyswietlstatkiwroga(plansza2);
	cout << endl;
	
	for (;;)
	{
		char igrek_1;
		int igrek{};
		int iks;
		int iks1;
		int igrek1;
		random_device device;
		mt19937 generator(device());
		uniform_int_distribution<int> losowa1(0, 9);
		int wybor, z;
		cout << "By zaatakowac przeciwnika kliknij 1:"  << endl;
		cout << "By sprawdzic wynik kliknij 2:" << endl;
		cout << "By zakonczyc gre kliknij 3:" << endl;
		while (!(cin >> z))
		{
	
			cin.clear();
			cin.ignore(1000,'\n'); 
			cout << "Blad" << endl;
			Sleep(1000);
			system("cls");
			refresh1(plansza1);
			cout << "______________________________" << endl << endl;
			refresh2(plansza2);
			cout << "By zaatakowac przeciwnika kliknij 1:" << endl;
			cout << "By sprawdzic wynik kliknij 2:" << endl;
			cout << "By zakonczyc gre kliknij 3:" << endl;
		}
		if (z == 1 || z == 2 || z == 3)
		{
			{
				switch (z)
				{
				case 1:

					cout << "Podaj wspolrzedna iksowa:";
					while (!(cin >> iks))
					{

						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Blad" << endl;
						Sleep(1000);
						system("cls");
						refresh1(plansza1);
						cout << "______________________________" << endl << endl;
						refresh2(plansza2);
						cout << "Podaj wspolrzedna iksowa:";
					}
					if (iks == 0 || iks == 1 || iks == 2 || iks == 3 || iks == 4 || iks == 5 || iks == 6 || iks == 7 || iks == 8 || iks == 9)
					{
						cout << "Podaj wspolrzedna igrekowa:";
						cin >> igrek_1;
						if (igrek_1 == 'A')
						{
							igrek = 0;
						}
							
							else if (igrek_1 == 'B')
							{
								igrek = 1;
							}
							else if (igrek_1 == 'C')
							{
								igrek = 2;
							}
							else if (igrek_1 == 'D')
							{
								igrek = 3;
							}
							else if (igrek_1 == 'E')
							{
								igrek = 4;
							}
							else if (igrek_1 == 'F')
							{
								igrek = 5;
							}
							else if (igrek_1 == 'G')
							{
								igrek = 6;
							}
							else if (igrek_1 == 'H')
							{
								igrek = 7;
							}
							else if (igrek_1 == 'I')
							{
								igrek = 8;
							}
							else if (igrek_1 == 'J')
							{
								igrek = 9;
							}
							else
							{
							cout << "Blad" << endl;
							Sleep(1000);
							system("cls");
							refresh1(plansza1);
							cout << "______________________________" << endl << endl;
							refresh2(plansza2);
							break;
							}	
						

						twojstrzal(plansza2, iks, igrek);

						cout << "Komputer atakuje..." << endl;
						iks1 = losowa1(generator);
						igrek1 = losowa1(generator);

						strzalwroga(plansza1, iks1, igrek1);
						
						if (licznik_1 == 10)
						{
							cout << "PRZEGRALES" << endl;
							exit(0);
						}
						if (licznik_2 == 10)
						{
							cout << "WYGRALES" << endl;
							exit(0);
						}

						cout << "Czy chcesz kontynuowac?" << " TAK(wcisnij 1) NIE(wcisnij 2)" << endl;
						while (!(cin >> wybor))
						{

							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Blad" << endl;
							Sleep(1000);
							system("cls");
							refresh1(plansza1);
							cout << "______________________________" << endl << endl;
							refresh2(plansza2);
							cout << "Czy chcesz kontynuowac?" << " TAK(wcisnij 1) NIE(wcisnij 2)" << endl;
						}
						if (wybor == 1)
						{
							system("cls");
							refresh1(plansza1);
							cout << "______________________________" << endl << endl;
							refresh2(plansza2);
							break;
						}
						else if (wybor == 2)
						{
							wynik(plansza1, plansza2);
							exit(0);
						}
						else
						{
							cout << "Blad" << endl;
							Sleep(1000);
							system("cls");
							refresh1(plansza1);
							cout << "______________________________" << endl << endl;
							refresh2(plansza2);
						}
						
                        break;
						
					}
					else
					{
						cout << "Blad" << endl;
						Sleep(1000);
						system("cls");
						refresh1(plansza1);
						cout << "______________________________" << endl << endl;
						refresh2(plansza2);
						break;
					}
						
					
					
				case 2:
					system("cls");
					status(licznik_1, licznik_2);
					wynik(plansza1, plansza2);
					cout << "Czy chcesz kontynuowac?" << " TAK(wcisnij 1) NIE(wcisnij 2)" << endl;
					while (!(cin >> wybor))
					{

						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Blad" << endl;
						Sleep(1000);
						system("cls");
						cout << "Czy chcesz kontynuowac?" << " TAK(wcisnij 1) NIE(wcisnij 2)" << endl;
					}
					if (wybor == 1)
					{
						system("cls");
						refresh1(plansza1);
						cout << "______________________________" << endl << endl;
						refresh2(plansza2);
						break;
					}
					else if (wybor == 2)
					{
						system("cls");
						wynik(plansza1, plansza2);
						cout << "Dzieki za wyprobowanie gierki much apreesh :>" << endl;
						exit(0);
					}
					else
					{
						cout << "Blad" << endl;
						Sleep(1000);
						system("cls");
						refresh1(plansza1);
						cout << "______________________________" << endl << endl;
						refresh2(plansza2);
					}
					break;

				case 3:
					system("cls");
					wynik2(plansza1, plansza2);
					cout << "Dzieki za wyprobowanie gierki much apreesh :>" << endl;
					exit(0);
					break;
				}
			}
		}
		else
		{
		cout << "Blad" << endl;
		Sleep(1000);
		system("cls");
		refresh1(plansza1);
		cout << "______________________________" << endl << endl;
		refresh2(plansza2);

		}
	}
	
	return 0;
}

 