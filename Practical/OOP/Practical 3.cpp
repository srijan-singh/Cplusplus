#include <iostream>

int fibbonaci(int term)
{   /*
    T1,T2,T3,T4,T5,T6,........ 
     0, 1, 1, 2, 3, 5,........
    T3 = T2+T1 (i.e. 1 = 1+0)
    TN = T(N-1) + T(N-2)
    */

    if (term == 1)
    {
        return 0;
    }

    if (term == 2)
    {
        return 1;
    }
    return fibbonaci(term-1) + fibbonaci(term-2);
}

inline void arithmetic_opertion(float num1, float num2, char oprtr)
{
    switch (oprtr)
    {
        case '+':
            std::cout<<num1+num2;
            break;
        case '-':
            std::cout<<num1-num2;
            break;
        case '/':
            std::cout<<num1/num2;
            break;
        default:
            std::cout<<"Error: Invalid Operator";
            break;
    }
}

int main()
{
    int input;
    std::cout<<"\nUse 1. For Fibbonaci Series\n";
    std::cout<<"\nUse 2. For Inline Arithmetic Operation\n\n";
    std::cin>>input;

    switch (input)
    {

    case 1:
        int term;
        std::cout<<"\nEnter the term till the Fibbonaci Series is to be printed: ";
        std::cin>>term;
        std::cout<<"\nSeries: ";

        for(int i=1; i<=term; i++)
        {
            std::cout<<fibbonaci(i)<<" ";
        }

        break;

    case 2:

        int num1, num2;
        char oprtr;
        std::cout<<"Enter the two numbers: ";
        std::cin>>num1>>num2;
        std::cout<<"Enter the operation\nUse + for addition\nUse - for subtraction\nUse / for division\n";
        std::cin>>oprtr;
        std::cout<<"Answer: ";
        arithmetic_opertion(num1,num2,oprtr);
        break;
    
    default:
        std::cout<<"Error: Invalid Use Case";
        break;
    }

    return 0;
}