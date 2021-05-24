#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class queue
{
    Node *head = NULL;

    public:

    // PRINT QUEUE
    void print()
    {
        if (head == NULL)
        {
            std::cout<<"***\tQUEUE IS EMPTY!\t***\n";
            return;
        }
        else
        {
            Node *head_ref = head;

            while (head_ref != NULL)
            {
                std::cout<<head_ref->data<<" ";
                head_ref = head_ref->next;
            }

            std::cout<<"\n";
            return;            
        }
    }
    // ADD ELEMENT
    void push(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;

        // IF QUEUE IS EMPTY
        if (head == NULL)
        {
            head = new_node;
            return;
        }

        else // ADD AT TAIL
        {
            Node *head_ref = head;

            // TRANSVERSING 
            while (head_ref->next != NULL)
            {
                head_ref = head_ref->next;
            }
            // ADDING AT TAIL
            head_ref->next = new_node;
            
        }
    }
    // REMOVE ELEMENT
    int pop()
    {
        if (head != NULL)
        {
            Node *head_ref = head;
            // REMOVING HEAD
            head = head_ref->next;
            // RETURNING HEAD DATA
            return head_ref->data;            
        }
        
        else // RETURNS GARBAGE VALUE
        {
            int garbage_value;
            std::cout<<"\n***\tQUEUE IS EMPTY!\t***\n";
            return garbage_value;
        }
    }
    // GET VALUE WITHOUT DELETING
    int peek(int position = 0) //BY DEFAULT HEAD VALUE
    {        
        if (head != NULL)
        {
            if (position == 0) //DEFAULT VALUE
            {
                // RETURNING HEAD DATA
                return head->data; 
            }  
            
            else // ANY OTHER VALUE
            {
                int count = 0;
                Node *head_ref = head;
                // TRANSVERSE
                while(head_ref != NULL && count<position)
                {
                    head_ref = head_ref->next;   
                    count += 1;             
                }
                // RETURNING HEAD DATA
                return head_ref->data;
            } 

        }
        
        else // RETURNS GARBAGE VALUE
        {
            int garbage_value;
            std::cout<<"\n***\tQUEUE IS EMPTY!\t***\n";
            return garbage_value;
        }
            
    }
};

int main()
{
    queue q;
    q.print();
    q.push(11);
    q.print();
    q.push(12);
    q.print();
    int data = q.peek();
    std::cout<<"Peek Value: "<<data<<"\n";
    q.print();
    data = q.pop();
    q.print();
    std::cout<<"Pop value: "<<data;
    q.pop();
    q.pop();

    return 0;
}