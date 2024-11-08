#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    int T;
    cin >> T;
    cin.ignore(1, '\n');
    string s, t;
    while(T--) {
        getline(cin , s);
        getline(cin , t);

        queue<char> q;

        bool can = false;
        for(auto c: t) {
            q.push(c);
        }

        for(int i=0; i< s.size(); i++) {
            if(!q.empty() && s[i] == q.front()) {
                q.pop();
            }
            else if(s[i]=='?') {
                if(!q.empty()) {
                    s[i] = q.front();
                    q.pop();
                }
                else
                    s[i] = 'a';
            }

            if(q.empty())
                can = true;
        }

        if(can) {
            cout << "YES\n";
            cout << s << endl;
        }
        else
            cout << "NO\n";
    }

    return 0;
}