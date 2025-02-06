# Strings

## Palindromes

### Iterative
$O(|s|)$

```cpp
bool is_palindrome(const string &s)
{
    int N = s.size();

    for(int i=0; i<N/2; i++)
        if(s[i] != s[N - 1 - i])
            return false;
    
    return true;
}
```

### Recursive
$O(|s|)$

```cpp
bool is_palindrome(const string& s, int i, int j)
{
    if(j-i <= 1)
        return true;

    return (s[i]==s[j]) && (is_palindrome(s, i+1, j-1));
}
```

### All substrings that are palindromes
$O(|s|^3)$

```cpp
vector<string> palindromes(const string& s)
{
    int N = s.size();
    vector<string> ps;

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            string sub = s.substr(i, j-i);
            if(is_palindrome(sub))
                ps.push_back(sub);
        }
    }

    return ps;
}
```

## Histograms

### Counters
$O(|s|)$

```cpp
map<char, int> histogram(const string& s)
{
    map<char, int> h;

    for(auto c: s)
        ++h[c];

    return h;
}
```

### Indexes
$O(|s|)$

```cpp
map<char, vector<int>> histogram(const string& s)
{
    map<char, int> h;

    for(int i=0; i<s.size(); i++)
        h[s[i]].push_back(i);

    return h;
}
```

## Anagrams

### Histogram
$O(|s|+|t|)$

```cpp
bool is_anagram(const string& s, const string & t) {
    return (histogram(s)==histogram(t));
}
```

### Sorting
$O(|s| log |s| + |t| log |t|)$

```cpp
bool is_anagram(const string& s, const string & t) {
    string a(s), b(t);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return (a==b);
}
```

### Number of anagrams
$O(|s|^2)$

```cpp
ll n_anagrams(const string &s) {
    ll N = s.size();
    map<char, ll> hist = histogram(s);

    ll n=1;
    for(ll i=2; i<N; i++) {
        n *= i;

        for(auto p: hist) {
            if(p.second<=i) (
                n /= i;
                break;
            )
        }
    }

    return n;
}
```

### All anagrams
$O(|s|!)$

```cpp
vector<string> anagrams(const string &s) {
    string a(s);

    vector<string> as;
    sort(a.begin(), a.end());

    do {
        as.push_back(a);
    } while(next_permutation(a.begin(), a.end()));

    return as;
}
```

## Hashes
$O(|s|)$

- If only lowercase chars, use $p = 31$
- Else if lowercase + uppercase, use $p = 53$
- Use $q = 1e9 + 7$ or $q=1e9 + 9$

```cpp
ll h(string s) {
    ll ans=0;

    for(auto c: s)
    {
        ans = (ans*p) % q;
        ans = (ans + to_int(c)) % q;
    }

    return ans;
}
```

### Distinct substrings
$O(|s|^2)$
```cpp
vll prefixes(string s) 
{
    ll n = s.length();
    vll ps(n, 0);

    for(ll i=0; i<n; i++) 
        ps[i] = h(s.substr(0, i+1));

    return ps;
}

ll fast_exp_mod(ll a, ll n) {
    ll res=1, base=a;

    while(n) {
        if(n & 1)
            res = (res*base) % q;
        
        base = (base*base) % q;
        n >>=1;
    } 

    return res;
}

vll inverses(ll n)
{
    vll is(n);
    ll base=1;

    for(ll i=0; i<n; i++) {
        is[i] = fast_exp_mod(base, q-2);
        base = (base*p) % q;
    }
    
    return is;
}

ll h(ll i, ll j, vll ps, vll is) {
    ll diff = i ? ps[j] - ps[i-1] : ps[j];
    diff = (diff*is[i]) % q;

    return(diff + q) % q;
}

ll unique_substrings(string s) {
    unordered_set<ll> hs;
    ll n = s.length();

    vll ps = prefixes(s);
    vll is = inverses(n);

    for(ll i=0; i<n; i++) {
        for(ll j=i; j<n; j++) {
            ll hij = h(i, j, ps, is);

            hs.insert(hij);
        }
    }

    return hs.size();
}
```

