#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::cout;
using std::sort;
using std::vector;
using std::unordered_map;


typedef vector<int> Vect;
typedef unordered_map<int, int> Graph;

struct Activity
{
    int start;
    int finish;
};

bool activity_sort(Activity a1, Activity a2)
{
    return a1.finish < a2.finish;
}

int activity_selection(Vect start, Vect end)
{
    int count = 1;
    int length = end.size();

    Activity act[length];

    for(int i=0; i<length; i++)
    {
        act[i].start = start[i];
        act[i].finish = end[i];
    }

    sort(act, act+length, activity_sort);

    int i = 0;

    cout<<"Start "<<act[i].start<<" Finish "<<act[i].finish<<"\n";

    for(int j=1; j<length; j++)
    {
        if(act[j].start >= act[i].finish)
        {
            count++;
            i=j;
            cout<<"Start "<<act[j].start<<" Finish "<<act[j].finish<<"\n";
        }
    }



    return count;
}

int main()
{
    Vect start = {
        5,1,3,0,5,8
    };
    Vect end = {
        9,2,4,6,7,9
    };

    cout<<activity_selection(start, end);

    return 0;
}