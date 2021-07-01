#include<iostream>
#include<string>

using namespace std;

string subjects[5] = {"SUB1", "SUB2", "SUB3", "SUB4", "SUB5"};

int get_subjects()
{
    cout<<"\tEnter Subjects\n";
    for(int i=0; i<4; i++)
    {
        cout<<"Subject "<<i+1<<endl;
        cin>>subjects[i];
    }
    return 0;
}

class eleven
{
    string name;
    string optional;

    int subject_theory_marks[5];
    int subject_practical_marks[5];

    int optional_theory_max, optional_practical_max;

    public:

    int get_name()
    {
        cout<<"Name: ";
        cin>>name; 
        return 0;
    }

    int submission( int(func) )
    {
        char submit;

        cout<<"\nWant to submit (Y/N)?";
        
        cin>>submit;

        if (submit == 'N' or submit == 'n')
        {            
            return func;
        }
        return 1;
    }

    int subject1()
    {
        cout<<subjects[0]<<endl;
        cout<<"\n\tMarks in 80: ";
        cin>>subject_theory_marks[0];
        cout<<"\n\tMarks in 20: ";
        cin>>subject_practical_marks[0];
        return 0;
    }

    int subject2()
    {
        cout<<subjects[1]<<endl;
        cout<<"\n\tMarks in 80: ";
        cin>>subject_theory_marks[1];
        cout<<"\n\tMarks in 20: ";
        cin>>subject_practical_marks[1];
        return 0;
    }

    int subject3()
    {
        cout<<subjects[2]<<endl;
        cout<<"\n\tMarks in 80: ";
        cin>>subject_theory_marks[2];
        cout<<"\n\tMarks in 20: ";
        cin>>subject_practical_marks[2];
        return 0;
    }

    int subject4()
    {
        cout<<subjects[3]<<endl;
        cout<<"\n\tMarks in 80: ";
        cin>>subject_theory_marks[3];
        cout<<"\n\tMarks in 20: ";
        cin>>subject_practical_marks[3];
        return 0;
    }
    
    int subject5()
    {
        cout<<"Optional"<<endl;
        cin>>optional;
        cout<<"Max Theory Marks: ";
        cin>>optional_theory_max;
        cout<<"Max Practical Marks: ";
        cin>>optional_practical_max;

        cout<<"\n\tMarks in "<<optional_theory_max<<": ";
        cin>>subject_theory_marks[4];
        cout<<"\n\tMarks in "<<optional_practical_max<<": ";
        cin>>subject_practical_marks[4];
        return 0;
    }

    int get_input()
    {
        get_name();
        submission(subject1());
        submission(subject2());
        submission(subject3());
        submission(subject4());
        submission(subject5());        
        return 0;
    }

    void update_data()
    {
        int input;

        get_output();
        
        do
        {
            cout<<"What you want to update?: ";
            cout<<"Use 0: TO EXIT\n";
            cout<<"Use 1: FOR NAME\n";
            cout<<"Use 2: FOR "<<subjects[0]<<endl;
            cout<<"Use 3: FOR "<<subjects[1]<<endl;
            cout<<"Use 4: FOR "<<subjects[2]<<endl;
            cout<<"Use 5: FOR "<<subjects[3]<<endl;
            cout<<"Use 6: FOR "<<subjects[4]<<endl;
            cout<<"Use 7: TO UPDATE SUBJECT NAME"<<endl;
            cin>>input;

            switch(input)
            {
                case 0:
                    break;

                case 1:
                    get_name();
                    break;

                case 2:
                    subject1();
                    break;

                case 3:
                    subject2();
                    break;

                case 4:
                    subject3();
                    break;

                case 5:
                    subject4();
                    break;

                case 6:
                    subject5();
                    break;

                case 7:
                    get_subjects();
                    break;

                default:
                    cout<<"ERROR: INVALID INPUT\n";
                    break;
            }

        }while(input != 0);
    }

    void get_output()
    {
        cout<<"\n\tRESULT\n";

        cout<<"Name: "<<name<<endl<<endl;
        
        for(int i=0; i<4; i++)
        {
            cout<<subjects[i]<<endl;
            cout<<"Theory 80: "<<subject_theory_marks[i]<<endl;
            cout<<"Practical 20: "<<subject_practical_marks[i]<<endl;
            cout<<endl;
        }

        cout<<optional<<endl;
        cout<<"Theory "<<optional_theory_max<<": "<<subject_theory_marks[4]<<endl;
        cout<<"Practical "<<optional_practical_max<<": "<<subject_practical_marks[4]<<endl;
        
        cout<<"\n\n";
    }

};

int main()
{
    int num_student = 11;

    class eleven ips[num_student];

    int index = 0;
    int input;

    do
    {
        cout<<"USE 0: TO NAME SUBJECTS"<<endl;
        cout<<"USE 1: TO ENTER MARKS"<<endl;
        cout<<"USE 2: TO GET RESULT"<<endl;
        cout<<"USE 3: TO UPDATE DATA"<<endl;
        cout<<"USE 99: TO EXIT"<<endl;

        cin>>input;

        switch (input)
        {
        
        case 0:
            get_subjects();
            break;           

        case 1:
            ips[index].get_input();
            index++;
            break;

        case 2:
            for(int i=0; i<num_student; i++)
            {
                ips[i].get_output();
            }
            break;

        case 3:
            int roll_no;
            cout<<"Enter Roll No: ";
            cin>>roll_no;
            roll_no-=1;
            ips[roll_no].update_data();
            break;

        case 99:
            break;
        
        default:
            cout<<"ERROR: INVALID INPUT\n";
            break;
        }
    }while(input!=99);

    return 0;
}