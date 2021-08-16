#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using std::unordered_map;
using std::stack;
using std::string;
using std::vector;
using std::cout;
using std::endl;

void depth_first_search(unordered_map<string , vector <string> > graph, string source)
{
    stack<string> stack;

    stack.push(source);

    while (!stack.empty())
    {
        string current = stack.top();
        cout<<current<<endl;
        stack.pop();

        for(auto neighbour : graph[current])
        {
            stack.push(neighbour);
        }
    }
    
}

int main()
{   // Similar to Python's Dictionary
    // Declarying Node as String and Neighbour as Vector of String 
    unordered_map<string , vector <string> > graph;

    // Node a and it's neighbour
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