//////////////
// stack
//////////////


#include<iostream>
using namespace std;

typedef class Node
{
    public:
          int data;
          Node *next;

          Node(int iValue)
          {
            data = iValue;
            next = NULL;
          }

}NODE,*PNODE;

class stack
{
    private: 
           PNODE First;
           int iCount;

    public:
           stack();
           void Push(int iNo);           // InsertLast
           int Pop();                   // Delete Last
           void Display();
           int Count();
};

stack::stack()
{
   First = NULL;
   iCount = 0;
}
void stack:: Push(int iNo)
{
   PNODE newn = new NODE(iNo);

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
int stack:: Pop()           //DeleteLast
{
    int iValue = 0;

   if(iCount == 0)
   {
     cout<<"Stack is empty"<<"\n";
     return -1;
   }
   else if(iCount == 1)
   {
      iValue = First->data;
      delete First;
      First = NULL;
   }
   else
   {
      PNODE temp = First;

      while(temp->next->next != NULL)
      {
        temp = temp->next;
      }

      Value = temp->next->data;
      delete temp->next;
      temp->next = NULL;
   }

   iCount--;
   return iValue;
}                  
void stack:: Display()
{
  if(First == NULL)
  {
    cout<<"Nothing to display as stack is empty\n";
    return;
  }
  
  cout<<"Elements of stack are: "<<"\n";

  PNODE temp = First;

  for(int icnt = 1; icnt<=iCount; icnt++)
  {
    cout<<temp->data<<"\n";
    temp = temp->next;
  }
}
int stack::Count()
{
   return iCount;
}

int main()
{

    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    stack obj;

    cout<<"--------------------------------------------------------------\n";
    cout<<"Dynamic Implementation of stack\n";
    cout<<"--------------------------------------------------------------\n";

    while(iChoice != 0)
    {
        cout<<"--------------------------------------------------------------\n";
        
        cout<<"1 : Push element into stack\n";
        cout<<"2 : Pop element from stack\n";
        cout<<"3 : Display element from stack\n";
        cout<<"4 : Count number of element from stack\n";
        cout<<"0 : Terminate the application\n";

        cout<<"--------------------------------------------------------------\n";
        


        cout<<"Please enter the option: "<<"\n";
        cin>>iChoice;


        switch(iChoice)
        {
            case 1:
                  cout<<"Enter the element that you want to push in stack"<<"\n";
                  cin>>iValue;
                  obj.Push(iValue);
                  break;

            case 2:
                  iRet =  obj.Pop();
                  if(iRet != -1)
                  {
                    cout<<"Poped element from stack is: "<<iRet<<"\n";
                  }
                  break;

            case 3:
                  obj.Display();
                  break;
                  
            
        }



        
    }
    

    return 0;
}