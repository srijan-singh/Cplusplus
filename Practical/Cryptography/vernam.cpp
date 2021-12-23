#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Vernam
{
  vector<int> key;
  vector<int> plain_text;
  vector<int> cypher_text;

  int conditioning(int input)
  {
    if(input>25)
    {
      return input-25;
    }
    return input;
  }

  public:

  void get_plain_text()
  {
    string input;
    cout<<"Enter plain text: ";
    cin>>input;

    for(int i=0; i<input.size(); i++)
    {
      // Converting int to binary
      plain_text.push_back(int(input[i]-65));    
    }
  }

  void get_key()
  {
    string input;
    cout<<"Enter key: ";
    cin>>input;

    for(int i=0; i<input.size(); i++)
    {
      // Converting int to binary
      key.push_back(int(input[i]-65));    
    }

    int index = 0;

    while(key.size() < plain_text.size())
    {
      key.push_back(key[index++]);
    }
  }

  void cypher()
  {
    for(int i=0; i<plain_text.size(); i++)
    {
      cypher_text.push_back(conditioning(plain_text[i] + key[i]));
    }
  }

  void print()
  {
    cout<<"Key: ";
    for(auto elm : key)
    {
      cout<<elm<<" ";
    }

    cout<<"\nPlain Text: ";
    for(auto elm: plain_text)
    {
      cout<<char(elm+65)<<" ";
    }

    cout<<"\nCypher Text: ";
    for(auto elm: cypher_text)
    {
      cout<<char(elm+65)<<" ";
    }
    cout<<"\n";
  }
};

int main()
{
  Vernam v;
  v.get_plain_text();
  v.get_key();
  v.cypher();
  v.print();
  return 0;
}