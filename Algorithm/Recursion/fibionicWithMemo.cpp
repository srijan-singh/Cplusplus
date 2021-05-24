//Memoization
#include <iostream>

//Intializaton memo to store the repeating value
int *memo;

int fibiaonic(int value, int *memo)
{
    // Base Value/Termination Condition
    if(value<=1)
    {
        return 1;
    }
    //If Value is in Memo
    if(memo[value] != -1)
    {
        return memo[value];
    }
    //If Value isn't in Memo
    memo[value] = fibiaonic(value-1, memo) + fibiaonic(value-2, memo);

    return memo[value];
}

int main()
{
    int n;
    std::cin>>n;
    // Dynamic Array
    memo = (int*)malloc(sizeof(int));
    //Initialization all Value as -1
    for(int i=0; i<n; i++)
    {
        memo[i] = -1;
    }
    std::cout<<fibiaonic(n,memo);
}