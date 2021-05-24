#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

int main()
{
    string name = "Srijan";
    cout<<name<<std::endl;
    name = "Ritika";
    cout<<name<<std::endl;
 
    //Concatenation and Append

    string greetings = "Hello";
    string complete_greetings = greetings + " " + name;//concatenation
    cout<< complete_greetings<<std::endl; 
    complete_greetings += "!"; //append
    cout<<complete_greetings<<std::endl;
    

    //Taking Input
    
    string new_name;
    getline(cin, new_name); //Take input like python
    cout<<new_name<<std::endl;

    //Length Function

    cout<<new_name.length()<<std::endl; // Both are same
    cout<<new_name.size()<<std::endl; 
 

    //To add or remove from string

    //Append Function
    cout<<greetings.append(" What's up?")<<std::endl;      // To add you can also do {name+= " ji"}
    
    //Insert Function
    cout<<greetings.insert(6, new_name)<<std::endl;  // To insert a string at a particular index
    
    //Erase Function
    cout<<greetings.erase(4, 4)<<std::endl;
    cout<<greetings.erase(4)<<std::endl;
    cout<<greetings.erase(name.length() -1)<<std::endl;
    
    //To remove last letter
    name.pop_back();
    cout<<greetings<<std::endl;

    //Replace Function
    cout<<greetings.replace(2, 1, "pal")<<std::endl;
    cout<<greetings.find("bob")<<std::endl;
    cout<<greetings.replace(name.find("bob"), 1, "pal");

    //Compare
    if(greetings == "Hello")
    {
        cout<<"Equal";
    }
    if(greetings.compare("Hello") == 0)
    {
        cout<<"Equal";
    }

    return 0;
}
