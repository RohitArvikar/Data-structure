////////////////////////////////////
// Doubly Linear LL
//////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;           // # 

}NODE,*PNODE,**PPNODE;
//////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->prev = NULL;
    newn->data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
      (*Head)-> prev = newn;                  //#
       newn -> next = *Head;
       *Head = newn;  
    }
}
//////////////////////////////////////////////////////////
void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->prev = NULL;
    newn->data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp -> next != NULL)              // type 2 cha while loop ahe
        {
            temp = temp -> next;
        }
        
        temp->next = newn;
        newn->prev = temp;                         //#
        
        
    }
}
//////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
  printf("The elements of Linked List are: \n");

  printf("NULL <=>");

  while(Head != NULL)
  {
    printf(" | %d | <=> ",Head->data);
    Head = Head -> next;
  }

  printf("NULL\n");
}  
////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
 

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
      *Head = (*Head) -> next;
       free((*Head)->prev);
       (*Head)->prev = NULL; 
       
    }
}

/////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
   PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
      while(temp ->next->next != NULL)      // type 3
      {
         temp = temp->next;
      }

       free(temp->next);
       temp->next = NULL;
    } 
}

/////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE Head, int iNo, int iPos)
{
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    int icnt = 0;

    iLength = Count(*Head);
    printf("iLength = %d\n",iLength);

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid Position");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(Head,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;                          //#

        for(icnt = 1; icnt < iPos-1; icnt++)
        {
           temp = temp -> next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;     //#
        temp->next = newn;
        newn -> prev = temp;          //#
        

    }
}
/////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE Head , int iPos)
{
    int iLength = 0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    int icnt = 0;

    iLength = Count(*Head);
    printf("iLength = %d\n",iLength);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid Position");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head);
    }
    else
    {

        for(icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp -> next;
        }
        
        temp -> next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;

    }
}

////////////////////////////////////////////////////////////////////////
int main()
{
  PNODE First = NULL;
  int iRet = 0;
  

  InsertFirst(&First,101);
  InsertFirst(&First,51);
  InsertFirst(&First,21);
  InsertFirst(&First,11);


  iRet = Count(First);
  printf("Number of elements are: %d\n",iRet);

  printf("//////////////////////////////////////////////////\n");

  printf("Insert First LOGIC: \n");
  Display(First);

  printf("//////////////////////////////////////////////////\n");

  InsertLast(&First,111);
  InsertLast(&First,121);
 
  printf("Insert Last LOGIC: \n");
  Display(First);

  iRet = Count(First);
  printf("Number of elements are: %d\n",iRet);


  printf("//////////////////////////////////////////////////\n");

  DeleteFirst(&First);

  printf("Delete First Logic\n");
  Display(First);

 printf("//////////////////////////////////////////////////\n");

  DeleteLast(&First);

  printf("Delete Last Logic\n");
  Display(First);

 printf("//////////////////////////////////////////////////\n");

 printf("Inser At Position LOGIC\n");
 InsertAtPosition(&First,55,4);

 Display(First);

printf("//////////////////////////////////////////////////\n");

printf("Delete At Position LOGIC\n");
DeleteAtPosition(&First,4);

 Display(First);





    return 0;
}