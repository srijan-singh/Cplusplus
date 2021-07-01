#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::cin;
using std::cout;

class UserDetails
{
    string firstName;
    string lastName;
    string country;
    int age;
    int pincode;
    int mobile;

    public:

    void get_data()
    {
        cout<<"\n\tForm\n";

        cout<<"\nFirst Name: ";
        cin>>firstName;
        cout<<"\nLast Name: ";
        cin>>lastName;

        cout<<"\nAge: ";
        cin>>age;

        cout<<"\nCountry: ";
        cin>>country;
        cout<<"\nPin Code: ";
        cin>>pincode;

        cout<<"\nMobile: ";
        cin>>mobile;

        return;
    }

    void show_data()
    {
        cout<<"\n\tUser Details\n";

        cout<<"\nFirst Name: \t";
        cout<<firstName;
        cout<<"\nLast Name:  \t";
        cout<<lastName;

        cout<<"\nAge:        \t";
        cout<<age;

        cout<<"\nCountry:    \t";
        cout<<country;
        cout<<"\nPin Code:   \t";
        cout<<pincode;

        cout<<"\nMobile:     \t";
        cout<<mobile;
        
        return;
    }

    void update_data()
    {
        std::cout<<"\nTODO";
    }

};

class Registration
{
    string username;
    string password;

    public:

    map<string, string> database;

    Registration()
    {
        // Default User
        database["abc"] = "123";
    }

    void sign_up()
    {
        std::cout<<"\nWe welcome you to our organization!\n";
        std::cout<<"\tRegistration Form\n";

        cout<<"\nUsername:\t";
        cin>>username;
        cout<<"\nPassword:\t";
        cin>>password;

        database.insert({username, password});

        std::cout<<"\nSuceesfully Registered!\n";
    }

};

class Login : public Registration
{
    string input_username;
    string input_password;

    public:

    bool sign_in()
    {
        cout<<"\n\tSign In Page\n";

        cout<<"\nUsername:\t";
        cin>>input_username;
        cout<<"\nPassword:\t";
        cin>>input_password;

        for(auto key = database.begin(); key != database.end(); key++)
        {
            if (input_username == key->first)
            {
                if (input_password == key->second)
                {  
                    std::cout<<"\nSuccess: Logged in!\n";  
                    
                    return true;                
                }
                else
                {
                    std::cout<<"\nError: Wrong Password!\n";
                }
            }           
        }
        std::cout<<"\nError: Username Not Found\n";
        
        return false;
    }   
};

class Features
{
    public:

    void user_data()
    {       
            UserDetails data;
            int input;

            do
            {
                cout<<"\nUse 1: Edit Profile\n";
                cout<<"\nUse 2: See Profile\n";
                cout<<"\nUse 0: To Log Out\n";
                               
                cin>>input;

                switch (input)
                {
                
                case 0:
                    std::cout<<"Bye!";
                    break;
                
                case 1:
                    data.get_data();
                    break;
                
                case 2:
                    data.show_data();
                    break;
                
                default:
                    cout<<"\nError: Invalid Input";
                    break;
                }
            }while (input != 0);
        
        return;
    }    
};

int main()
{
    Login server;
    Features feat;

    int input;
    do
    {       
        cout<<"\nUse 1: Sign Up\n";
        cout<<"\nUse 2: Sign In\n";
        cout<<"\nUse 0: To Exit\n";
        
        cin>>input;

        switch (input)
        {
        
        case 0:
            std::cout<<"Bye!";
            break;
        
        case 1:
            server.sign_up();
            break;
        
        case 2:
            if (server.sign_in() == true)
            {
                feat.user_data();
            }
            break;
        

        default:
            cout<<"\nError: Invalid Input";
            break;
        }
    }
    while (input != 0);

    return 0;
}