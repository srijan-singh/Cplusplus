#include <iostream>

std::string is_prime()
{
    int num; 
    int prime_arr[4] = {2,3,5,7};

    std::cout<<"Enter number between 1-100:\n";
    std::cin>>num;

    if (num == 2 or num == 3 or num == 5 or num == 7)
    {
        return "Prime";
    }

    for (auto p: prime_arr)
    {
        if (num % p == 0)
        {
            return "Non Prime";
        }   
    }
    return "Prime";
}

void tables()
{
    int num;
    std::cout<<"\nEnter the Number: ";
    std::cin>>num;
    
    for (int i=1; i<=10; i++)
    {
        std::cout<<num<<" x "<<i<<" = "<<num*i<<"\n";
    }
}

void days()
{
    int num;
    std::cout<<"Input Day Number (1-7): ";
    std::cin>>num;

    switch (num)
    {
    case 1:
        std::cout<<"Monday";
        break;

    case 2:
        std::cout<<"Tuesday";
        break;

    case 3:
        std::cout<<"Wednesday";
        break;

    case 4:
        std::cout<<"Thurshday";
        break;

    case 5:
        std::cout<<"Friday";
        break;

    case 6:
        std::cout<<"Saturday";
        break;

    case 7:
        std::cout<<"Sunday";
        break;  

    default:
        std::cout<<"Invalid!";
        break;
    }
}

void reverse()
{
    for (int i=10; i>=1; i--)
    {
        std::cout<<i<<" ";
    }
}

void multiple_of_5()
{
    int num;
    std::cout<<"\nInput num ";
    std::cin>>num;

    if (num%5 == 0)
    {
        std::cout<<"Multiple";
    }
    else
    {
        std::cout<<"Not Multiple";
    }
}

void area()
{
    int num;
    std::cout<<"1. Rectangle\n2. Square\n3. Triangle \n";
    std::cin>>num;
    switch (num)
    {
    case 1:
        /* code */
        int a,b;
        std::cout<<"\nInput Length ";
        std::cin>>a;
        std::cout<<"\nInput Breadth ";
        std::cin>>b;
        std::cout<<"\nArea: "<<a*b;
        break;

    case 2:
        int a1;
        std::cout<<"\nEnter Side: ";
        std::cin>>a1;
        std::cout<<"\nArea: "<<a1*a1;
        break;

    case 3:
        int b1,h;
        std::cout<<"\nInput Height ";
        std::cin>>h;
        std::cout<<"\nInput Base ";
        std::cin>>b1;
        std::cout<<"\nArea: "<<b1*h/2;
        break;
    
    default:
        std::cout<<"\nInvalid Inp!";
        break;
    }

}

int main()
{
    int input;
    std::cout<<"Use 1. Create a program which prints weather the number is prime or not.\n";
    std::cout<<"Use 2. Create a program which prints table of given number.\n";
    std::cout<<"Use 3. Create a program which prints day accoring to given number using switch case.\n";
    std::cout<<"Use 4. Create a program which prints 1 to 10 in reverse order.\n";
    std::cout<<"Use 5. Create a program which prints weather the entered number is multiplicable with 5 without reminder or not.\n";
    std::cout<<"Use 6. Create a program which takes choice from user to calculate the area of triangle, rectangle or square using switch case\n";
    std::cin>>input;

    switch(input)
    {
        case 1:
        std::cout<<is_prime();
        break;

        case 2:
        tables();
        break;

        case 3:
        days();
        break;

        case 4:
        reverse();
        break;

        case 5:
        multiple_of_5();
        break;

        case 6:
        area();
        break;

        default:
        std::cout<<"Invalid!";
        break;
    }
    return 0;
}