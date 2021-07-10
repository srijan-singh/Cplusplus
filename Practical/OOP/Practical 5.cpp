/*
    Function Overloading
    Friend Function
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class MeanValue
{
    float num1;
    float num2;

    void print()
    {
        cout<<"Mean Value is: "<<(num1+num2)/2;
    }

    public:

    MeanValue()
    {
        num1 = num2 = 0;
    }

    friend void inputValue(MeanValue &m);
};

void inputValue(MeanValue &m)
{
    std::cout<<"Enter a number: ";
    cin>>m.num1;

    cout<<"Enter another number: ";
    cin>>m.num2;

    m.print();

}

class Area
{
    int side;
    int length, breadth;
    float radius;
    float base, height;

    public:

    Area()
    {
        side = length = breadth = radius = base = height = 0; 
    }

    friend void input(Area &a);

    int area(int side)
    {
        return side * side;
    }

    int area(int length, int breadth)
    {
        return length * breadth;
    }

    float area(float radius)
    {
        return 22*radius*radius/7;
    }

    float area(float base, float height)
    {
        return base * height;
    }

    void print();
};

void Area::print()
{
    cout<<"Area of Square: "<<area(side)<<endl;
    cout<<"Area of Rectangle: "<<area(length, breadth)<<endl;
    cout<<"Area of Circle: "<<area(radius)<<endl;
    cout<<"Area of Triangle: "<<area(base, height)<<endl;
}

void input(Area &a)
    {        
        cout<<"Enter side of the square: ";
        cin>>a.side;
        
        
        cout<<"Enter length and breadth of the rectangle: ";
        cin>>a.length>>a.breadth;
        
        
        cout<<"Enter radius of the circle: ";
        cin>>a.radius;

        cout<<"Enter base and height of triangle: ";
        cin>>a.base>>a.height;
    }

int main()
{   
    cout<<"\n\tClass of Area\n";
    Area a;
    input(a);
    a.print();

    cout<<"\n\tClass of Mean Value\n";
    MeanValue m;
    inputValue(m);
    return 0;
}