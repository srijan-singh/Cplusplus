#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main()
{
    vector <int> x = {1, 2};
    x.push_back(12);
    std::cout<<x[x.size()-1]<<"\n"; //To print the last element
    std::cout<<x.size()<<"\n"; //To priint the size of array
    x.pop_back(); //To remove the last element
    std::cout<<x[x.size()-1]<<"\n";
    return 0;
}