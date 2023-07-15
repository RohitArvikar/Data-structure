/////////////////////////
// Singly LL  // oop design
////////////////////////

#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;

}NODE,*PNODE,**PPNODE;

class SinglyLL
{
   private:
          PNODE First;                             //Characterstics
          int iCount;                              //Characterstics

   public:
          SinglyLL();

          void InsertFirst(int iNo);
          void InsertLast(int iNo);
          void InsertAtPosition(int iNo, int iPos);

          void DeletetFirst();
          void DeleteLast();
          void DeleteAtPosition(int iPos);

          void Display();
          int Count();
                   
};

// Implementations  of All behaviours  

void SinglyLL:: InsertFirst(int iNo)      /* ReturnValue_ClassName :: FunctionName(Parameter)*/   
{

}

void SinglyLL:: InsertLast(int iNo)
{

}

void SinglyLL:: InsertAtPosition(int iNo, int iPos)
{

}


void SinglyLL:: DeletetFirst()
{

}

void SinglyLL:: DeleteLast()
{

}

void SinglyLL:: DeleteAtPosition(int iPos)
{

}

void SinglyLL:: Display()
{

}

int SinglyLL:: Count()
{
    return 0;
}

SinglyLL::SinglyLL()
{

}

int main()
{
   SinglyLL obj1;



    return 0;
}


