#include <iostream>

using std::cout;

class Fibonaci {

  int * memo;
    
public:
    
    int getFibNumber(int n) {

      memo = new int[n+1];
      return fib_memo(n, memo);

    }

    int fib_memo(int n, int memo[])
    {
      if (n==0 or n==1)
      {
        return n;
      }

      for(int i=0; i<n; i++)
      {
        if(n==memo[i])
        {
          return memo[n];
        }
      }

      memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);

      return memo[n];
    }
};


int main()
{
  Fibonaci s;

  cout<<s.getFibNumber(8)<<"\n";
  cout<<s.getFibNumber(9)<<"\n";
  cout<<s.getFibNumber(10)<<"\n";

  return 0;
}
