#include <bits/stdc++.h>

using namespace std;

string algo(string s) {
    string s_asc = s;
    sort(s_asc.begin(), s_asc.end());

    string s_dsc = s;
    sort(s_dsc.begin(), s_dsc.end(), greater<char>());
  
    string result = to_string(stoll(s_dsc)-stoll(s_asc));
    cout << stoll(s_dsc) << " - " << stoll(s_asc) << " = " << result << '\n';

    return result;
}

void solve(string s) {
    set<string> already;
    already.insert(s);
    cout << "Original number was " << s << '\n';

    string result = algo(s);
    
    while(already.find(result)==already.end()) {
        already.insert(result);
        result = algo(result);
    }

    cout << "Chain length " << already.size() << '\n';
    return;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s="";
    while(getline(cin, s), s!="0") {
        solve(s);
        cout << '\n';
    }


    return 0;
}