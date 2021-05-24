//Invoke all employee with a single command e->Work
#include <iostream>

using std::string;
using std::cin;
using std::cout;

class Promotion
{
    virtual void AskPromotion()=0;
};
class Employee:Promotion
{
    //private: is set by default so, don't need to write it
    string FirstName;
    string LastName;
    string Company;

    protected:
    int age;

    public:

    //Encapsulation
    void setName()
    {
        cout<<"\nFirst Name:\t";
        cin>>FirstName;        
        cout<<"Last Name:\t";
        cin>>LastName;
    }

    void setCompany()
    {
        cout<<"\nCompany: \t";
        cin>>Company;
    }

    void setAge()
    {
        cout<<"\nEmployee Age:\t";
        int user_age;
        cin>>user_age;

        if(user_age>18)
        {
            age=user_age;
        }
        else
        {
            cout<<"\nAge is set to 18 by default!\n";
            age = 18;
        }
    }

    string getName()
    {
        string Name = FirstName+" "+LastName;
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return age;
    }
    //Abstraction
    void AskPromotion()
    {
        cout<<"\n**Promotion Status**\n";
        if(age>30)
        {
            cout<<FirstName<<" you are promoted!";
        }
        else
        {
            cout<<FirstName<<" you are not promoted!";
        }
        cout<<"\n**Promotion Status**\n";
    }

    //Can be other derived function calling by pointers
    virtual void Print()
    {
        cout<<"\nDetails of Employee:\nEmployee Name:\t"<<FirstName<<" "<<LastName<<"\nCompany:\t"<<Company<<"\nEmployee Age:\t"<<age<<"\n";
    }
    virtual void Work()
    {
        cout<<getName()<<" do you respective work!";
    }    
};
//Inheritance
class Developer: public Employee
{
    string ProgrammingLanguage;
    public:
    
    void setPL()
    {
        cout<<"\nLanguage:\t";
        cin>>ProgrammingLanguage;
    }
    string getPL()
    {
        return ProgrammingLanguage;
    }
    //Polymorphism
    void Print()
    {                                            //Encapsulation can't directly acces first name (private member);Inheritance age is protected so it can be access by it's child class
       cout<<"\nDetails of Employee:\nEmployee Name:\t"<<getName()<<"\nCompany:\t"<<getCompany()<<"\nEmployee Age:\t"<<age<<"\nLanguage:\t"<<getPL()<<"\n";
    }
    void Work()
    {
        cout<<getName()<<" start coding!\n";
    }

};

class Teacher:public Employee
{
    string sub;

    public:

    void setSub()
    {
        cout<<"Subject: ";
        cin>>sub;
    }

    string getSub()
    {
        return sub;
    }
    void Work()
    {
        cout<<getName()<<" start teaching!\n";
    }
};
int main()
{
    Developer dev;
    Employee *e1=&dev;

    Teacher t;
    Employee *e2=&t;

    dev.setName();
    dev.setAge();
    dev.setCompany();
    dev.setPL();
    //Calling by pointers
    e1->Work();
    e2->Work();
}