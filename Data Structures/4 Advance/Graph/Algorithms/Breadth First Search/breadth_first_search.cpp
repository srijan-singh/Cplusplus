//BFS

#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using std::unordered_map;
using std::vector;
using std::queue;
using std::string;
using std::cout;
using std::endl;

void breadth_first_search(unordered_map <string, vector<string> > graph, string source)
{
    queue<string> queue;
    queue.push(source);

    while (!queue.empty())
    {
        string current = queue.front();
        queue.pop();
        cout<<current<<endl;

        for(auto neighbour : graph[current])
        {
            queue.push(neighbour);
        }
    }
    
}

int main()
{
    unordered_map <string, vector<string> > graph;

    graph["a"].push_back("b");
    graph["a"].push_back("c");

    graph["b"].push_back("d");

    graph["c"].push_back("e");

    graph["d"].push_back("f");

    graph["e"];

    graph["f"];

    string source = "a";

    breadth_first_search(graph, source);

    return 0;
}

