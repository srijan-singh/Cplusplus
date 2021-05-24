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
    std::cout<<n->data<<"\n";
    n = n->next;
  }
}

void push(Node **head_ref, int data)
{
  Node *new_node = NULL;

  new_node = new Node();

  new_node->data = data;

  new_node->next = *head_ref;

  *head_ref = new_node;
}

int main()
{
  Node *head = NULL;

  int test_case;

  std::cin>>test_case;

  for (int i=0; i<test_case; i++)
  {
    int input;
    std::cin>>input;
    push(&head, input);
  }

  print(head);

  return 0;
}