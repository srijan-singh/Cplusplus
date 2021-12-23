#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

class PlayFare
{
    string temp_matrix[25];
    string matrix[5][5];
    unordered_map<string, vector<int>> locator; //Graph or Hash Table
    //Position
    int x1=0,x2=0,y1=0,y2=0;

    public:

    // Users Function
    PlayFare(string keyword)
    {
        get_temp_matrix(keyword);

        get_locator();
    }

    string cypher(string plain_text)
    {    
        string result = "";

        vector<string> duplet;

        for(int i=0; i<plain_text.size(); i+=2)
        {   
            string a = "";
            string b = "";

            a +=plain_text[i];
            b+=plain_text[i+1];

            if(row_rule(a,b));
            if(column_rule(a,b));
            if(rectangle_rule(a,b));

            string x = "";
            string y = "";

            x+=matrix[x1][y1];
            y+=matrix[x2][y2];

            result+=x+y;
        }

        return result;
    }

    // Populating Matrix and Locator
    bool distinct(string keyword, char letter)
    {
        for(auto element : keyword)
        {
            if(letter == element)
            {
                return false;
            }
        }
        return true;
    }

    void get_temp_matrix(string keyword)
    {        
        int length = keyword.size();

        for(int i=0; i<length; i++)
        {
            temp_matrix[i] = keyword[i];
        } 

        int position = 65; //A

        while(length<25)
        {
            if (position == 90) //Z
            {
                break;
            }

            if(distinct(keyword, char(position)))
            {
                temp_matrix[length] = char(position);
                length++;
            }

            position++;
            continue;
        }   
    }

    void get_2d_matrix()
    {
        int x=-1, y=0;

        for(int i=0; i<25; i++)
        {
            if(i%5==0)
            {
                x+=1;
            }
            y=i%5;

            matrix[x][y]=temp_matrix[i];
        }
    }

    void get_locator()
    {
        get_2d_matrix();

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(matrix[i][j] == "Y") // Y/Z (5x5 Matrix)
                {
                    locator["Z"] = {i,j};
                }

                locator[matrix[i][j]] = {i,j} ;
            }
        }
    }

    // Rules
    bool row_rule(string a, string b)
    {
        int i = locator[a][0];
        int j = locator[b][0];

        
        x1 = locator[a][0];
        x2 = locator[b][0];

        y1 = locator[a][1] + 1;
        y2 = locator[b][1] + 1;

        return i==j;
    }

    bool column_rule(string a, string b)
    {
        int i = locator[a][1];
        int j = locator[b][1];

        x1 = locator[a][0] + 1;
        x2 = locator[b][0] + 1;

        y1 = locator[a][1];
        y2 = locator[b][1];

        return i==j;
    }

    bool rectangle_rule(string a, string b)
    {
        if(!row_rule(a,b) and !column_rule(a,b))
        {
            //Opposite Element
            x1 = locator[a][0]; 
            x2 = locator[b][0];

            //Column Changes
            y2 = locator[a][1];
            y1 = locator[b][1];

            return true;
        }
        return false;
    }

    // Print (Optional)
    void print_temp_matrix()
    {
        for(int i=0; i<25; i++)
        {
            cout<<temp_matrix[i]<<" ";
        }
        cout<<endl;
    }

    void print_matrix()
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    void print_locator()
    {
        for(auto element : locator)
        {
            cout<<element.first<<" ";

            cout<<element.second[0]<<" ";

            cout<<element.second[1]<<endl;
        }
    }

};

int main()
{
    string str = "UNIVERSITY";
    string keyword = "COMPUTER";
    PlayFare p(keyword);
    cout<<p.cypher(str);
    return 0;
}