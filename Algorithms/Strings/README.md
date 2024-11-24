# Strings

## Palindromes

### Iterative
`O(|s|)`

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
`O(|s|)`

```cpp
bool is_palindrome(const string& s, int i, int j)
{
    if(j-i <= 1)
        return true;

    return (s[i]==s[j]) && (is_palindrome(s, i+1, j-1));
}
```

### All substrings that are palindromes
`O(|s|^3)`

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
`O(|s|)`

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
`O(|s|)`

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
`O(|s|+|t|)`

```cpp
bool is_anagram(const string& s, const string & t) {
    return (histogram(s)==histogram(t));
}
```

### Sorting
`O(|s| log |s| + |t| log |t|)`

```cpp
bool is_anagram(const string& s, const string & t) {
    string a(s), b(t);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return (a==b);
}
```

### Number of anagrams
`O(|s|^2)`

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
`O(|s|!)`

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

## Facts
