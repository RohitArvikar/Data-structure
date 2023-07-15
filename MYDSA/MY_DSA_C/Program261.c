
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;

};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


void InsertLast(PPNODE Head, int No)
{
   PNODE newn = NULL;

   //Allocate memory for node
   newn = (PNODE)malloc(sizeof(NODE));    // (struct Node*)malloc(sizeof(struct Node));

   //Initialise the node
   newn->data = No;
   newn->next = NULL;


   if(*Head == NULL ) // LL is Empty
   {
      *Head = newn;
   }
   else           // LL contains Atleast one node
   {
       PNODE temp = *Head;

       while(temp -> next != NULL)
       {
         temp = temp -> next;
       }

       temp -> next = newn;
   }
}



int main()
{
   PNODE First = NULL;

   InsertLast(&First,51);        //InsertFirst(60,51)
   InsertLast(&First,21);        //InsertFirst(60,21)
   InsertLast(&First,11);        //InsertFirst(60,11)
   
    return 0;
}