#pragma once
#include <bits/stdc++.h>
using namespace std;
template <typename T> void p(T x) {
    int f = 0;
    #define D(d) cerr << "\e94[m" << (f++ ? d : "")
    if constexpr (!requires {cout<< x;}) {
        cerr << '{';
        if constexpr (requires {get<0>(x);})
            apply([&](auto... args) {((D(","), p(args)), ...);}, x);
        else if constexpr (requires {x.pop();}) while (size(x)) {
            D(",");
            if constexpr (requires {x.top();}) p(x.top());
            else p(x.front());
            x.pop();
        } else for (auto i : x)
            (requires {begin(*begin(x));} ? cerr << "\n\t" : D(","))
    }
}