#include"list.h"

void addBeginning(node **head)
{
  	node * tmp;
  	tmp = malloc(sizeof(node));
  	if(tmp == NULL)
  	{
	  	clear(head);
	  	printf("Memory error");
  	}
  	tmp->next = *head;
  	*head = tmp;
  	printf("Enter first name: ");
  	scanf("%s", tmp->person.firstName);
  	printf("Enter last name: ");
  	scanf("%s", tmp->person.lastName);
  	printf("Enter year of birth: ");
  	scanf("%d", &tmp->person.yearofBirth);
  	printf("Node has been added\n");
  	printf("Press any key to continue");
  	getch();
}

void addMiddle(node **head, node **adres)
{
	node *tmp;
    tmp = malloc(sizeof(node));
    if(tmp == NULL)
    {
    	clear(head);
        printf("Memory error\n");
        return;
    }
    printf("\nEnter first name: ");
  	scanf("%s", tmp->person.firstName);
  	printf("Enter last name: ");
  	scanf("%s", tmp->person.lastName);
  	printf("Enter year of birth: ");
  	scanf("%d", &tmp->person.yearofBirth);
	tmp->next = (*adres)->next;
	(*adres)->next = tmp;
	printf("Node has been added\n");
  	printf("Press any key to continue");
  	getch();
}

void addEnd(node *head)
{
  	node *tmp;
  	node *tmp2;
  	tmp2 = malloc(sizeof(node));
  	if(tmp2 == NULL)
  	{
  		clear(&head);
	  	printf("Memory error");
	}
	printf("Enter first name: ");
  	scanf("%s", tmp2->person.firstName);
  	printf("Enter last name: ");
  	scanf("%s", tmp2->person.lastName);
  	printf("Enter year of birth: ");
  	scanf("%d", &tmp2->person.yearofBirth);
  	for(tmp = head; (tmp->next) != NULL; tmp = tmp->next);
  	tmp->next = tmp2;
  	tmp2->next = NULL;
  	printf("Wezel zostal dodany\n");
  	printf("Press any key to continue");
  	getch();
}

void deleteBeginning(node **head)
{
	if(*head == NULL)
	{
		printf("There is nothing to delete");
		printf("Press any key to continue");
  		getch();
	}
	else
	{
		node *tmp = (*head)->next;
		free (*head);
		*head = NULL;
		*head = tmp;
		printf("Node has been deleted\n");
  		printf("Press any key to continue");
  		getch();
  	}
}

void deleteMiddle(node **head, node **adres)
{
	node *tmp, *before;
	if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		printf("Node has been deleted\n");
  		printf("Press any key to continue");
  		getch();
	}
	else
	{
		for(tmp = *head; tmp != *adres; tmp = tmp->next)
			before = tmp;
		before->next = (*adres)->next;
		free(*adres);
		*adres = NULL;
		printf("Node has been deleted\n");
  		printf("Press any key to continue");
  		getch();
  	}
}

void deleteEnd(node **head)
{
	node *beforeLast, *last, *tmp = *head;

	if(*head == NULL)
	{
		printf("There is nothing to delete\n");
		printf("Press any key to continue");
  		getch();
	}
	else if(tmp->next == NULL)
	{
		*head = NULL;
		printf("Node has been deleted\n");
  		printf("Press any key to continue");
  		getch();
		return;
	}
	else
	{
		for(tmp = *head; tmp->next != NULL; tmp = tmp->next)
			beforeLast = tmp;
		for(tmp = *head; tmp != NULL; tmp = tmp->next)
			last = tmp;
		beforeLast->next = last->next;
		printf("Node has been deleted\n");
  		printf("Press any key to continue");
  		getch();
	}
}

void show(node *head)
{
	if(head == NULL)
		printf("List is empty\n");
  	int i = 1;
  	for(head = head; head != NULL; head = head->next)
  	{
    	printf("%d Node:\nFirst Name: %s\nLast Name: %s\nYear of Birth: %d\n",
				i,head->person.firstName,head->person.lastName,head->person.yearofBirth);
		i++;
  	}
  	printf("Press any key to continue");
  	getch();
}

void searchYear(node *head)
{
	int yearofBirth, x = 0;
	printf("Enter year of birth searched person: ");
	scanf("%d", &yearofBirth);
	for(head = head; head != NULL; head = head->next)
	{
		if((head->person.yearofBirth) == yearofBirth)
		{
			printf("Person found!\nFirst Name: %s\nLast Name: %s\n Year of Birth: %d\n",
					head->person.firstName, head->person.lastName, head->person.yearofBirth);
			printf("Press any key to continue");
			x++;
			getch();
		}
	}
	if(x == 0)
	{
		printf("There is no such a person in storage\n");
		printf("Press any key to continue");
		getch();
	}
}

void searchName(node *head)
{
	int i, x, y = 0;
	char lastName[SIZE];
	printf("Enter last name searched person: ");
	scanf("%s", lastName);
	for(head = head; head != NULL; head = head->next)
	{
		x = 0;
		for(i = 0; lastName[i] != '\0'; i++)
		{
			if((head->person.lastName[i]) != lastName[i])
			{
				x++;
			}
		}
		if(x == 0)
		{
			printf("Person found!\nPersonal data:\nFirst Name: %s\nLast Name: %s\nYear of Birth: %d\n",
					head->person.firstName, head->person.lastName, head->person.yearofBirth);
			printf("Press any key to continue");
			getch();
			y++;
		}
	}
	if(y == 0)
	{
		printf("There is no such a person in storage\n");
		printf("Press any key to continue");
		getch();
	}
}

void clear(node **head)
{
	node *tmp;
	for(tmp = *head; *head != NULL; *head = tmp->next)
	{
		tmp = *head;
		free(tmp);

	}
	printf("Storage has been cleared\n");
	printf("Press any key to continue");
	getch();
}

node *search(node *head)
{
	int yearofBirth;
	printf("Enter year of birth searched person: ");
	scanf("%d", &yearofBirth);

	for(head = head; head != NULL; head = head->next)
		if((head->person.yearofBirth) == yearofBirth)
			return head;

	head = NULL;
	return head;
}

