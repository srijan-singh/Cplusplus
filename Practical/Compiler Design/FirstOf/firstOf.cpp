#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class First
{
    unordered_map<char, vector<char>> table;
    vector<char> variable;
    vector<char> terminal;
    
    // To check whether element is present
    bool present(char input)
    {
        if(isupper(input))
        {
            for(auto elm : variable)
            {   
                if(input == elm)
                {
                    return true;
                }
            }
            return false;
        }

        else
        {
            for(auto elm : terminal)
            {   
                if(input == elm)
                {
                    return true;
                }
            }
            return false;
        }
    }

    // To get the first of a variable in LHS
    char get_first(char elm)
    {
        char first = table[elm][0];
        //cout<<first<<endl;
        
        if(isupper(first))
        {
            return get_first(first);
        }

        else
        {
            return first;   
        }
    
    }

    public:

    void print_first()
    {
        for(auto elm : variable)
        {
            cout<<"First of "<<elm<<" : "<<get_first(elm)<<endl;
        }
    }

    void get_input(string input) 
    {
        int length = input.size();

        char lhs = input[0];
        string rhs = input.substr(2,length-1);

        for(int i=0; i<rhs.size(); i++)
        {
            table[lhs].push_back(rhs[i]);
        }

        for(int i=0; i<length; i++)
        {
            if(isupper(input[i]))
            {
                if(!present(input[i]))
                {
                    variable.push_back(input[i]);
                }
            }
            if(islower(input[i]))
            {
                if(!present(input[i]))
                {
                    terminal.push_back(input[i]);
                }
            }
        }
    }

    void print_table()
    {
        for(auto elm : table)
        {
            cout<<elm.first<<" = { ";
            for(auto el : elm.second)
            {
                cout<<el<<",";
            }
            cout<<" }\n";
        }
    }
    
    void print_data()
    {
        cout<<"Variable: ";
        for(auto elm:variable)
        {
            cout<<elm<<" ";
        }
        cout<<endl;

        cout<<"Terminal: ";
        for(auto elm:terminal)
        {
            cout<<elm<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    First f;

    // Provide input    
    f.get_input("A=Bc");
    f.get_input("B=dC");
    f.get_input("C=A");

    // To print variables and terminals
    f.print_data();

    // To print first
    f.print_first();
    return 0;
}