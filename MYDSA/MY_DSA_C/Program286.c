/////////////////////////////////////////////////////////////
// Singly Circular LL
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

}NODE,*PNODE,**PPNODE;

//////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn =(PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))         //LL is empty
    {
        *Head = newn;
        *Tail = newn;
                       
    }
    else                                          //LL contains atleast one node
    {
        newn->next = *Head;
        *Head = newn;
        
    }

    (*Tail)->next = *Head;
}

////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;
    newn =(PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))         //LL is empty
    {
        *Head = newn;
        *Tail = newn;

        (*Tail)->next = *Head;                    
    }
    else                                          //LL contains atleast one node
    {
        (*Tail)->next = newn;
        *Tail = (*Tail)->next;               //(*Tail = newn)  as pan lihu shkto
    }

    (*Tail)->next = *Head;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head, PNODE Tail)
{
    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            printf("| %d | -> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);

        printf("\n");
    }
    else
    {
        printf("Linked List is Empty\n");
    }
}

///////////////////////////////////////////////////////////////////////////

int Count(PNODE Head, PNODE Tail)
{
    int iCount = 0;

    if((Head != NULL) && (Tail != NULL))
    {
        do
        {
            iCount++;
            Head = Head->next;
        }while(Head != Tail->next);
        return iCount;
    }
    else
    {
       return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    

    if((*Head == NULL) && (*Tail == NULL))
    {
       return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        free(*Tail);
        *Tail = NULL;
    }
    else
    {
       *Head = (*Head) ->next;
       free((*Tail)->next);
       (*Tail)->next = *Head;
    }
}
/////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
       return;
    }
    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        free(*Tail);
        *Tail = NULL;
    }
    else
    {
       while(temp->next != *Tail)
       {
           temp = temp->next;
       }

       free(*Tail);
       *Tail = temp;

       (*Tail)->next = *Head;

    } 
}

/////////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE Head, PPNODE Tail,int iNo, int iPos)
{
   int iLength = 0;
   PNODE newn = NULL;
   int icnt = 0;
   PNODE temp = *Head;

   iLength = Count(*Head,*Tail);

   if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position");
        return;
    }

   if(iPos == 1)
   {
     InsertFirst(Head,Tail,iNo);
   }
   else if(iPos == iLength+1)
   {
      InsertLast(Head,Tail,iNo);
   }
   else
   {
      newn = (PNODE)malloc(sizeof(NODE));
      newn->data = iNo;
      newn->next = NULL;

      for(icnt = 1; icnt < iPos-1; icnt++)
      {
         temp = temp->next;
      }

      newn->next = temp->next;
      temp->next = newn;

    

   }
}

/////////////////////////////////////////////////////////////////////////////
void DeleteAtPosition(PPNODE Head, PPNODE Tail, int iPos)
{
   int iLength = 0;
   PNODE temp = *Head;
   PNODE tempX = NULL;
   int icnt = 0;


   iLength = Count(*Head,*Tail);

   if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position");
        return;
    }

   if(iPos == 1)
   {
     DeleteFirst(Head,Tail);
   }
   else if(iPos == iLength+1)
   {
      DeleteLast(Head,Tail);
   }
   else
   {
      for(icnt =1; icnt < iPos-1; icnt++)
      {
        temp = temp->next;
      }

      tempX = temp->next;                    //2 temp pointer
      temp->next = temp->next->next;
      free(tempX);
   }
}

//////////////////////////////////////////////////////////////////////////////////
int main()
{
      PNODE First = NULL;
      PNODE Last = NULL;             //#
      int iRet = 0;

      InsertFirst(&First,&Last,51);
      InsertFirst(&First,&Last,21);
      InsertFirst(&First,&Last,11);

      InsertLast(&First,&Last,101);
      InsertLast(&First,&Last,111);
      InsertLast(&First,&Last,121);

      Display(First,Last);

      iRet = Count(First,Last);
      printf("Number of nodes are: %d\n",iRet);

      DeleteFirst(&First,&Last);
      DeleteLast(&First,&Last);

       Display(First,Last);

      iRet = Count(First,Last);
      printf("Number of nodes are: %d\n",iRet);

      InsertAtPosition(&First,&Last,55,2);
      Display(First,Last);
      iRet = Count(First,Last);
      printf("Number of nodes are: %d\n",iRet);

      DeleteAtPosition(&First,&Last,2);
      Display(First,Last);
      iRet = Count(First,Last);
      printf("Number of nodes are: %d\n",iRet);



     return 0;
}