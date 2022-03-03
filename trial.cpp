#include<iostream>

using namespace std;

template <typename T> T maximum(T elm1, T elm2){
    return (elm1 > elm2) ? elm1 : elm2;
}

int main()
{
    std::cout<<maximum(11, 12)<<std::endl;
    std::cout<<maximum(11.1212, 12.21)<<std::endl;
    std::cout<<maximum("hello", "world")<<std::endl;
    return 0;   
}