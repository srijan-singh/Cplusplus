#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>

using std::unordered_map;
using std::random_shuffle;
using std::string;
using std::cin;
using std::cout;

// Global Database
unordered_map <char, char> code_base;
unordered_map <char, char> reverse_code_base;
char codewa[26];

void print_map();

void code_setter()
{
    int i=65;
    int x=0;

    for(int j=65; j<i+26; j++)
    {
        codewa[x++] = j;
    }

    random_shuffle(codewa, codewa+26);

    for(auto element : codewa)
    {
        code_base[i] = char(element);
        reverse_code_base[char(element)] = i;
        i++;
    }
}

string cypher(string input)
{
    int length = input.size();
    char result[length];
    int i=0;

    for(auto elm:input)
    {
        result[i] = char(elm);
        i++;
    }

    for(int i=0; i<length; i++)
    {
        result[i] = code_base[result[i]];
        
    }
        
    return result;
}

string decrypt(string input)
{
    int length = input.size();
    char result[length];
    int i=0;

    for(auto elm:input)
    {
        result[i] = char(elm);
        i++;
    }

    for(int i=0; i<length; i++)
    {
        result[i] = reverse_code_base[result[i]];
    }
        
    return result;
}

int main()
{
    string input;
    cout<<"Please Input the String: ";
    cin>>input;
    cout<<cypher(input);
    
    code_setter();

    string encryption = cypher(input);

    cout<<"Encryption: "<<encryption<<"\n";

    print_map();

    //cout<<"Decryption: "<<decrypt(encryption)<<"\n";

    return 0;
}

void print_map()
{
    for(auto elem : code_base)
    {
        cout<<elem.first<<" "<<elem.second<<"\n";
    }
}