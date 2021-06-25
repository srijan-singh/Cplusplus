#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::cin;
using std::cout;

class Registration
{
    string username;
    string password;

    public:

    map<string, string> database;

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

class RegisteredUser : public Login
{
    public:

    void psudo_function()
    {

        if (sign_in() == true)
        {
            std::cout<<"\nWelcome back you have 7 new noifications!\n";
        }
        else
        {
            std::cout<<"\nUse 1: To Register: ";
            int value;
            std::cin>>value;
            
            if (value == 1)
            {
                sign_up();
                psudo_function();
            }
        }
    }
    
};

int main()
{
    RegisteredUser server;
    server.psudo_function();
    return 0;
}