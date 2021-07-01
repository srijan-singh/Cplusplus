/*
    Default Constructor
    Static Member
    Static Function
*/

#include <iostream>
#include <string>

using namespace std;

class Practical
{
    public:

    static int age;
    string name;

    Practical()
    {
        name = "Default Name";
    }

    void get_data()
    {
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
    }

    void show_data()
    {
        cout<<"Name: "<<name;
        cout<<"\nAge : "<<age;
        cout<<endl;
    }

    static void show_age()
    {
        cout<<"Age : "<<age;
        cout<<endl;
    }
};

void input(int length, Practical p[]);
void print(int length, Practical p[]);

int Practical::age = 18;

int main()
{
    int length = 2;

    Practical p[length];

    print(length, p);
    input(length, p);
    print(length, p);

    return 0;
}

void input(int length, Practical p[])
{
    for(int i = 0; i<length; i++)
    {
        p[i].get_data();
    }
    cout<<endl;
}

void print(int length, Practical p[])
{
    for(int i = 0; i<length; i++)
    {
        p[i].show_data();
    }
    
    cout<<"Static Function"<<endl;
    
    for(int i = 0; i<length; i++)
    {
        p[i].show_age();
    }
    
    cout<<endl;
}