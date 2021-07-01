#include<iostream>
#include<string>

using namespace std;

class eleven
{
    string name;
    string subject_name[5] = {"English", "", "", "", ""};
    int english;
    int pol_sc;
    int history;
    int eco;
    int optional;

    public:

    int marks_in_80()
    {
        int marks;
        cin>>marks;
        int new_marks = marks/70;
        return marks*80;
    }

    void get_input()
    {
        cout<<"\n\tMarks in 70\n";
        cout<<"Name: ";
        cin>>name;
        
        cout<<"English: ";
        english = marks_in_80();
        
        cout<<"Political Science: ";
        pol_sc = marks_in_80();

        cout<<"History: ";
        history = marks_in_80();

        cout<<"Economics: ";
        eco = marks_in_80();

        cout<<"Optional: ";
        cin>>optional;

        cout<<"\n\tMarks in 20\n";

        int num; 
   
        cout<<"English: ";
        cin>>num;
        english +=num;
        
        cout<<"Political Science: ";
        cin>>num;
        pol_sc +=num;

        cout<<"History: ";
        cin>>num;
        history +=num;

        cout<<"Economics: ";
        cin>>num;
        eco +=num;

        cout<<"Optional: ";
        cin>>num;
        optional +=num;     

        cout<<"\n";

    }

    void get_output()
    {
        cout<<"\nName: ";
        cin>>name;
        
        cout<<"\nEnglish          : "<<english;
        
        cout<<"\nPolitical Science: "<<pol_sc; 

        cout<<"\nHistory          : "<<history;

        cout<<"\nEconomics        : "<<eco;

        cout<<"\nOptional         : "<<optional;   

        cout<<"\n\n";
    }

    void percentage()
    {
        float percentage = (english+pol_sc+history+eco+optional)/5;

        cout<<"\nName: "<<name<<"Percentage "<<percentage;       
        
        cout<<"\n";
    }
};


int main()
{
    int num_student = 11;

    class eleven ips[num_student];

    for(int i=0; i<num_student; i++)
    {
        ips[i].get_input();
    }

    cout<<"\n\tResult\n";
    for(int i=0; i<num_student; i++)
    {
        ips[i].get_output();
    }

    cout<<"\n\tPercentage\n";
    for(int i=0; i<num_student; i++)
    {
        ips[i].percentage();
    }

}