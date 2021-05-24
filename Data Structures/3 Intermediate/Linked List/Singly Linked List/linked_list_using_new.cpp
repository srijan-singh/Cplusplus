#include <iostream>

class Node
{
  public:
  int data;
  Node *next;
};

void print(Node *n)
{
    while(n != NULL)
    {
      std::cout<<n->data<<" ";
      n = n->next; 
    }
}

int main()
{
  // creating the pointers

  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;
  Node *tail = NULL;

  // allocating the blocks connected with the pointers

  head = new Node();
  second = new Node();
  third = new Node();
  tail = new Node();

  // assigning then value

  head->data = 1; // the value 
  head->next = second; // pointers towards the next value

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = tail;

  tail->data = 4;
  tail->next = NULL; //end of the list

  print(head);
  
  return 0;
}