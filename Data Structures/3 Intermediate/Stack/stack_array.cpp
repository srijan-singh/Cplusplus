#include <iostream>

class stack
{
    int *arr;
    int length;
    int count = -1;

    public:
    // SET LIMIT
    int stack_length(int input)
    {
        length = input;
        arr = new int[length];
        return length;
    }
    // ADD VALUE   
    void push(int data)
    {
        if(count<length) // LEGAL
        {
            arr[++count] = data;
            return;
        }
        //STACKOVERFLOW
        else
        {
            std::cout<<"***\tSTACK OVERFLOW\n";
            return;
        }
    }
    // DELETE VALUE
    int pop()
    {
        if (count > -1) // LEGAL
        {   
            int data = arr[count--];
            return data;            
        }
        // STACKUNDERFLOW
        else
        {
            int garbage_value;
            std::cout<<"\tSTACKUNDERFLOW\n";    
            return garbage_value;        
        }
        
    }
    // PRINT HEAD VALUE WITHOUT DELETING
    int peek(int position = 0)
    {        
        if (count > -1 && position<count) // LEGAL
        {   
            int data = arr[count-position];
            return data;            
        }
        // OUT OF RANGE
        else if (position>=count)
        {
            int garbage_value;
            std::cout<<"\tOUT OF RANGE\n";    
            return garbage_value;     
        }
        // STACKUNDERFLOW
        else
        {
            int garbage_value;
            std::cout<<"\tSTACKUNDERFLOW\n";    
            return garbage_value;        
        }
    
    }
    // PRINT STACK
    void print()
    {        
        if (count > -1) // LEGAL
        {   
            for(int i=count; i>-1; i--)
            {
                std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
            return;            
        }
        // STACKUNDERFLOW
        else
        {
            std::cout<<"\tSTACKUNDERFLOW\n";
        }
    }

};

int main()
{
    stack s;
    s.stack_length(5);
    s.push(1);
    s.print();
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.push(4);
    s.print();
    s.push(5);
    s.print();
    std::cout<<"Peek Value: "<<s.peek(5)<<"\n";
    s.print();
    int pop_value = s.pop();
    std::cout<<"Pop Value: \t"<<pop_value<<"\n";
    s.print();
    s.push(5);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    return 0;
}