## Coin problem

### Minimum number of coins to form the sum n (with chosen coins)
`O(n*coins.size())`
```cpp
int chosen[n+1];
int f[n+1];

f[0] = 0;
for (int i = 1; i <= n; i++) {
    f[i] = INF;
    for (auto c : coins) {
        if (i-c >= 0 && f[i-c]+1 < f[i]) {
            f[i] = f[i-c]+1;
            chosen[i] = c;
        }
    }
}
```

#### Retrieval of chosen items
```cpp
while(n > 0) {
    cout << chosen[n] << '\n';
    n -= chosen[n];
}
```
***

### Counting the number of solutions
`O(n*coins.size())`
```cpp
ll m = BIGNUMBER; // Prevents overflow
int f[n+1];
memset(f, 0, sizeof(f));

f[0] = 1;
for (int i = 1; i <= n; i++) {
    for (auto c : coins) {
        if(i-c >= 0) {
            f[i] += f[i-c];
            f[i] %= m;
        }
    }
}
```
***

### Counting the number of ordered solutions
`O(n*coins.size())`
```cpp
ll m = BIGNUMBER; // Prevents overflow
int f[n+1];
memset(f, 0, sizeof(f));

f[0] = 1;
for (auto c : coins) {
    for (int i = 1; i <= n; i++) {
        if(i-c >= 0) {
            f[i] += f[i-c];
            f[i] %= m;
        }
    }
}
```

## Knapsack
### Subset sum (with chosen items)
`O(n*W)`
```cpp
bool f[W+1];
memset(f, false, sizeof(f));
f[0] = true;

int chosen[W+1];
memset(chosen, -1, sizeof(chosen));

for (int i = 0; i < n; i++) {
    for (int j = W; j >= 0; j--) {
        if (f[j] && (j+a[i]) <= W) {
            f[j+a[i]] = true;
            if(chosen[j+a[i]]==-1)
                chosen[j+a[i]] = i;
        }
    }
}
```

#### Retrieval of chosen items (`if (f[W]==true)`)
```cpp
vector<bool> items (n, false);

while(W > 0) {
    int i = chosen[W];
    items[i] = true;
    W -= a[i];
}
```
***

### 0-1 Knapsack (with chosen items)
`O(n*W)`
```cpp
int f[W+1];
memset(f, 0, sizeof(f));

int chosen[W+1];
memset(chosen, -1, sizeof(chosen));

for (int i = 0; i < n; i++) {
  for (int j = W; j >= w[i]; j--) {
    if(f[j] < (f[j-w[i]] + v[i])) {
        f[j] = (f[j - w[i]] + v[i]);

        chosen[j] = i;
    }
  }
}
```

#### Retrieval of chosen items
```cpp
vector<bool> items (n, false);

while(W > 0 && chosen[W]!=-1) {
        int i = chosen[W];
        items[i] = true;
        W -= w[i];
    }
```