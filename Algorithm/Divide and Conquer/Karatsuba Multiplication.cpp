// num1 = a*10**x/2 + b  
// num2 = c*10**y/2 + d

// 1) a*c & b*d
// 2) rest = (a+b) * (c+d) - ac - bd -> #
// 3) num1 * num2 = ac * 10**(x+y)/2 + rest * 10**(x+y)/4 + bd

#include <iostream>
#include <math.h>


class KaratsubaMultiplication
{
    private:
    int num1, a, b, x;
    int num2, c, d, y;
    int ac, bd, rest;

    int distribution(int num)
    {
        if (num % 2 == 0)
        {
            return num % 2;
        }

        else
        {
            return (num+1) % 2;
        }
    }

    int value_assign(int x, int y)
    {
        int power_num1 = pow(10, distribution(x));
        
        a = num1 / power_num1;
        b = num1 % power_num1;

        int power_num2 = pow(10, distribution(y));

        c = num2 / power_num2;
        d = num2 % power_num2;

        return a,b,c,d;
    }

    int product()
    {
        ac = a*c;
        bd = b*d;
        rest = (a+b)*(c+d) - a*c - b*d; 
        return ac, bd, rest;
    }

    int result()
    {
        int m = distribution(x+y);
        int n = distribution((x+y)/2);

        return ac*pow(10,m) + rest*pow(10,n) + bd;
    }

    public:

    void input(int num_1, int i ,int num_2, int j)
    {
        num1 = num_1;
        x = i;
        num2 = num_2;
        y = j;

        value_assign(x, y);
        product();
    }

    void print()
    {
        std::cout<<result();
    }
};


int main()
{
    KaratsubaMultiplication k;
    k.input(1223,4,23413,5);
    k.print();

    return 0;
}
