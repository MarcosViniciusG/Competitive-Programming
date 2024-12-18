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
string build(int n) {
    string ans="";
    for(int i=0; i<=n; i++) 
        ans += to_string(i);
    return ans;
}

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