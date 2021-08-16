#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using std::unordered_map;
using std::vector;
using std::queue;
using std:: string;
using std::cout;
using std::boolalpha;

bool has_path(unordered_map <string, vector<string> > graph, string source, string destination)
{
    if (source == destination)
    {
        return true;
    }

    queue<string> queue;

    queue.push(source);

    while (!queue.empty())
    {
        string current_node = queue.front();
        queue.pop();
        
        for(auto neighbour : graph[current_node])
        {
            if (neighbour == destination)
            {
                return true;
            }
            queue.push(neighbour);
        }
    }

    return false;
}

int main()
{
    unordered_map <string, vector<string> > graph;

    graph["f"] = {"g", "i"};

    graph["g"] = {"h"};

    graph["h"];

    graph["i"] = {"g", "k"};

    graph["j"] = {"i"};

    graph["k"];

    string source = "f";

    string destination = "j";

    cout<<boolalpha<<has_path(graph, source, destination);

    return 0;
}