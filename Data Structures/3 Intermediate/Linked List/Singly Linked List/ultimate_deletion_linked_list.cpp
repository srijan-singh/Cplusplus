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

// TO DELETE THE VALUES
void pop(Node **head, int position = -1)
{
  int count = 0;

  Node *head_ref = *head;
  Node *pos_node = NULL;

  // TO DELETE HEAD NODE
  if (position == 0)
  {
    *head = head_ref->next;
    free(head_ref);
    print(*head);
    return;
  }
  
  // TO DELETE TAIL NODE
  else if(position == -1) // DEFAULT CASE
  {
    // TRANSVERSING TILL SECOND LAST NODE
    while((head_ref->next)->next != NULL)
    {
      head_ref = head_ref->next;
    }
    // REMOVING THE LAST ELEMENT
    head_ref->next = NULL;
    print(*head);
    return;
  }
  
  // TO DELETE FROM SPECIFIC POSITION
  else
  {
    // TRANSVERSE
    while (head_ref != NULL && count<position)
    {
      pos_node = head_ref;
      head_ref = head_ref->next;
      count+=1;
    }
    // IF POSITION IS OUT OF RANGE
    if (head_ref == NULL)
    {
      std::cout<<"\nOut Of Range!\n";
      return;
    }
    // REMOVING THE SPECIFIC NODE
    else
    {
      pos_node->next = head_ref->next; // SKIPPING THE NODE
      print(*head);
      return;
    }
  }
}

int main()
{
  Node *head = new Node();
  
  list_creator(head);

  pop(&head, 0);

  pop(&head, 8);

  pop(&head, 0);

  return 0;
}