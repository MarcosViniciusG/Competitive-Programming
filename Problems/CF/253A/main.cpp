#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m;
    ifstream inp ("input.txt");
    inp >> n >> m;

    bool alt = true;
    if(n > m)
        alt = false;

    int cB=n;
    int cG=m;
    string s="";
    for(int i=0; i<(n+m); i++) {
        if((alt || cB==0) && cG>0) {
            cG--;
            s += "G";
            alt = false;
        }
        else if(cB>0) {
            cB--;
            s += "B";
            alt = true;
        }
    }
    
    s += "\n";

    ofstream f;
    f.open ("output.txt");
    f << s;
    f.close();

    return 0;
}