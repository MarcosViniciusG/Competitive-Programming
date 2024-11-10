#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n=1;
    string s;
    cin >> n;
    int cas=1;
    while (n!=0)
    {   
        string start="#include<string.h>\n#include<stdio.h>\nint main()\n{\n";

        cin.ignore(1, '\n');
        for(int i=0; i<n; i++) {
            getline(cin, s);
            for(int j=0; j<s.size(); j++) {
                if(s[j]=='"' || s[j]=='\\') {
                    s.insert(s.begin()+j, '\\');
                    j++;
                }
            }

            start += "printf(\"" + s + "\\n\");";
            start += '\n';
        }

        string en = "printf(\"\\n\");\nreturn 0;\n}\n";

        cout << "Case " << cas <<  ":\n";
        cout << start + en;

        cin >> n;
        cas++;
    }
    

    return 0;
}