#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::boolalpha;

bool has_path(unordered_map <string, vector <string> > graph, string source, string destination)
{
    if (source == destination)
    {
        return true;
    }

    for (auto neighbour : graph[source])
    {
        if (has_path(graph, neighbour, destination) == true)
        {
            return true;
        }
    }

    return false;
}

int main()

{
    unordered_map <string, vector <string> > graph;

    // Both way's are valid

    /* Generic
    graph = {
        {"f", {"g","i"}},

        {"g", {"h"}},

        {"h", {}},

        {"i", {"g","k"}},

        {"j", {"i"}},

        {"k", {}}
    };
    */

    // Using operator
    graph["f"] = {"g","i"};

    graph["g"] = {"h"} ;

    graph["h"];

    graph["i"] = {"g", "k"};

    graph["j"] = {"i"};

    graph["k"];

    string source = "f";

    string destination = "k";

    cout<<boolalpha<<has_path(graph, source, destination);

    return 0;
}