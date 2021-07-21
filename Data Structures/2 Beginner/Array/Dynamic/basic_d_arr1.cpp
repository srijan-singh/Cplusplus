/*
    C++
    Dynamic Array 
    Srijan Singh 
    12th July 2021
*/

#include <iostream>

class DynamicArray
{
    int size; // Inital size of the dynamic array
    int *d_arr; 
    int index = 0;

    public:

    DynamicArray(int length)
    {
        size = length; 
        d_arr = new int[size]; // Initialization of Dynamic Array
    }

    void append(int num)
    {
        d_arr[index] = num;
        index++;
        
        if (index > size)
        {
            size = index; // If index is greater, than size equals to index
            return;
        }
    }

    void pop()
    {
        d_arr[size-1] = 0;

        // Adjusting the size
        size--;
        index--;
    }

    void print()
    {
        std::cout<<"Array : ";
        for(int i=0; i<size; i++)
        {
            std::cout<<d_arr[i]<<" ";
        }
        std::cout<<"\n";
    }

    ~DynamicArray()
    {
        delete d_arr;
    }
};

int main()
{
    DynamicArray d(3);

    d.append(1);
    d.append(2);
    d.append(5);
    d.print();
    d.pop();    
    d.print();
    d.append(3);
    d.print();
    d.append(11);
    d.print();

    return 0;
}