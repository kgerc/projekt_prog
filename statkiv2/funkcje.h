#pragma once
void ustawstatki(int plansza[10][10], int rm);
void wyswietlstatki(int plansza[10][10]);
void wyswietlstatkiwroga(int plansza[10][10]);
void twojstrzal(int plansza[10][10], int iks, int igrek);
void strzalwroga(int plansza[10][10], int iks1, int igrek1);
void refresh1(int plansza[10][10]);
void refresh2(int plansza[10][10]);
void zatapianie(int plansza[10][10], int masztowiec, int numer, int&);
void wynik(int plansza[10][10], int plansza2[10][10]);
void wynik2(int plansza[10][10], int plansza2[10][10]);
void status(int licznik1, int licznik2);

extern int plansza1[10][10];
extern int plansza2[10][10];
extern int licznik_1;
extern int licznik_2;