#### Alternative implementation
```cpp
ll count_unique_substrings(string s) {
    ll n = s.length();

    // Pre-calculate powers of p
    vll p_pow(n);
    p_pow[0] = 1;
    for(ll i=1; i<n; i++) 
        p_pow[i] = (p_pow[i-1] * p) % q;

    // Pre-calculate hashes of prefixes of s
    vll h(n+1, 0);
    for(ll i=0; i<n; i++)
        h[i+1] = (h[i] + to_int(s[i]) * p_pow[i]) % q;
    
    ll cnt=0;
    // Iterate over all substrings of lenght l
    for(ll l=1; l<=n; l++) {
        unordered_set<ll> hs;
        for(ll i=0; i<=n-l; i++) {
            ll cur_h = (h[i+l] + q - h[i]) % q;
            cur_h = (cur_h * p_pow[n-i-1]) % q;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }

    return cnt;
}
```

### Double hash
```cpp
ll hi(string s, ll p, ll q) {
    ll ans=0;

    for(auto c: s) {
        ans = (ans * p) % q;
        ans = (ans + to_int(c)) % q;
    }

    return ans;
}

pll h(string s) {
    ll p1 = 31;
    ll p2 = 29;
    ll q1 = ll(1e9) + ll(7);
    ll q2 = ll(1e9) + ll(9);

    return {hi(s, p1, q1), hi(s, p2, q2)};
}
```

## KMP
$O(|s| + |p|)$
```cpp
ll KMP(string s, string p) {
    ll n = s.length(), m=p.length(), i=0, j=0, occ=0;

    vll bs = strong_borders(p);

    while(i<=n - m) {
        while(j < m && p[j]==s[i+j])
            j++;
        
        if(j==m) occ++;

        ll shift = j-bs[j];
        i += shift;
        j = max(0LL, j-shift);
    }

    return occ;
}
```

### Calculate strong borders
$(|s|)$

```cpp
vll strong_borders(string s) {
    ll n = s.length(), t=-1;
    vll bs(n+1, -1);

    for(ll i=1; i<=n; i++) {
        while(t>-1 && s[t] != s[i-1])
            t = bs[t];

        t++;
        bs[i] = (i==m || s[t] != s[i]) ? t: bs[t];
    }

    return bs;
}
```

### Calculate borders
$O(|s|)$

```cpp
vll borders(string s) {
    ll n = s.length(), t=-1;
    vll bs(n+1, -1);
    
    for(ll i=0; i<n; i++) {
        while(t >-1 and s[t]!=s[i])
            t = bs[t];
        
        bs[i+1] = t++;
    }

    return bs;
}

```

## Z-function
$O(|s|)$

```cpp
vll z(string s) {
    ll n = s.length(), L = 0, R = 0;
    vll zs(n, 0);
    for (ll i = 1; i < n; i++) {
        if (i <= R)
            zs[i] = min(zs[i - L], R - i + 1);

        while (zs[i] + i < n && s[zs[i]] == s[i + zs[i]])
            zs[i]++;

        if (R < i + zs[i] - 1)
            L = i, R = i + zs[i] - 1;
    }

    return zs;
}
```

### Number of occurrences
$O(|s|)$

```cpp
ll search(string s, string p, char delim='#') {
    string t {p + delim + s};
    vll zs = z(t);
    ll occ = 0, m=p.length();

    for(ll x: zs)
        occ += (x==m ? 1 : 0);

    return occ;
}
```

## Edit Distance
$O(nm)$

- $edit(S, T)$ is the minimum cost to transform the string $S$ into the string $T$ 
- $edit(S, T) \ge 0$  
- $edit(S, T) = 0$ if, and only if, $S = T$
- $edit(S, T) = edit(T, S)$ (symmetry)
- $edit(S, T) \leq edit(S, U) + edit(U, T)$ (triangular inequality)

