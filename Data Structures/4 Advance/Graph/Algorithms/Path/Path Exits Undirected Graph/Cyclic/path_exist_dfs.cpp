#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>


using std::unordered_map; // Unordered Map use hash table; Dictionary equivalent in python
using std::unordered_set; // Unordered Set use hash table; Set equivalent in python
using std::vector;        // Dynamica Array; List equivalent in python 

using std::string;
using std::cout;          
using std::boolalpha;     // To print true or false


typedef unordered_map<string, vector<string>> Graph;
typedef vector< vector<string> > Edge;
typedef unordered_set<string> Set;


void print(Graph graph); // To Print Graph

Graph graph_generator (Edge edges); //Generate Graph

bool has_path(Graph graph, string source, string destination, Set visited)
{
    if (source == destination) return true;

    if (visited.find(source) != visited.end()) // If source is present
    {
        return false;
    }

    visited.insert(source);

    for(auto neighbour : graph[source])
    {
        if (has_path(graph, neighbour, destination, visited))
        {
            return true;
        }
    }

    return false;
}

bool undirected_path(Edge edges, string source, string destination)
{
    Set visited;
    Graph graph = graph_generator(edges);
    print(graph);
    cout<<"Source: "<<source<<" Destination: "<<destination<<"\n";
    return has_path(graph, source, destination, visited);
}

int main()
{
    Edge edges = {
        {"i","j"},
        {"k","i"},
        {"m","k"},
        {"k","l"},
        {"o","n"}
    };

    string source = "l";
    string destination = "i";

    cout<<boolalpha<<undirected_path(edges, source, destination);

    return 0;
}

Graph graph_generator (Edge edges) 
{
    Graph graph;

    for(auto edge : edges)
    {
        string first = edge[0], second = edge[1];

        if(graph.find(first) == graph.end())
        {
            graph[first];
        }

        if(graph.find(second) == graph.end())
        {
            graph[second];
        }

        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    return graph;
}

void print(Graph graph)
{
    for(auto node : graph)
    {
        cout<<"Node: "<<node.first<<" Edges: ";
        
        for(auto value : node.second)
        {
            cout<<value<<" ";
        }
        cout<<"\n";
    }

}
