#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 20

typedef struct dane
{
  char imie[SIZE];
  char nazwisko[SIZE];
  int rok;
}dane;

typedef struct lista
{
  dane osoba;
  struct lista * next;
}lista;

void dodajpoczatek (lista **);
void dodajsrodek (lista**, lista **);
void dodajkoniec (lista *);
void usunpoczatek (lista **);
void usunsrodek (lista **, lista **);
void usunkoniec (lista **);
void wypisz (lista *);
void wyszukajrok (lista *);
void wyszukajnazwisko (lista *);
void usuncalosc (lista **);
lista * wyszukaj (lista * head);
