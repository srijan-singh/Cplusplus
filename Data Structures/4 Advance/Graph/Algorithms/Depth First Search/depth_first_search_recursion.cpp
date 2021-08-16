#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;

void depth_first_search(unordered_map <string, vector <string> > graph, string source_node)
{
    cout<<source_node<<endl;
    
    for (auto neighbour : graph[source_node])
    {
        depth_first_search(graph, neighbour);
    }
}

int main()
{
    unordered_map <string, vector <string> > graph;

    graph["a"].push_back("b");
    graph["a"].push_back("c");

    graph["b"].push_back("d");

    graph["c"].push_back("e");

    graph["d"].push_back("f");

    graph["e"];

    graph["f"];

    string source = "a";

    depth_first_search(graph, source);

    return 0;
}