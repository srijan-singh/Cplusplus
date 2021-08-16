#include<iostream>
#include<unordered_set>

using std::unordered_set;
using std::cout;

typedef unordered_set<int> Set;

void jadoo(Set visited)
{
    
}

int set_size(Set visited, int count=0)
{
    if(visited.size() > 4)
    {
        return visited.size();
    }

    visited.insert(count);

    return set_size(visited, ++count);
}


int main()
{
    Set visited;
    cout<<set_size(visited);
    return 0;
}