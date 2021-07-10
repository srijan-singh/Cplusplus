/*
    Creating Objects with Array 
*/
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Box
{
    float dataset[3];
    string labels[3] = {"Length", "Breadth", "Height"};

    public:

    friend void input(Box &, int);
    
    friend void print(Box &, int);
};

class Student
{
    
    string name;
    int mobile;
    int pincode;

    string labels[3] = {"Name", "Mobile", "Pin Code"};

    public:

    friend void input(Student &, int);
    friend void print(Student &, int);
};

void input(Box &b, int box_num)
{
    cout<<"Enter Data for Box "<<box_num<<endl;
    for(int i=0; i<3; i++)
    {   
        cout<<b.labels[i]<<" : ";
        cin>>b.dataset[i];
    }
}

void input(Student &s, int student_num)
{
    cout<<"Enter Data of Student "<<student_num<<endl;
    cout<<s.labels[0]<<" : ";
    cin>>s.name;
    cout<<s.labels[1]<<" : ";
    cin>>s.mobile;
    cout<<s.labels[2]<<" : ";
    cin>>s.pincode;
}


int main()
{
    cout<<"\n\tBox Dataset\n";

    int num_box;
    cout<<"Number of Boxes: ";
    cin>>num_box;

    Box b[num_box];

    for(int i=0; i<num_box; i++)
    {
        input(b[i], i+1);
    }

    for(int i=0; i<num_box; i++)
    {
        print(b[i], i+1);
    }

    cout<<"\n\tStudent Dataset\n";

    int num_student;
    cout<<"Number of Students: ";
    cin>>num_student;

    Student s[num_student];

    for(int i=0; i<num_student; i++)
    {
        input(s[i], i+1);
    }

    for(int i=0; i<num_student; i++)
    {
        print(s[i], i+1);
    }

    return 0;
}

void print(Box &b, int box_num)
{
    cout<<"\n\tBox Dimension\n";
    cout<<"Provided Data for Box "<<box_num<<endl;
    
    for(int i=0; i<3; i++)
    {   
        cout<<b.labels[i]<<" : "<<b.dataset[i]<<endl;
    }
}   

void print(Student &s, int student_num)
{
    cout<<"\n\tStudent Data\n";
    cout<<"Provided Data for Student "<<student_num<<endl;
    cout<<s.labels[0]<<" : "<<s.name<<endl;
    cout<<s.labels[1]<<" : "<<s.mobile<<endl;
    cout<<s.labels[2]<<" : "<<s.pincode<<endl;
}   