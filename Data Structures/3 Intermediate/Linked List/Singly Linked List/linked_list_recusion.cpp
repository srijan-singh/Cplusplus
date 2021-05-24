#include <iostream>

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

    Node *appendage(Node *head, int data, int value=-1)
    {
        // NODE IS NULL
        if (head == NULL)
        {
            head = new Node();
            head->data = data;
            head->next = NULL;
            return head; 
        }
        
        // NEXT TO VALUE
        else if(head->data == value)
        {
            Node *new_node = new Node();
            new_node->data = data;

            new_node->next = head->next;
            head->next = new_node;

            return head;

        }
        
        // TRANSVERSE TO NEXT NODE
        else
        {
            head->next = appendage(head->next, data, value);
        }

        return head;
    }
    
    Node *insertion(Node *head, int data, int position)
    {
        // HEAD
        if (position == 0)
        {
            Node *new_node = new Node();
            new_node->data = data;
            new_node->next = head;
            head = new_node;
            delete new_node;
        }

        // APPEND
        else if (position == -1 or head == NULL)
        {
            head = appendage(head, data);
        }
        
        // SPECIFIC LOCATION
        else
        {
            int count = 0;
            Node *head_ref = head;
            Node *prev_node = NULL;

            while(head_ref != NULL and count < position)
            {
                prev_node = head_ref;
                head_ref = head_ref->next;
                count += 1; 
            }

            if (head_ref == NULL and count < position)
            {
                std::cout<<"\tOUT OF RANGE\t\n";
                return head;
            }

            else
            {
                Node *new_node = new Node();
                new_node->data = data;

                prev_node->next = new_node;
                new_node->next = head_ref;
            }
        }
        
        return head;
    }
    
    Node *deletion(Node *head, int data)
    {
        if (head == NULL)
        {
            return head;
        }

        else if (head->data == data)
        {
            Node *temp_node = head;
            head = head->next;
            delete temp_node;
            return head;
        }

        else
        {
            head->next = deletion(head->next, data);
        }

        return head;
    }
    
    Node *pop(Node *head)
    {
        if ((head->next)->next == NULL)
        {
            head->next = NULL;
            return head;
        }

        head->next = pop(head->next);     

        return head;
    }

    Node *peek(Node *head)
    {
        if (head->next == NULL)
        {
            return head;
        }

        return head->next = peek(head->next);
    }

    void print_list(Node *head)
    {
        if (head == NULL)
        {
            return;
        }

        std::cout<<head->data<<" ";

        print_list(head->next);
    }

    public:

    LinkedList()
    {
        head = NULL;
    }

    void append(int data, int value = -1)
    {
        head = appendage(head, data, value);
    }
    
    void insert(int data, int position = -1)
    {
        head = insertion(head, data, position);
    }

    void remove(int data)
    {
        head = deletion(head ,data);
    }

    int pop()
    {
        return pop(head)->data;
    }

    int peek()
    {
        return peek(head)->data;
    }
    
    void print()
    {
        print_list(head);

        std::cout<<"\n";
    }
};

int main()
{
    LinkedList l;
    l.append(11);
    l.append(12);
    l.print();
    l.insert(10, 8);
    l.print();
    l.append(14);
    l.print();
    l.append(100, 12);
    l.print();
    l.insert(13,2);
    l.print();
    l.insert(16);
    l.print();
    l.insert(15,4);
    l.print();
    l.pop();
    l.print();
    l.remove(13);
    l.print();
    std::cout<< l.peek();;
    return 0;
}