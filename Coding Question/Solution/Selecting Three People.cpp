/*
	Link to Question : https://www.codingninjas.com/codestudio/problems/selecting-three-people_1214971?topList=top-fintech-software-engineer-interview-questions
*/

#include<iostream>

using namespace std;

int order(int *arr, int size)
{
	int result = 0;

	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			for(int k=j+1; k<size; k++)
			{
				if(arr[i] < arr[j])
				{
					if(arr[j] < arr[k])
					{
						result+=1;
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	int test_case;
	cin>>test_case;

	int result[test_case];

	for(int i=0; i<test_case; i++)
	{
		int size;
		cin>>size;

		int arr[size];

		for(int i=0; i<size; i++)
		{
			cin>>arr[i];
		}

		result[i] = order(arr, size);
	}

	cout<<"Answer\n";
	for(int i=0; i<test_case; i++)
	{
		cout<<result[i]<<'\n';
	}

	return 0;
}