### $O(nm)$ memory complexity
```cpp
ll edit(const string& s, const string& t) {
    const ll c_i=1, c_r = 1, c_s = 1; // Costs
    ll m = s.length(), n = t.length();

    for(ll i=0; i<=m; i++)
        st[i][0] = i*c_r; 
    
    for(ll j=1; j<=n; j++)
        st[0][j] = j*c_i;

    for(ll i=1; i<=m; i++) {
        for(ll j=1; j<=n; j++) {
            ll insertion = st[i][j-1] + c_i;
            ll deletion = st[i-1][j] + c_r;
            ll change = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? ll(0) : ll(1));
            st[i][j] = min({insertion, deletion, change});
        }
    }

    return st[m][n];
}

```

### $O(n)$ memory complexity
```cpp
ll edit(const string& s, const string& t) {
    const ll c_i=1, c_r = 1, c_s = 1; // Costs
    ll m = s.length(), n = t.length();
    ll *prev = a, *line = b;

    for(ll j=1; j<=n; j++)
        prev[j] = j*c_i; 

    for(ll i=1; i<=m; i++) {
        line[0] = i*c_r;

        for(ll j=1; j<=n; j++) {
            ll insertion = line[j-1] + c_i;
            ll deletion = prev[j] + c_r;
            ll change = prev[j-1] + c_s*(s[i-1] == t[j-1] ? ll(0) : ll(1));
            line[j] = min({insertion, deletion, change});
        }

        swap(line, prev);
    }

    return prev[n];
}
```

### Optimal operations
```cpp
string edit_operations(const string&s, const string& t)
{
    const ll c_i=1, c_r=1, c_s=1; // Costs
    ll m = s.length(), n = t.length();

    for(ll i=0; i<=m; i++) {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for(ll j=1; j<=n; j++) {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for(ll i=1; i<= m; i++) {
        for(ll j=1; j<= n; j++) {
            ll insertion = st[i][j-1] + c_i;
            ll deletion = st[i-1][j] + c_r;
            ll change = st[i-1][j-1] + c_s*(s[i-1]==t[j-1] ? ll(0) : ll(1));

            st[i][j] = min({insertion, deletion, change});

            ps[i][j] = (insertion <= deletion && insertion <=change) ? 
                'i' : (deletion <= change ? 'r' : 's');
        }
    }

    ll i=m, j=n;
    ostringstream os;

    while(i || j) {
        switch(ps[i][j]) {
            case 'i':
                os << t[j-1];
                j--;
                break;
            case 'r':
                os << '-';
                i--;
                break;
            case 's':
                if(s[i-1] == t[j-1])
                    os << '=';
                else
                    os << "]" << t[j-1] << ">-" << s[i-1] << "[";
            i--; j--;
        }
    }

    auto ops = os.str();
    reverse(ops.begin(), ops.end());

    return ops;
}
```

## Longest Palindrome Subsequence
$O(n^2)$
```cpp
ll dp(const string& s, ll i, ll j)
{
    if (i > j)
        return 0;
    
    if(i==j)
        return 1;

    if(st[i][j] != -1)
        return st[i][j]; 

    st[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));

    if(s[i] == s[j])
        st[i][j] = max(st[i][j], dp(s, i+1, j-1) + 2);

    return st[i][j];
}
```

