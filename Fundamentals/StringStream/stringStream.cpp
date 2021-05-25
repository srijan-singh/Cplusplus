#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::stringstream;
using std::getline;
using std::cout;
using std::endl;

int main()
{
    vector<string> words;
    stringstream ss("Some Random Words");
    string word;
    while (getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    cout <<"Printed Using Usual Syntax:\n";
    for(int i=0; i<words.size(); i++)
    {
        cout<<words[i]<<endl;
    }

    cout <<"Printed Using New Syntax:\n";
    for(auto x: words) cout << x <<endl;
    

    return 0;

}