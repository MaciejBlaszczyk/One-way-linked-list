#include "list.h"

int main()
{
  	lista * head = NULL;
	lista * adres = NULL;
  	int numb;
  	for(;;system("cls"))
  	{
  		printf("Witaj w liscie jednokierunkowej!\nMozesz gromadzic tutaj dane osobowe!\n\n"
  			   "Jesli chcesz dodac na poczatek listy nowy wezel wcisnij \"1\"\n"
  			   "Jesli chcesz dodac w srodku listy nowy wezel wcisnij \"2\"\n"
  			   "Jesli chcesz dodac na koncu listy nowy wezel wcisnij \"3\"\n"
  			   "Jesli chcesz usunac wezel z poczatku listy wcisnij \"4\"\n"
  			   "Jesli chcesz usunac wezel ze srodka listy wcisnij \"5\"\n"
  			   "Jesli chcesz usunac wezel z konca listy wcisnij \"6\"\n"
			   "Jesli chcesz wypisac cala liste wcisnij \"7\"\n"
			   "Jesli chcesz wyszukac kogos po roku urodzenia wcisnij \"8\"\n"
			   "Jesli chcesz wyszukac kogos po nazwisku wcisnij \"9\"\n"
			   "Jesli chcesz usunac cala liste wcisnij \"10\"\n"
			   "Jesli chcesz wyjsc wcisnij \"11\"\n");
  		if(scanf("%d", &numb) == 0)
  		{
  			free(head);
  			head=NULL;
  			return -1;
		}
		switch(numb)
		{
			case 1 : dodajpoczatek(&head); break;
			case 2 : adres=wyszukaj(head);
					 if(adres==NULL)
					 {
					 	printf("Niestety szukanej osoby nie ma na liscie\n");
					 	printf("Wcisnij dowolny klawisz aby kontynuowac");
					 	getch();
					 	break;
					 }
					 else
					 {
					 	printf("Szukana osoba jest na liscie! \nMozesz dodac po niej nowy wezel\n");
					 	dodajsrodek(&head, &adres); break;
					 }
					 adres=NULL;
			case 3 : dodajkoniec(head); break;
			case 4 : usunpoczatek(&head); break;
			case 5 : adres=wyszukaj(head);
					 if(adres==NULL)
					 {
					 	printf("Niestety szukanej osoby nie ma na liscie\n");
					 	printf("Wcisnij dowolny klawisz aby kontynuowac");
					 	getch();
					 	break;
					 }
					 else
					 {
					 	printf("Szukana osoba jest na liscie! \nMozesz usunac ten wezel\n");
					 	usunsrodek(&head, &adres); break;
					 }
					 adres=NULL;
			case 6 : usunkoniec(&head); break;
			case 7 : wypisz(head); break;
			case 8 : wyszukajrok(head); break;
			case 9 : wyszukajnazwisko(head); break;
			case 10 : usuncalosc(&head); break;
			case 11 : free(head);
  					  head=NULL;
  					  return -1;
			default : printf("Podaj inny numer\n");
					  printf("Wcisnij dowolny klawisz aby kontynuowac\n");
					  getch();
		}
  	}
  	return 0;
}
