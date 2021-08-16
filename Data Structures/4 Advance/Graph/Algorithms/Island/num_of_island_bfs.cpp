#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>

using std::unordered_map;   // Hashtable
using std::unordered_set;   // Hashtable
using std::vector;          // Dynamic Array
using std::queue;

using std::string;          
using std::cout;

typedef unordered_map< string, vector<string> > Graph;
typedef unordered_set<string> Set;
typedef vector < vector<string> > Edge;

void print(Graph graph);

Graph get_graph(Edge edges);

int bfs(Graph graph, Set base_node)
{
    queue <string> queue;

    for(auto node : graph)
    {
        string source = node.first;

        if(base_node.find(source) == base_node.end())
        {
            queue.push(source);
        }

        while (!queue.empty())
        {
            string current = queue.front();
            queue.pop();

            for(auto neighbour : graph[current])
            {
                base_node.insert(neighbour);
            }
        }        
    }

    return base_node.size();
}

int num_island(Edge edges)
{
    Graph graph = get_graph(edges);
    Set base_node;
    //print(graph);
    return bfs(graph, base_node);
}

int main()
{
    Edge edge = {
        {"a","b"},
        /*
        {"d","c"},
        {"d","e"},
        {"d","f"},
        {"d","g"},
        */
        {"c","d"},
        {"e","d"},
        {"f","d"},
        {"g","d"},
        {"j","d"},
        {"h","i"},
        //{"j","l"},
        //{"z", "y"}
    };

    cout<<num_island(edge);

    return 0;
}

Graph get_graph(Edge edges)
{
    Graph graph;

    for (auto edge : edges)
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
        for(auto neighbour : node.second)
        {
            cout<<neighbour<<" ";
        }
        cout<<"\n";
    }
}

