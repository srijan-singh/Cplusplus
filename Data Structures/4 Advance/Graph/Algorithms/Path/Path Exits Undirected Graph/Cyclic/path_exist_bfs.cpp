#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>

using std::unordered_map;   // Unorder Map use's Hash Table
using std::unordered_set;   // Unorder Set use's Hash Table
using std::vector;          // Dynamic Array
using std::queue;

using std::string;
using std::cout;
using std::boolalpha;

typedef unordered_map<string, vector<string> > Graph; 
typedef vector< vector<string> > Edge;
typedef unordered_set<string> Set;

void print(Graph graph);

Graph get_graph(Edge edges);

bool path_exist_bfs(Graph graph, string source, string destination, Set visited)
{
    queue<string> queue;
    queue.push(source);

    while(!queue.empty())
    {
        string current_node = queue.front();
        queue.pop();
        
        visited.insert(current_node);

        for(auto neighbour: graph[current_node])
        {
            if(neighbour == destination)
            {
                return true;
            }
            if (visited.find(neighbour) == visited.end())
            {
                queue.push(neighbour);
            }
        }
    }
    return false;
}

bool undirected_path_exist(Edge edges, string source, string destination)
{
    Set visited;
    Graph graph = get_graph(edges);
    print(graph);

    cout<<"Source: "<<source<<" Destination : "<<destination<<"\n";

    return path_exist_bfs(graph, source, destination, visited);
}


int main()
{   
    Edge edges = {
        {"i", "j"},
        {"k", "i"},
        {"m", "k"},
        {"k", "l"},
        {"o", "n"}
    };

    string source = "n";
    string destination = "o";

    cout<<boolalpha<<undirected_path_exist(edges, source, destination);

    return 0;
}

Graph get_graph(Edge edges)
{
    Graph graph;
    for(auto edge : edges)
    {
        string a = edge[0], b = edge[1];

        if(graph.find(a) == graph.end())
        {
            graph[a];
        }

        if(graph.find(b) == graph.end())
        {
            graph[b];
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}

void print(Graph graph)
{
    for(auto node : graph)
    {
        cout<<"Node: "<<node.first<<" Neighbour: ";
        
        for(auto neighbour: node.second)
        {
            cout<<neighbour<<" ";
        }
        cout<<"\n";
    }
}



