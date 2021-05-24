#include <iostream>
#include <string>

using std::cout;

int main()
{
    cout<<"Ram Ram!"<<std::endl;   //Regular
    cout<<"Ram \nRam!"<<std::endl; // \n add a new line
    cout<<"Ram \tRam!"<<std::endl; // \t tabular form
    cout<<"Ram \bRam!"<<std::endl; // \b backspace
    cout<<"Ram \vRam!"<<std::endl;
    cout<<"Ram \0Ram!"<<std::endl; // \0 Terminate the String
    cout<<"Ram \aRam!"<<std::endl;
    cout<<"Ram \"Ram!"<<std::endl; // \" To add " 
    cout<<"Ram \\Ram!"<<std::endl; // \\ to add \ 

    return 0;
}