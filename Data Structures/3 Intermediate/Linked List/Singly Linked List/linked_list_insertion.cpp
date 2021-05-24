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

void push(Node **head_ref, int data)
{
  Node *new_node = NULL;

  new_node = new Node();

  new_node->data = data;

  new_node->next = (*head_ref);

  (*head_ref) = new_node;

}

void push_after(Node *prev_node, int data)
{
  if (prev_node == NULL)
  {
    std::cout<<"\nError: The previous node can't be empty\n";
  }
  Node *new_node = NULL;

  new_node = new Node();

  new_node->data = data;

  new_node->next = prev_node->next; // linking to the next node which previous node was linking

  prev_node->next = new_node; // linking to the new node

}

void append(Node **head_ref, int data)
{
  Node *last = *head_ref;

  Node *new_node = NULL;

  new_node = new Node();

  new_node->data = data;

  new_node->next = NULL;

  // If Linked List is empty

  if (*head_ref == NULL)
  {
    *head_ref = new_node;    
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = new_node;
  return;
}

int main()
{
  // creating the head

  Node *head = NULL;

  std::cout<<"\nLinked List: \n"; // transversing
  print(head);
  append(&head, 12);
  std::cout<<"\nLinked List: \n";
  print(head);
  push(&head, 10);
  std::cout<<"\nLinked List: \n";
  print(head);
  push_after(head, 11);
  std::cout<<"\nLinked List: \n";
  print(head);
  
  return 0;
}