#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using std::vector;
using std::unordered_map;
using std::cout;

int activity_selection(vector<int> start, vector<int> end)
{
  // Your code here
  int count = 1;
  int length = end.size();
  
  unordered_map <int, int> graph;

  for(int i=0; i<length; i++)
  {
      graph[end[i]] = start[i];
  }

  sort(end.begin(), end.end());

  int i=0;

  cout<<"Start "<<graph[end[i]]<<" Finish "<<end[i]<<"\n";

  for(int j=1; j<length; j++)
  {
    if(graph[end[j]] >= end[i])
    {
      count++;
      i=j;
      cout<<"Start "<<graph[end[j]]<<" Finish "<<end[j]<<"\n";
    }
  }

  return count;

}

int main()
{
  vector <int> start = {
    5,1,3,0,5,8
  };
  vector <int> end = {
    9,2,4,6,7,9
  };  
  std::cout<<activity_selection(start,end);
}