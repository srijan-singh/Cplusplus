#include <iostream>

struct Node
{
  int data;
  Node *next;
};

class linkedlist
{
  private:
  Node *head = NULL;

  public:

  void push(int data, int position = -1)
  {
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    // FOR FIRST TIME
    if (head == NULL)
    {
      head = new_node;
      return;
    }

    // INSERTION AT HEAD
    if (position == 0)
    {
      new_node->next = head;
      head = new_node;
      return;
    }

    // INSERTION AT TAIL
    else if (position == -1) // BY DEFAULT
    {
      Node *head_ref = head;

      while(head_ref->next != NULL)
      {
        head_ref = head_ref->next;
      }  

      head_ref->next = new_node;
      return;    
    }

    // INSERTION AT GIVEN POSITION
    else
    {
      int count = 0;
      Node *head_ref = head;
      Node *prev_node = NULL;
      
      // TRANSVERSING FOR GIVEN POSITION
      while (head_ref !=NULL && count<position)
     {
        prev_node = head_ref;
        head_ref = head_ref->next;
        count+=1;
      }

      // OUT OF RANGE
      if(head_ref == NULL && count<position)
      {
        std::cout<<"\n***\t***\tOUT OF RANGE\t***\t***\n\n";
        return;
      }
      
      // FOR GIVEN POSITION
      else
      {
        prev_node->next = new_node;
        new_node->next = head_ref;
        return;     
      }
    
    }
  }

  void pop(int position = -1)
  {
    // TO DELETE HEAD IF LIST IS EMPTY
    if (position == 0 || head->next == NULL) // IF LIST CONTAINS ONLY HEAD
      {
        head = head->next;
        return;
      }
    // TO DELETE TAIL
    else if (position == -1)
      {
        Node *head_ref = head;

        while ((head_ref->next)->next != NULL)
        {
          head_ref = head_ref->next;
        }

        head_ref->next = NULL;
        return;        
      }
      
    // TO DELETE AT SPECIFIC LOCATION
    else
    {
      int count = 0;
      Node *head_ref = head;
      Node *prev_node = NULL;
        
      // TRANSVERSING TILL SPECIFIC POSITION
      while(head_ref != NULL && count<position)
        {
          prev_node = head_ref;
          head_ref = head_ref->next;
          count += 1;
        }

      // OUT OF RANGE
      if (head_ref == NULL && count>position)
        {
          std::cout<<"Error!\n";    
          return;      
        }

      // TO ADD SPECIFIC LOCATION
      else
        {
          prev_node->next = head_ref->next;
          return;
        }
    }
  }

  void print()
  {
    Node *head_ref = head;

    // IF LIST IS EMPTY
    if (head_ref == NULL)
    {
      std::cout<<"\n***\tERROR: List is Empty!\t***\n\n";
      return;
    }

    while (head_ref != NULL)
    {
      std::cout<<head_ref->data<<" ";
      head_ref = head_ref->next;
    }
    std::cout<<"\n";
  }
};

int main()
{
  linkedlist l;
  l.print();
  l.push(12);
  l.print();
  l.push(13);
  l.print();
  l.push(11, 0);
  l.print();
  l.push(14, 3);
  l.print();
  l.pop(3);
  l.print();
  l.pop(1);
  l.print();
  l.pop();
  l.print();
  l.pop(-1);
  l.print();
  l.pop();
  l.print();
  return 0;
}