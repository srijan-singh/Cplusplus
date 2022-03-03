#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>


using namespace std;

class First
{
    unordered_map<char, vector<char>> table;
    unordered_map<char, vector<char>> first_table;
    vector<char> variable;
    vector<char> terminal;

    public:

    void print_first()
    {
        for(auto elm : variable)
        {
            cout<<"First of "<<elm<<" : "<<get_first(elm)<<endl;
        }
    }

    char get_first(char elm)
    {
        char first = table[elm][0];
        //cout<<first<<endl;
        
        if(islower(first))
        {
            return first;
        }

        else
        {
            return get_first(first);
        }
    
    }

    void get_input(string input) 
    {
        int length = input.size();

        char lhs = input[0];
        string rhs = input.substr(2,length-1);

        /*
        cout<<"LHS = "<<lhs<<endl;
        cout<<"RHS = "<<rhs<<endl;
        */

        for(int i=0; i<rhs.size(); i++)
        {
            table[lhs].push_back(rhs[i]);
        }

        for(int i=0; i<length; i++)
        {
            if(isupper(input[i]))
            {
                variable.push_back(input[i]);
            }
            else
            {
                terminal.push_back(input[i]);
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
    
    void print_variable()
    {
        cout<<"Variable: ";
        for(auto elm:variable)
        {
            cout<<elm<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    First f;
    f.get_input("A=Bc");
    f.get_input("B=dC");
    //f.get_input("C=A");
    f.print_table();
    f.print_variable();
    f.print_first();
    return 0;
}