#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
    string os = s;

    reverse(os.begin(), os.end());

    return (s==os);
}

int main() {
    int N, K;
    cin >> N >> K;

    string s;
    cin.ignore(1, '\n');
    getline(cin, s);
    
    sort(s.begin(), s.end());

    int c=0;
    do
    {
        bool sat = true;
        for(int i=0; (i+K)<=s.length() && sat; i++) {
            string sub="";
            for(int j=i; j<(K+i); j++) {
                sub+= s[j]; 
            }

            if(is_palindrome(sub))
                sat = false;
        }

        if(sat)
            c++;

    } while (next_permutation(s.begin(), s.end()));
    
    cout << c << endl;

    return 0;
}