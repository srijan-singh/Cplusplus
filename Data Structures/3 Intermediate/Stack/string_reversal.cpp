#include <iostream>
#include <stack>
#include <string>

std::string reverse(std::string s, int len)
{
    std::stack<char> S;

    for(int i=0; i<len; i++)
    {
        S.push(s[i]);
    }
    for(int i=0; i<len; i++)
    {
        s[i] = S.top();
        S.pop();
    }
    return s;
}

int main()
{
    std::string s;
    getline(std::cin, s);
    int len = s.length();
    std::string reverse_string = reverse(s, len);
    std::cout<<reverse_string;
}