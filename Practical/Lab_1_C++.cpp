#include <iostream>

float add(int range = 2)
{
    float num[range];

    float result = 0;
    
    for (int i = 0; i < range; i++)
    {
        std::cin>>num[i];
    }
    for (int i = 0; i < range; i++)
    {
        result += num[i];
    }
    
    return result;
}

float average(int range = 3)
{
    float num[range] = {};
    float result = 0;

    for(int i = 0; i<range; i++)
    {
        std::cin>>num[i];
    }

    for (int i = 0; i < range; i++)
    {
        result+=num[i];
    }

    return result/range;
    
}

float get_marks(int range = 5)
{
    float marks[range] = {};
    float total;
    for (int i = 0; i<range; i++)
    {
        std::cin>>marks[i];
    }
    for (int i = 0; i<range; i++)
    {
        total += marks[i];
    }
    return total/range;
}

char get_grades(float total = get_marks())
{
    char grades[5] = {'A','B','C','D','F'};
    
    int marks[4] = {70, 60, 50, 35};
    
    if (total < marks[3])
    {
        return grades[4];
    }

    else if (total >= marks[3] and total < marks[2])
    {
        return grades[3];
    }
    else if (total >= marks[2] and total < marks[1])
    {
        return grades[2];
    }
    else if (total >= marks[1] and total < marks[0])
    {
        return grades[1];
    }
    else
    {
        return grades[0];
    }
}

float get_temp()
{
    float celcius;
    std::cin>>celcius;
    return celcius;
}

float c_to_f(float temp = get_temp())
{
    return (1.8*temp) + 32;
}

int main()
{
    int input;
    std::cout<<"Use 1. Print Name.\n";
    std::cout<<"Use 2. Print Address.\n";
    std::cout<<"Use 3. Add two numbers.\n";
    std::cout<<"Use 4. Write a program which takes three values from user and calculate average of it.\n";
    std::cout<<"Use 5. Write a program which takes 5 subject marks from user. Calculate average of it. According to average display appropriate grade.\n";
    std::cout<<"Use 6. Write a program which takes temperature value in Celsius and coverts it in Fahrenheit.\n";
    std::cin>>input;

    switch(input)
    {
        case 1:
        std::cout<<"Srijan";
        break;

        case 2:
        std::cout<<"Varanasi";
        break;

        case 3:
        std::cout<<add();
        break;

        case 4:
        std::cout<<average();
        break;

        case 5:
        std::cout<<get_grades();
        break;

        case 6:
        std::cout<<c_to_f();
        break;

        default:
        std::cout<<"Invalid!";
        break;
    }
    return 0;
}