/////////////////////////////////////////////////////////////
// for DeleteAtPosition
//////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;


void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;

   // Allocate Memory

   newn = (PNODE)malloc(sizeof(NODE));

   //Intialise the node

   newn->data = No;
   newn->next = NULL;

// Check whetehr LL is empty or not


   if(*Head == NULL)
   {
      *Head = newn;
   }
   else
   {
       newn->next= *Head;
       *Head = newn;
   }
}


void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;

   // Allocate Memory

   newn = (PNODE)malloc(sizeof(NODE));

   //Intialise the node

   newn->data = No;
   newn->next = NULL;

// Check whetehr LL is empty or not


   if(*Head == NULL)
   {
      *Head = newn;
   }
   else
   {
     PNODE temp = *Head;

     while(temp -> next != NULL)
     {
        temp = temp->next;
     }

     temp->next= newn;
   }
}


void Display(PNODE Head)
 {
    printf("Elements of LinkedList are: \n");
      while(Head != NULL)
      {
         printf("| %d | ->",Head->data);
         Head = Head->next;
      }

      printf("NULL\n");
 }


int Count(PNODE Head)
{
      int iCount = 0;

       while(Head != NULL)
       {
          iCount++;
          Head = Head -> next;
       }

       return iCount;

}






void DeleteFirst(PPNODE Head)
{
   PNODE temp = *Head;

   if(*Head == NULL)                  //LL is empty
   {
      return;
   }
   else if((*Head) ->next == NULL)     //LL contains 1 Node//    //(*Head) imp 13-6-23 // t- 19.42pm
   {
      free(*Head);
      *Head = NULL;
   }
   else                                //LL contains more than one node
   {
     *Head = (*Head) -> next;
     free(temp);
      
   }
}


void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

   if(*Head == NULL)                  //LL is empty
   {
      return;
   }
   else if((*Head) ->next == NULL)     //LL contains 1 Node//    //(*Head) imp 13-6-23 // t- 19.42pm
   {
      free(*Head);
      *Head = NULL;
   }
   else                                //LL contains more than one node
   {
      
      while(temp->next->next != NULL)     //type 3 while loop
      {
         temp = temp -> next;
      }

      free(temp->next);
      temp->next = NULL;
   }
}


 void DeleteAtPos(PPNODE Head, int iPos)    
 {
    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iLength = 0;
    iLength = Count(*Head);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position");
        return;
    } 

    if(iPos == 1)
    {
        DeleteFirst(Head,No);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head,No);
    }
    else
    {
    for(icnt = 1; icnt<iPos - 1; icnt++)
     {
        temp = temp -> next;
     }

     tempX = temp->next;

     temp->next = temp->next->next;
     free(tempX);
        
    }
 } 




int main()
{
   PNODE First = NULL;

   InsertLast(&First,11);
   InsertLast(&First,21);
   InsertLast(&First,51);
   InsertLast(&First,101);

   Display(First);

   int iRet = Count(First);
   printf("Number of nodes are: %d\n",iRet);

   InsertFirst(&First,10);
   InsertFirst(&First,20);

   Display(First);

   iRet = Count(First);
   printf("Number of nodes are: %d\n",iRet);

   /* ------- */
   InsertAtPos(&First,25,5);
   
   Display(First);

   DeleteAtPos(&first , 5);

   Display(First);

   DeleteFirst(&First);
   DeleteFirst(&First);

   Display(First);

   iRet = Count(First);
   printf("Number of nodes are: %d\n",iRet);

   
   DeleteLast(&First);

   Display(First);

   iRet = Count(First);
   printf("Number of nodes are: %d\n",iRet);

    return 0;
}