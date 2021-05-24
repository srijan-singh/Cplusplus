#include <iostream>

class Node
{
  public:
  int data;
  Node *next;
};

// TO PRINT THE LINKED LIST
void print(Node *n)
{
  while(n!=NULL)
  {
  std::cout<<n->data<<" ";
  n = n->next;
  }
  std::cout<<"\n";
}

// TO INSERT THE VALUES
void insert(Node *head, int value, int position=-1)
{
  int count = 0;

  Node *head_ref = head;
  Node *prev_node = new Node();
  Node *new_node = new Node();

  // ASSIGNING THE GIVEN VALUE
  new_node->data = value;

  // INSERTION AT HEAD
  if (position == 0)
  {
    new_node->next = head_ref;
    head_ref = new_node;
    print(head_ref);
    return;
  }

  // INSERTION AT TAIL/LAST
  else if (position == -1) // DEFAULT VALUE
  {
    // TRANSVERSAL
    while (head_ref->next !=NULL)
    {
      head_ref = head_ref->next;
    }    
    // ADDING THE NODE
    head_ref->next = new_node;
    new_node->next = NULL;

    print(head);
    return;
  }

  // INSERTION AT SPECIFIC LOCATION
  else
  {
    // TRANSVERSAL TILL SPECIFIC LOCATION
    while (head_ref !=NULL && count<position)
    {
      prev_node = head_ref;
      head_ref = head_ref->next;
      count+=1;
    }
    
    // IF IT'S REACH TO THE END
    if (head == NULL)
    {
      head_ref->next = new_node;
      new_node->next = NULL;
      print(head);
      return;
    }
    
    // LINKING THE NEW NODE TO THE SPECIFIC LOCATION
    else
    {
      prev_node->next = new_node;
      new_node->next = head_ref;
      print(head);
      return;
    }
  }
}

// TO POPULATE LINKED LIST WITH VALUES
void list_creator(Node *head)
{
  Node *second = new Node();
  Node *tail = new Node();
  
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = tail;

  tail->data = 3;
  tail->next = NULL;

}

int main()
{
  Node *head = new Node();
  
  list_creator(head);
  
  // To insert at last
  insert(head, 8);

  // To insert at head
  insert(head, 11, 0);

  // To insert at specific position
  insert(head, 19, 3);

  return 0;
}