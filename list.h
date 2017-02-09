#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 20

typedef struct data
{
  char firstName[SIZE];
  char lastName[SIZE];
  int yearofBirth;
}data;

typedef struct node
{
  data person;
  struct node * next;
}node;

void addBeginning (node **);
void addMiddle (node**, node **);
void addEnd (node *);
void deleteBeginning (node **);
void deleteMiddle (node **, node **);
void deleteEnd (node **);
void show (node *);
void searchYear (node *);
void searchName (node *);
void clear (node **);
node * search (node * head);
