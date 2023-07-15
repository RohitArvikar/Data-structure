/////////////////////////
// Project part 
////////////////////////

#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;

}NODE,*PNODE;

class SinglyLL
{
   private:
          PNODE First;                             //Characterstics
          int iCount;                              //Characterstics

   public:
          SinglyLL();
          ~SinglyLL();

          void InsertFirst(int iNo);
          void InsertLast(int iNo);
          void InsertAtPosition(int iNo, int iPos);

          void DeleteFirst();
          void DeleteLast();
          void DeleteAtPosition(int iPos);

          void Display();
          int Count();
                   
};

// Implementations  of All behaviours  

void SinglyLL:: InsertFirst(int iNo)      /* ReturnValue_ClassName :: FunctionName(Parameter)*/   
{
   PNODE newn = NULL;
   newn = new NODE;        //newn = (PNODE)malloc(sizeof(NODE));


   newn->data = iNo;
   newn->next = NULL;


   if(First == NULL)
   {
      First = newn;
   }
   else
   {
     newn->next = First;
     First = newn;
   }

   iCount++;

}

void SinglyLL:: InsertLast(int iNo)
{
   PNODE newn = NULL;
   newn = new NODE;        //newn = (PNODE)malloc(sizeof(NODE));


   newn->data = iNo;
   newn->next = NULL;


   if(First == NULL)
   {
      First = newn;
   }
   else
   {
     PNODE temp = First;

     while(temp->next != NULL)
     {
        temp = temp->next;
     }

     temp->next = newn;

   }

   iCount++;
   
}

void SinglyLL:: InsertAtPosition(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = iNo;
        newn->next = NULL;

        PNODE temp = First;
        int icnt = 0;

        for(icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }

    
}


void SinglyLL:: DeleteFirst()
{
   if(First == NULL)
   {
      return;
   }
   else if(First->next == NULL)
   {
      delete First;          // free(First);
      First = NULL;
   }
   else
   {
      PNODE temp = First;
      First = First->next;
      delete temp;

     
   }

    iCount--; 
}

void SinglyLL:: DeleteLast()
{
   if(First == NULL)
   {
      return;
   }
   else if(First->next == NULL)
   {
      delete First;          // free(First);
      First = NULL;
   }
   else
   {
      PNODE temp = First;

      while(temp->next->next != NULL)
      {
        temp = temp->next;
      }

      delete temp->next;
      temp->next = NULL;
   }

   iCount--;
}

void SinglyLL:: DeleteAtPosition(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        
        
        PNODE temp = First;
        PNODE tempX = NULL;
        int icnt = 0;

        for(icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;

        temp->next = temp->next->next;

        delete tempX;

         iCount--;
    }

   
}

void SinglyLL:: Display()
{
  PNODE temp = First;

  cout<<"Elements of Linked List are: "<<"\n";

  while(temp != NULL)
  {
    cout<<"| "<<temp->data<<" |-> ";
    temp = temp->next;
  }

   cout<<"NULL"<<"\n";
}

int SinglyLL:: Count()
{
    return iCount;
}

SinglyLL::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

SinglyLL::~SinglyLL()
{
    cout<<"Inside Destructor\n"; 

     PNODE temp = First

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }   
}


int main()
{
   SinglyLL obj;
   int iChoice = 0;
   int iValue = 0;
   int iPosition = 0;

   cout<<"Marvellous Linked List Application\n";

   while(1)
   {
     cout<<"Please enter your choice"<<"\n";
     cout<<"1: Insert node At First Position"<<"\n";
     cout<<"2: Insert node At Last Position"<<"\n";
     cout<<"3: Insert node At Given Position"<<"\n";
     cout<<"4: Delete node At First Position"<<"\n";
     cout<<"5: Delete node At Last Position"<<"\n";
     cout<<"6: Delete node At Given Position"<<"\n";
     cout<<"7: Display the elements of Linked List"<<"\n";
     cout<<"8: Count the numbers of nodes in Linked List"<<"\n";
     cout<<"9: Terminate the Application"<<"\n";
  
     cin>>iChoice;

     cout<<"--------------------------------------------------------------------\n";

     switch(iChoice)
     {
       case 1:
              cout<<"Enter the Value that you want to insert: "<<"\n";
              cin>>iValue;
              obj.InsertFirst(iValue);
              break;

        case 2:
              cout<<"Enter the Value that you want to insert: "<<"\n";
              cin>>iValue;
              obj.InsertLast(iValue);
              break;

        case 3:
              cout<<"Enter the Value that you want to insert: "<<"\n";
              cin>>iValue;

              cout<<"Enter the Position: "<<"\n";
              cin>>iPosition;

              obj.InsertAtPosition(iValue,iPosition);
              break;


        case 4:
              obj.DeleteFirst();
              break;

        case 5:
              obj.DeleteLast();
              break;

        case 6:
              
             cout<<"Enter the Position: "<<"\n";
              cin>>iPosition;

              obj.DeleteAtPosition(iPosition);
              break;

        case 7:
              obj.Display();
              break;

        case 8:
              cout<<"Numbers of elements are: "<<obj.Count()<<"\n";
              break;

        case 9:
              cout<<"Thank you for using the application"<<"\n";
              return 0;

        default :
                cout<<"Invalid Choice"<<"\n";
                break;

      }

   }
   


   
    return 0;
}


