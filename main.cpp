#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

using std::string;
using std::to_string;
using std::cout;
using std::endl;

typedef unordered_map<string ,vector<string>> Graph;
typedef unordered_set<string> Set;
typedef vector<vector<string>> Edge;

void print(Graph);

Graph get_graph(Edge);

int dfs(Graph graph, string source, Set visited)
{
    if(visited.find(source) != visited.end())
    {
        cout<<source<<endl;
        visited.insert(source);

        for(auto neighbour : graph[source])
        {
            return dfs(graph, neighbour, visited);
        }
    }
    return visited.size();   
}

int num_island(Edge edges)
{
    Set visited;
    Graph graph = get_graph(edges);
    int size = 0;
    
    for(auto node: graph)
    {
        //cout<<visited.size()<<endl;
        size = dfs(graph, node.first, visited);
    }

    return size;
}

int set_size(Set set, int count=0)
{
    if(set.size()>4)
    {
        return set.size();
    }

    string input = to_string(count);
    set.insert(input);
    
    return set_size(set, ++count);
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

    Set set;

    //cout<<set_size(set);

    cout<<num_island(edge);
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
        cout<<"Node: "<<node.first<<" Neighbour : ";
        for(auto neighbour : node.second)
        {
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
}


