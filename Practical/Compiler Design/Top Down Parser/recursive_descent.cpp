#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<char, vector<char>> Grammer;

bool match(char element)
{
  for(auto var : Grammer)
  {
    for(auto terminal : var.second)
    {
      if(terminal == element)
      {
        return true;
      }
    }
  }
  return false;
}

void RD(string input, int index=0)
{
  if(index < input.size())
  {
    if(match(input[index])==false)
    {
      cout<<"Not Possible";
      return;
    }
    
    RD(input, ++index);
  }
  else
  {
    cout<<"Successful!";
    return;
  }
}

int main()
{
  Grammer['S'] = {'A', 'B'};
  Grammer['A'] = {'a','b'};
  Grammer['B'] = {'c','d'};

  string input = "abcd";

  input = "abcd";

  RD(input);

  return 0;
}