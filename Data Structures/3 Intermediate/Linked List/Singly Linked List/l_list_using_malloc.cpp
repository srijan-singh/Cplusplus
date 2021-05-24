/*
Memory Allocation = malloc

ptr = (int*) malloc(100 * sizeof(int));

Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. 
And, the pointer ptr holds the address of the first byte in the allocated memory.
*/
#include <iostream>

struct Node
{
    int data;
    struct Node *next;  
};

//Global variable
struct Node *head;

//function to insert
void insert(int n)
{
    Node *temp = (Node*)malloc(sizeof(struct Node));
    //or(*temp).data = n;
    temp->data = n; //most used way
    temp->next = head;
    head = temp;
}
//function to print
void print()
{
    struct Node *temp = head;
    std::cout<<"List is: \n";
    while(temp != NULL)
    {
        std::cout<<temp->data<<"\n";
        temp=temp->next;
    }
    std::cout<<"\n";
}

int main()
{
    head = NULL;
    int len;
    std::cout<<"Number of elements: ";    
    std::cin>>len;
    for(int i=0; i<len; i++)
    {
        int x;
        std::cout<<"Element "<<i+1<<":\t";
        std::cin>>x;
        insert(x);
    }
    print();
    return 0;
}