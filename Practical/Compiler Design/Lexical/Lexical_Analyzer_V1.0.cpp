#include<iostream>
#include<regex>
#include<vector>
#include<unordered_set>

#include<fstream>

using namespace std;

class Lexical
{
    int counter = 0;
    vector<char> input_arr;
    vector<string> vec;

    unordered_set<string> datatypes = {"int","float","long","string"};
    unordered_set<string> keywords = {"main","return","printf","cin","cout","for","while","do"};
    unordered_set<string> whitespaces = {" "};
    unordered_set<string> separators = {";"};
    unordered_set<string> identifiers = {"_","a","b","i","x","y","z"};
    unordered_set<string> operators = {"+","-","%","/","="};
    unordered_set<string> brackets = {"{","(",")","}"};
    unordered_set<string> numbers = {"0","1","2","3","4","5","6","7","8","9"};


    public:

    // Helpers

    string remove_extra(string input)
    {
        string result = "";        

        for(int i=0; i<input.length(); i++)
        {
            result+=input[i];

            if(input[i] == '{' or input[i] == ';')
            {   
                i++; //Going to next element
                
                //While element is whitespace continue forward
                while(input[i] == ' ')
                {
                    i++;
                }

                //Reducing to previous index otherwise loop will skip this one
                i--;
            }                  
        }

        input = result;

        return input;
    }

    bool is_valid(string result)
    {
        if(datatypes.find(result) != datatypes.end())
        {
            return true;
        }

        if(keywords.find(result) != keywords.end())
        {
            return true;
        }

        if(separators.find(result) != keywords.end())
        {
            return true;
        }        

        if(operators.find(result) != keywords.end())
        {
            return true;
        }

        if(brackets.find(result) != keywords.end())
        {
            return true;
        }   

        if(numbers.find(result) != keywords.end())
        {
            return true;
        }           

        return false;
    }

    // Parse
    void parse(string input)
    {
        input = remove_extra(input);

        int length = input.size();

        int i=0;

        while(i<length)
        {
            string result="";
            //result+=input[i];
            int j=i;
            while(j<length)
            {   
                result+=input[j];
                string temp = result;    
                string first = "";
                first+= temp[0];            
                int k=j;
                while (k<length)
                {                    
                    if(identifiers.find(first) != identifiers.end())
                    {
                        string last = "";
                        last+=result[result.size()-1];
                        if(operators.find(last) != operators.end() or separators.find(last) != separators.end())
                        {    
                            //cout<<last<<" Works!\n"
                            counter+=1;
                            cout<<counter<<". "<<result<<endl;
                            i=j-2;
                            break;
                            break;                            
                        }
                    }

                    if(is_valid(result))
                    {                        
                        counter+=1;
                        cout<<counter<<". "<<result<<endl;
                        i=j;
                        break;
                        break;
                    }
                    k+=1;
                }
                j+=1;                                
            }
            i+=1;
        }

        cout<<"Counter: "<<counter<<endl;
    }    

    bool valid_var(string result)
    {
        string first = "";
        first+=result[0];
        string second = "";
        second+=result[1];

        if(identifiers.find(first) != identifiers.end())
        {
            if(separators.find(second) != separators.end() or operators.find(second)!= operators.end())
            {
                return true;
            }
        }
        return false;
    }

 // Print
    void print_input()
    {
        for(auto elm : input_arr)
        {
            cout<<"Element: "<<elm<<endl;
        }
        cout<<endl<<"Size: "<<input_arr.size();
    }

    void print_vec()
    {
        for(auto elm : vec)
        {
            cout<<"Element: "<<elm<<endl;
        }
        cout<<endl<<"Size: "<<vec.size();
    }

};

int main()
{
    string text="";
    string code="";

    ifstream readfile("code.txt");

    while(getline(readfile, text))
    {
        code+=text;
    }

    readfile.close();

    //cout<<"Code: "<<code<<endl;

    Lexical l;

    l.parse(code);  

    //cout<<boolalpha<<l.valid_var("a;");

    return 0;
}