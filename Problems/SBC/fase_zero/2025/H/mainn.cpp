#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()

// bool isPalindrome(const string& s, ll size)
// {
//     bool ans = true;
//     for(int i = 0; i <= size/2; i++)
//     {
//         if(s[i] != s[size-1-i]) ans = false;
//     }
//     return ans;
// }

string stripzeros(const bitset<64>& bt) {
    ll ultimo = 63;
    per(i, ultimo, 0)
        if (bt[i] == 1) {
            ultimo = i;
            break;
        }
    string s = bt.to_string();
    reverse(all(s));
    s = s.substr(0, ultimo + 1);
    return s;
}

bool is_palindrome(const string& s) {
    string t = s;
    reverse(all(t));
    return s == t;
}

signed main() {
    ll n;
    cin >> n;
    // ll m = n;
    // n = 1;
    // while (n < m) {
    // cout << n << '\n';
    // ll ans = 0;
    // per(i, n, 0) {
    //     string s = stripzeros(bitset<64>(i));
    //     if (is_palindrome(s)) {
    //         ans = i;
    //         // cout << "ans: " << s << '\n';
    //         break;
    //     }
    // }
    // cout << "ans: " << ans << '\n';

    string s = stripzeros(bitset<64>(n));  
    // cout << "s: " << s << '\n';
    if (is_palindrome(s)) cout << n << '\n';
    else {
        bool livre = false;
        rep(i, 0, s.size() / 2) {
            if (s[s.size() - 1 - i] == '0' and s[i] == '1') {
                livre = true;
                s[i] = '0';
            }
            if (s[s.size() - 1 - i] == '1' and s[i] == '0')
                livre = false;
            if (!livre) s[i] = '0';
        }

        if (!livre) {
            rep(i, s.size() / 2, s.size())
                if (s[i] == '1') {
                    s[i] = '0';
                    if (i == s.size() - 1) {
                        s.pop_back();
                        fill(all(s), '1');
                    }
                    rep(j, s.size() / 2, i)
                        s[j] = s[s.size() - 1 - j] = '1';
                    break;
                }
            }

        rep(i, 0, s.size())
            if (s[s.size() - 1 - i] == '1')
                s[i] = '1';                
        ll x = 0;
        rep(i, 0, s.size())
            x += (s[i] - '0') * (1LL << i);
        cout << x << '\n';
        s = stripzeros(bitset<64>(x));
        // cout << "x em binário: " << stripzeros(bitset<64>(x)) << '\n';
        assert(x <= n);
        // assert(ans == x);
        assert(is_palindrome(s));
    }
    // ++n;}
}