### Recuperation of LPS
$O(n^2)$
```cpp
ll dp(const string& s, ll i, ll j)
{
    if (i > j)
        return 0;
    
    if(i==j) {
        ps[i][j] = 'K';
        return 1;
    }

    if(st[i][j] != -1)
        return st[i][j]; 

    st[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));
    ps[i][j] = dp(s, i+1, j) > dp(s, i, j-1) ? 'L' : 'R';

    if(s[i] == s[j]) {
        st[i][j] = max(st[i][j], dp(s, i+1, j-1) + 2);
        ps[i][j] = st[i][j] > dp(s, i+1, j-1) + 2 ? ps[i][j] : 'B';
    }

    return st[i][j];
}

string lps(const string& s)
{
    memset(st, -1, sizeof(st));
    memset(ps, 0, sizeof(ps));

    ll n = s.length();

    dp(s, 0, n-1);

    ll i=0, j=n-1;
    string L = "", R="";

    while(i <= j)
    {
        auto p = ps[i][j];
        switch(p) {
            case 'L':
                i++;
                break;
            
            case 'R':
                j--;
                break;
            
            case 'K':
                L += s[i];
                i++;
                break;
            
            default:
                L += s[i]; R = s[i] + R;
                i++; j--;
                break;
        }
    }

    return L+R;
}
```

## Tries
- It's the graph $G$ that represents all the substring of s, which labels are made of only one character
- Black nodes are essential nodes
- The numbers besides the essential nodes are the indexes of the initial character of the suffix

### Building 
$O(|T_n|)$
```cpp
using Node = map<char, ll>;
using Trie = vector<Node>;

Trie build(const string& s)
{
    ll next=0, deepest=0;
    string S = s+'#';
    vll suf {-1};
    Trie trie(1);

    for(size_t i=0; i<S.size(); i++)
    {
        char c = S[i];
        ll u = deepest;

        while(u >= 0)
        {
            auto it = trie[u].find(c);

            if(it == trie[u].end())
            {
                trie.push_back({ });
                trie[u][c] = ++next;

                suf.push_back(0);

                if(u != deepest)
                    suf[next-1] = next;
                else
                    deepest = next;
            }
            else
            {
                suf[next] = it->second;
                break;
            }
            u = suf[u];
        }
    } 

    return trie;
}
```

### Search
$O(m)$
```cpp
bool search(const Trie& trie, const string& s) {
    ll v=0;

    for(auto c: s)
    {
        auto it = trie[v].find(c);

        if(it==trie[v].end())
            return false;
        
        v = it->second;
    }

    return true;
}
```

## Remarkable strings

### Fibonacci strings
```cpp
string build(int n) {
    string ans="";
    if(n==0) return ans;
    else if(n==1) return (ans+'b');
    else if(n==2) return (ans+'a');

    ans += build(n-1);
    ans += build(n-2);
    return ans;
}
```

### Thue-Morse prefixes
```cpp
string build(int n) {
    string ans;
    for(int k=0; k<(1<<n); k++) {
        if(__builtin_popcount(k) & 1)
            ans += 'b';
        else
            ans += 'a';
    }

    return ans;
}
```

### Binary words
```cpp
string build(int n) {
    string ans="";
    for(int k=0; k<=n; k++) {
        ans += to_string((fact(n) / (fact(k) * fact(n-k))) % 2); 
    }

    return ans;
}
```

### Digits string
```cpp
string build(int n) {
    string ans="";
    for(int i=0; i<=n; i++) 
        ans += to_string(i);
    return ans;
}
```

## Facts

### Periods and borders
- The sequence: $ |s| - |border(s)|, |s| - |border^2(s)|, ..., |s| - |border^k(s)| $ is the crescent sequence of all possible periods of s, where k is the smallest positive integer such that $|border^k(s)|=0$

### Fibonacci strings
- Removing the last two letters of a Fibonacci string give us a palindrome
- Any Fibonacci string $F_n$ with $n \ge 2$ is a prefix of another Fibonacci string
- Every Fibonacci string $F_n$ with $n \ge 2$ is a prefix of $F_\infty$

### Thue-Morse prefixes
- They are free from overlaps (There is no emtpy string $s$ that occurs em two distinct positions of $T(n)$ with a distance between the positions smaller than $|s|$)
- They are free from squares

### Binary words
- The number of occurences of the char `'1'` in $P_n$ is equal to $2^{g(n)}$, where $g(n)$ is equal to the number of ones in the binary representation of k

### Digits string
- Let $s$ be a string composed by decimal digits. The function $occ_n(s)$ computes the number of occurrences of s in $W_n$