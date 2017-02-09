#include "list.h"

int main()
{
  	node *head = NULL;
	node *adres = NULL;
  	int numb;
  	for( ;  ; system("cls"))
  	{
  		printf("Welcome in personal data storage powered by one way linked list!\n"
  			   "If you want to add data in the beginning of the list, press 1\n"
  			   "If you want to add data in the middle of the list, press 2\n"
  			   "If you want to add data in the end of the list, press 3\n"
  			   "If you want to delete data from the beginning of the list, press 4\n"
  			   "If you want to delete data from the middle of the list, press 5\n"
  			   "If you want to delete data from the end of the list, press 6\n"
			   "If you want to show whole list, press 7\n"
			   "If you want to search someone by year of birth, press 8\n"
			   "If you want to search someone by last name, press 9\n"
			   "If you want to delete whole list, press 10\n"
			   "If you want to exit, press 11\n");
  		if(scanf("%d", &numb) == 0)
  		{
  			free(head);
  			head = NULL;
  			return -1;
		}
		switch(numb)
		{
			case 1 : addBeginning(&head);
			break;
			case 2 : adres = search(head);
					 if(adres==NULL)
					 {
					 	printf("There is no such a person in storage\n");
					 	printf("Press any key to continue");
					 	getch();
					 	break;
					 }
					 else
					 {
					 	printf("Person found! \nYou can add new data\n");
					 	addMiddle(&head, &adres); break;
					 }
					 adres=NULL;
			case 3 : addEnd(head);
			break;
			case 4 : deleteBeginning(&head);
			break;
			case 5 : adres = search(head);
					 if(adres == NULL)
					 {
					 	printf("There is no such a person in storage\n");
					 	printf("Press any key to continue");
					 	getch();
					 }
					 else
					 {
					 	printf("Person found! \nYou can delete data\n");
					 	deleteMiddle(&head, &adres);
					 }
					 adres=NULL;
					 break;
			case 6 : deleteEnd(&head);
			break;
			case 7 : show(head);
			break;
			case 8 : searchYear(head);
			break;
			case 9 : searchName(head);
			break;
			case 10 : clear(&head);
			break;
			case 11 : free(head);
  					  head = NULL;
  					  return 1;
			default : printf("Enter other number\n");
					  printf("Press any key to continue\n");
					  getch();
		}
  	}
  	return 0;
}
