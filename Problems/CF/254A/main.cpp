#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream f("input.txt");

    string s;
    int n, a;
    getline(f, s);
    n = stoi(s);

    getline(f, s);
    
    vector<vector<int>> v (5001);

    string b = "";
    for(int i=0, c=0; i<s.size(); i++) {
        if(s[i] != ' ') {
            b += s[i];
        }
        else {
            a = stoi(b);
            v[a].push_back(c+1);
            b="";
            c++;
        }
    }

    a = stoi(b);
    v[a].push_back(n*2);

    bool possible = true;
    string sol = "";

    for(auto e: v) {
        if ((e.size() > 0) && (e.size() & 1)) {
            possible = false;
            break;
        }
        else if(e.size() > 0) {
            int c=0;
            for(int i=0; i<e.size(); i++)
            {
                sol += to_string(e[i]);
                if(c!=1) {
                    sol += " ";
                    c++;
                }
                else {
                    sol += "\n";
                    c = 0;
                }
            }
        }
    }

    ofstream MyFile("output.txt");
    if(possible)
        MyFile << sol;
    else
        MyFile << -1 << endl;

    MyFile.close();
    return 0;
}