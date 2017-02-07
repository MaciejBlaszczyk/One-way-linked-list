#include"list.h"

void dodajpoczatek (lista ** head)
{

  	lista * tmp;
  	tmp = malloc(sizeof(lista));
  	if(tmp == NULL)
  	{
	  	usuncalosc(head);
	  	printf("Blad pamieci");
  	}
  	tmp->next = * head;
  	* head = tmp;
  	printf("Podaj imie: ");
  	scanf("%s", tmp->osoba.imie);
  	printf("Podaj nazwisko: ");
  	scanf("%s", tmp->osoba.nazwisko);
  	printf("Podaj rok urodzenia: ");
  	scanf("%d", &tmp->osoba.rok);
  	printf("Wezel zostal dodany\n");
  	printf("Wcisnij dowolny klawisz aby kontynuowac");
  	getch();
}

void dodajsrodek (lista ** head, lista ** adres)
{
	lista * tmp;
    tmp = malloc(sizeof(lista));
    if(tmp == NULL)
    {
    	usuncalosc(head);
        printf("Blad pamieci\n");
        return;
    }
    printf("\nPodaj imie: ");
  	scanf("%s", tmp->osoba.imie);
  	printf("Podaj nazwisko: ");
  	scanf("%s", tmp->osoba.nazwisko);
  	printf("Podaj rok urodzenia: ");
  	scanf("%d", &tmp->osoba.rok);
	tmp->next = (* adres)->next;
	(* adres)->next = tmp;
	printf("Wezel zostal dodany\n");
  	printf("Wcisnij dowolny klawisz aby kontynuowac");
  	getch();
}

void dodajkoniec(lista * head)
{
  	lista * tmp;
  	lista * tmp2;
  	tmp2 = malloc(sizeof(lista));
  	if(tmp2 == NULL)
  	{
  		usuncalosc(&head);
	  	printf("Blad pamieci");
	}
	printf("Podaj imie: ");
  	scanf("%s", tmp2->osoba.imie);
  	printf("Podaj nazwisko: ");
  	scanf("%s", tmp2->osoba.nazwisko);
  	printf("Podaj rok urodzenia: ");
  	scanf("%d", &tmp2->osoba.rok);
  	for(tmp = head; (tmp->next) != NULL; tmp = tmp->next);
  	tmp->next = tmp2;
  	tmp2->next = NULL;
  	printf("Wezel zostal dodany\n");
  	printf("Wcisnij dowolny klawisz aby kontynuowac");
  	getch();
}

void usunpoczatek (lista ** head)
{
	if(*head==NULL)
	{
		printf("Nic nie ma na liscie,nie mozna nic usunac");
		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
	}
	else
	{
		lista * tmp = (* head)->next;
		free (* head);
		* head = NULL;
		* head = tmp;
		printf("Wezel zostal usuniety\n");
  		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
  	}
}

void usunsrodek (lista ** head, lista ** adres)
{
	lista * tmp, * przed;
	if((*head)->next == NULL)
	{
		free(* head);
		* head = NULL;
		printf("Wezel zostal usuniety\n");
  		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
	}
	else
	{
		for(tmp = * head; tmp != * adres; tmp = tmp->next)
			przed=tmp;
		przed->next = (*adres)->next;
		free(* adres);
		* adres = NULL;
		printf("Wezel zostal usuniety\n");
  		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
  	}
}

void usunkoniec (lista ** head)
{
	lista * przedostatni, * ostatni, * tmp = * head;

	if(*head==NULL)
	{
		printf("Nic nie ma na liscie,nie mozna nic usunac\n");
		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
	}
	else if(tmp->next == NULL)
	{
		* head = NULL;
		printf("Wezel zostal usuniety\n");
  		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
		return;
	}
	else
	{
		for(tmp = * head; tmp->next != NULL; tmp = tmp->next)
			przedostatni = tmp;
		for(tmp = * head; tmp != NULL; tmp = tmp->next)
			ostatni = tmp;
		przedostatni->next = ostatni->next;
		printf("Wezel zostal usuniety\n");
  		printf("Wcisnij dowolny klawisz aby kontynuowac");
  		getch();
	}
}

void wypisz (lista * head)
{
	if(head == NULL)
		printf("Lista jest pusta\n");
  	int i = 1;
  	for(head = head; head != NULL; head = head->next)
  	{
    	printf("%d WEZEL:\nimie: %s\nNazwisko: %s\nRok Urodzenia: %d\n",
				i,head->osoba.imie,head->osoba.nazwisko,head->osoba.rok);
		i++;
  	}
  	printf("Wcisnij dowolny klawisz aby kontynuowac");
  	getch();
}

void wyszukajrok (lista * head)
{
	int rok, x = 0;
	printf("Podaj rok urodzenia szukanej osoby: ");
	scanf("%d", &rok);
	for(head = head; head != NULL; head = head->next)
	{
		if((head->osoba.rok) == rok)
		{
			printf("Szukana osoba jest na liscie!\nOto jej dane:\nImie: %s\nNazwisko: %s\nRok Urodzenia: %d\n",
					head->osoba.imie,head->osoba.nazwisko,head->osoba.rok);
			printf("Wcisnij dowolny klawisz aby kontynuowac");
			x++;
			getch();
		}
	}
	if(x == 0)
	{
		printf("Niestety szukanej osoby nie ma na liscie\n");
		printf("Wcisnij dowolny klawisz aby kontynuowac");
		getch();
	}
}

void wyszukajnazwisko (lista * head)
{
	int i, x, y = 0;
	char nazwisko[SIZE];
	printf("Podaj nazwisko szukanej osoby: ");
	scanf("%s", nazwisko);
	for(head = head; head != NULL; head = head->next)
	{
		x = 0;
		for(i = 0; nazwisko[i] != '\0'; i++)
		{
			if((head->osoba.nazwisko[i]) != nazwisko[i])
			{
				x++;
			}
		}
		if(x == 0)
		{
			printf("Szukana osoba jest w liscie!\nOto jej dane:\nImie: %s\nNazwisko: %s\nRok Urodzenia: %d\n",
					head->osoba.imie,head->osoba.nazwisko,head->osoba.rok);
			printf("Wcisnij dowolny klawisz aby kontynuowac");
			getch();
			y++;
		}
	}
	if(y == 0)
	{
		printf("Szukanej osoby nie ma na liscie\n");
		printf("Wcisnij dowolny klawisz aby kontynuowac");
		getch();
	}
}

void usuncalosc (lista ** head)
{
	lista * tmp;
	for(tmp = * head; * head != NULL; * head = tmp->next)
	{
		tmp = * head;
		free(tmp);

	}
	printf("Lista zostala wyczyszczona");
	printf("Wcisnij dowolny klawisz aby kontynuowac");
	getch();
}

lista * wyszukaj (lista * head)
{
	int rok, x = 0;
	printf("Podaj rok urodzenia szukanej osoby: ");
	scanf("%d", &rok);
	for(head = head; head != NULL; head = head->next)
	{
		if((head->osoba.rok) == rok)
		{
			x++;
			return head;
		}
	}
	if(x == 0)
	{
		head=NULL;
		return head;
	}
}

