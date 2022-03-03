/* 
    Link To Question: https://www.codingninjas.com/codestudio/problems/first-k-maximum-elements_1214933?topList=top-fintech-software-engineer-interview-questions
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> get_index(int *arr, int size, vector<int> vec)
{
    vector<int> result;

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<vec.size(); j++)
        {
            if(arr[i] == vec[j])
            {
                result.push_back(i);
            }
        }
    }
    return result;
}

vector<int> maximum_elements(int *arr, int size, int target)
{
    vector<int> result;

    /*Sorting array without disturbing the original array*/

    // Creating a temp array
    int temp[size];
    
    // Copying Element
    for(int i=0; i<size; i++)
    {
        temp[i] = arr[i];
    }

    // Sorting
    sort(temp, temp+size);

    // Getting the max elements
    for(int i=size-1; i>=0; i--)
    {
        if(result.size() == target)
        {
            break;
        }

        if(temp[i] == temp[i-1])
        {
            continue;
        }
        else
        {
            result.push_back(temp[i]);
        }
    }

    // Getting Indexes
    result = get_index(arr, size, result);

    return result;
}

int main()
{
    int test_case;
    cin>>test_case;

    vector<vector<int>> result;

    for(int i=0; i<test_case; i++)
    {
        int size;
        cin>>size;

        int target;
        cin>>target;

        int arr[size];

        for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

        result.push_back(maximum_elements(arr, size, target));
    }

    cout<<"\nAnswer\n";
    for(auto arr: result)
    {
        for(auto elm: arr)
        {
            cout<<elm<<' ';
        }
        cout<<'\n';
    }

    return 0;
}