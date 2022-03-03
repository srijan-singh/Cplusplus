#include<iostream>
#include<vector>

using namespace std;

int max_index(vector<int> arr, int index=0)
{
    int max = index;
    int length = arr.size();

    for(int i=max+1; i<length; i++)
    {
        if(arr[max] < arr[i])
        {
            max = i;
        }
    }

    if(max == index)
    {
        return -1;
    }

    return max;
}

int best_time_to_sell(vector<int> arr)
{
    int max = 0;

    int length = arr.size();

    vector<int> result(length, 0);  

    for(int i=0; i<length; i++)
    {
        int max = max_index(arr, i);

        if(max > -1)
        {
            result[i] = arr[max] - arr[i];
        }
    }
     
    max = max_index(result);

    return result[max];
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};

    cout<<best_time_to_sell(arr);

    return 0;
}