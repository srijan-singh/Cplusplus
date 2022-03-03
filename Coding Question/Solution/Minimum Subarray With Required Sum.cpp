/*
    Link To Question : https://www.codingninjas.com/codestudio/problems/minimum-subarray-with-required-sum_696460?topList=top-fintech-software-engineer-interview-questions
*/

#include<iostream>

using namespace std;

void min_sub_arr(int *arr, int size, int target)
{
    for(int i=0; i<size-1; i++)
    {
        int sum = arr[i] + arr[i+1];

        if(sum > target)
        {
            cout<<"\nAnswer\n"<<arr[i]<<" "<<arr[i+1];
            return;
        }
    }
    
    cout<<"\nAnswer\n"<<0;
    return;
}

int main()
{
    int size;
    cin>>size;

    int arr[size];

    int target;
    cin>>target;

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    min_sub_arr(arr, size, target);

    return 0;
}