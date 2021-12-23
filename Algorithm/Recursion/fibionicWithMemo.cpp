#include<iostream>
#include<unordered_map>

using std::unordered_map;
using std::cout;


unsigned long fib(long num, unordered_map <unsigned long, unsigned long> &Dict)
{
  if (Dict.find(num) != Dict.end())
  {
    return Dict[num];
  }

  if (num <= 2)
  {
    return 1;
  }

  Dict[num] = fib(num-1, Dict) + fib(num-2, Dict);

  return Dict[num];
}

int main()
{
  unsigned long n;
  cout<<"Enter the number: ";
  std::cin>>n;
  unordered_map <unsigned long, unsigned long> Dict;
  cout<<fib(n, Dict);
  return 0;
}
