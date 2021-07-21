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

    void insert(int elementIndex, int element)
    {        
        int *temp_d_arr = new int[size+1]; // Initializing Temporary Dynamic Array

        if (elementIndex == 0) // If element has to be inserted at beginning
        {
            temp_d_arr[0] = element;

            for(int i=1; i<size+1; i++)
            {
                temp_d_arr[i] = d_arr[i-1];
            }

        }

        else
        {
            for(int i = 0; i<elementIndex; i++) // Copy the element before the element
            {
                temp_d_arr[i] = d_arr[i];
            }

            temp_d_arr[elementIndex] = element;

            for(int i = elementIndex+1; i<size+1; i++) // Copy element after the given element
            {
                temp_d_arr[i] = d_arr[i-1];
            }
        }      

        // Adjusting the size and index
        size++; 

        if (elementIndex > index)
        {
            index = elementIndex+1;
        }

        else
        {
            index++; 
        }

        // Copying the temporary array in main array and deleting it.
        d_arr = temp_d_arr;

        temp_d_arr = NULL;

        delete temp_d_arr;
    }

    void remove(int element)
    {
        int *temp_d_arr = new int[size-1];
        int temp_index = 0;

        for(int i=0; i<size; i++)
        {
            if(d_arr[i] != element)
            {
                temp_d_arr[temp_index] = d_arr[i];
                temp_index++;
            }
        }

        // Adjusting the size and index
        size--; 

        if (temp_index > index)
        {
            index = temp_index+1;
        }
        
        else
        {
            index--; 
        }

        // Copying the temporary array in main array and deleting it.
        d_arr = temp_d_arr;

        temp_d_arr = NULL;

        delete temp_d_arr;
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
    d.insert(0, 7);
    d.print();
    d.insert(2,9);
    d.print();
    d.remove(1);
    d.print();
    d.append(3);
    d.print();
    d.remove(3);
    d.print();
    d.append(11);
    d.print();
    
    return 0;
}