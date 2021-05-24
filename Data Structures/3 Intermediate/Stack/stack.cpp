#include <iostream>

struct Node
{
  int data;
  Node *next;
};

class stack
{
  Node *head = NULL;
  int size = 0;
  int count = 0;

  public:
  
  // STACKSIZE
  int length(int input)
  {
    size = input;
    return size;
  }
  // ADD VALUE
  void push(int data)
  {
    // INCREAMENT AFTER EVERY INPUT
    count +=1;
    // LEGAL INSERTION
    if (size == 0 || count <= size)
    {
      Node *new_node = new Node();
      new_node->data = data;
      
      // STACK IS EMPTY
      if (head == NULL)
      {
        new_node->next = NULL;
        head = new_node;
        return;
      }
      
      else
      {
        new_node->next = head;
        head = new_node;
        return;
      }
    }
    // STACKOVERFLOW
    else
    {
      std::cout<<"\tSTACKOVERFLOW\n";
    }
  }
  // DELETE VALUE
  int pop()
  {    
    if (head != NULL)
    {
      Node *head_ref = head;
      head = head_ref->next;
      return head_ref->data;      
    }
    
    else // STACKUNDERFLOW  
    {
      int none;
      std::cout<<"\tSTACKUNDERFLOW\n";
      return none;     
    }
  }
  // GET VALUE WITHOUT DELETING
  int peek(int position = 0) //BY DEFAULT HEAD VALUE
  {    
    if (head != NULL)
    {
        if (position == 0) //DEFAULT VALUE
        {
            return head->data;      
        }
        
        else // ANY OTHER VALUE
        {
            int count = 0;
            Node *head_ref = head;

            while(head_ref != NULL && count<position)
            {
                head_ref = head_ref->next;   
                count += 1;             
            }

            return head_ref->data;
        }
    }
    
    else // GARBAGE VALUE
    {
      int none;
      std::cout<<"\tSTACKUNDERFLOW\n";
      return none;      
    }

  }
  // PRINT LIST
  void print()
  {    
    if (head != NULL)
    {
      Node *head_ref = head; 
      // TRANSVERSE
      while (head_ref != NULL)
    {
      std::cout<<head_ref->data<<" ";
      head_ref = head_ref->next;
    }  
      //NEWLINE
      std::cout<<"\n";
      return;
    }
    
    else // STACKUNDERFLOW  
    {
      std::cout<<"\tSTACKUNDERFLOW";
      return;
    }

    
  }
};

int main()
{
  stack s;
  int pop_value;
  pop_value = s.pop();
  s.length(3);
  s.push(1);
  int data = s.peek();
  s.print();
  std::cout<<"Peek Value: "<<data<<"\n";
  s.print();
  s.push(2);
  s.print();
  s.push(3);
  s.print();
  data = s.peek();
  std::cout<<"Peek Value: "<<data<<"\n";
  s.print();
  s.push(4);
  s.print();
  pop_value = s.pop();
  s.print();
  std::cout<<"Pop Value: \t"<<pop_value<<"\n";
  s.print();
  pop_value = s.pop();
  std::cout<<"Pop Value: \t"<<pop_value<<"\n";
  s.print();
  pop_value = s.pop();
  std::cout<<"Pop Value: \t"<<pop_value<<"\n";
  s.print();
  pop_value = s.pop();
  std::cout<<"Pop Value: \t"<<pop_value<<"\n";
  
  return 0;
}