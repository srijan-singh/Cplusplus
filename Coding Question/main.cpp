/*
    Link To Question : https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?topList=top-fintech-software-engineer-interview-questions
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int stairs(int n, unordered_map<int, int> memo = {})
{
    if(n==1 or n==2)
    {
        return n;
    }

    if(memo.find(n) != memo.end())
    {
        return memo[n];
    }

    memo[n] = stairs(n-1) + stairs(n-2);

    return memo[n];
}

int main()
{
    int test_case;
    cin>>test_case;

    int result[test_case];

    for(int i=0; i<test_case; i++)
    {
        int target;
        cin>>target;
        result[i]=stairs(target);
    }

    cout<<"\nAnswer\n";
    for(int i=0; i<test_case; i++)
    {
        cout<<result[i]<<'\n';
    }

    return 0;
}