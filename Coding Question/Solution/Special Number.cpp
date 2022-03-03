/*
    Link To Question : https://www.codingninjas.com/codestudio/problems/special-numbers_1214935?topList=top-fintech-software-engineer-interview-questions
*/
#include<iostream>

using namespace std;

int special_num(int num)
{
    num--;

    int arr[6] = {0,1,2,3,4,5};

    int q = num/6;
    int r = num%6;

    /*
    cout<<"\nq: "<<q;
    cout<<"\nr: "<<r;
    cout<<'\n';
    */

    int result = arr[q]*10;
    result+=arr[r];

    return result;
}

int main()
{
    cout<<special_num(18);
    return 0;
}