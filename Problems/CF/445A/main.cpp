#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<string> board;
    vector<string> ans;
    string str;
    cin.ignore(1, '\n');
    for(int i=0; i<n; i++)
    {
        getline(cin, str);
        board.push_back(str);
    }

    bool alt = false;
    for(int i=0; i<n; i++)
    {
        string s="";
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == '-')
                s += "-";
            else
                if(!alt)
                    s += "B";
                else
                    s += "W";
    
            if(!alt)
                alt = true;
            else
                alt = false;
        }
        if(m % 2 == 0)
        {
            if(alt)
                alt = false;
            else
                alt = true;
        }
        
        ans.push_back(s);
    }
   
    for(auto s: ans)
    {
        cout << s << endl;
    }

    return 0;
}