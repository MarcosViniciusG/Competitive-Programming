## Knapsack
### Subset sum (with chosen items)
O(nW)
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
O(nW)
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