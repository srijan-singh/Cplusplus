#include <iostream>
#include <string>

struct student
{
    std::string name;
    int roll;
    float marks;
    std::string address;
};

void student_details()
{
    std::cout<<"\nStudent Details";
    student s;
    // Input
    std::cout<<"\nEnter Name: ";
    std::cin>>s.name;
    std::cout<<"\nEnter Address: ";
    std::cin>>s.address;
    std::cout<<"\nEnter Roll Number: ";
    std::cin>>s.roll;
    std::cout<<"\nEnter Total Marks: ";
    std::cin>>s.marks;

    //Output
    std::cout<<"\nName:        \t"<<s.name;
    std::cout<<"\nAdress:      \t"<<s.address;
    std::cout<<"\nRoll Number: \t"<<s.roll;
    std::cout<<"\nMarks:       \t"<<s.marks;
}

void odd_even()
{
    std::cout<<"\nOdd or Even\n";
    int num;
    std::cout<<"Enter a number: ";
    std::cin>>num;
    if(num%2==0)
    {
        std::cout<<"\nEven";
        return;
    }
    std::cout<<"Odd";
    return; 
}

void calculator()
{
    float num1,num2;   
    char operand;

    std::cout<<"\n**Calculator**";
    std::cout<<"\nUse + for addition\nUse - for subtraction\nUse * for multiplication\nUse / for division\n";
    
    std::cout<<"\nEnter two numbers: ";
    std::cin>>num1>>num2;
    std::cout<<"\nEnter operation: ";
    std::cin>>operand;
    
    switch (operand)
    {
    case '+':
        std::cout<<"\nAnswer: ";
        std::cout<<num1+num2;
        break;

    case '-':
        std::cout<<"\nAnswer: ";
        std::cout<<num1-num2;
        break;

    case '*':
        std::cout<<"\nAnswer: ";
        std::cout<<num1*num2;
        break;

    case '/':
        std::cout<<"\nAnswer: ";
        std::cout<<num1/num2;
        break;
    
    default:
        std::cout<<"Invalid Input";
        break;
    }
}

int main()
{
    int input;

    std::cout<<"Use 1 For Practical 1\n";
    std::cout<<"Use 2 For Practical 2 Part 1\n";
    std::cout<<"Use 3 For Practical 2 Part 2\n";

    std::cin>>input;

    switch(input)
    {
    case 1:
        student_details();
        break;
    case 2:
        odd_even();
        break;
    case 3:
        calculator();
        break;
    default:
        std::cout<<"Invalid Input!";
        break;
    }
    
    return 0;
}