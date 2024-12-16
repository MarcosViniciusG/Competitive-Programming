#pragma once
#include <bits/stdc++.h>
using namespace std;
namespace DBG {
    template<typename T>
    void C(T x, int n = 4) { cerr << fixed << "\033[9" << n << 'm' << x << "\033[m"; }
    void p(char x) { C("\'" + string({x}) + "\'", 3); }
    void p(string x) { C("\"" + x + "\"", 3); }
    void p(bool x) { x ? C('T', 2) : C('F', 1); }
    void p(vector<bool> xs) { for (bool x : xs) p(x); }
    static int m = 0;
    template<typename T>
    void p(T x) {
        int i = 0;
        if constexpr (requires { begin(x); }) {
            C('{');
            if (size(x) && requires { begin(*begin(x)); }) {
                cerr << '\n';
                m += 2;
                for (auto y : x)
                    cerr << string(m, ' ') << setw(2) << left << i++, p(y), cerr << '\n';
                cerr << string(m -= 2, ' ');
            } else 
                for (auto y : x) i++ ? C(',') : C(""), p(y);
            C('}');
        } else if constexpr (requires { x.pop(); }) {
            C('{');
            while (!x.empty()) {
                if (i++) C(',');
                if constexpr (requires { x.top(); }) p(x.top());
                else p(x.front());
                x.pop();
            }
            C('}');
        } else if constexpr (requires { get<0>(x); }) {
            C('(');
            apply([&](auto... args) { ((i++ ? C(',') : C(""), p(args)), ...); }, x);
            C(')');
        } else C(x, 5);
    }
    template<typename T, typename... V>
    void printer(const char* names, T head, V ...tail) {
        int i = 0;
        for (int bs = 0; names[i] && (names[i] != ',' || bs); ++i)
            bs += !strchr(")>}", names[i]) - !strchr("(<{", names[i]);
        cerr.write(names, i), C(" = "), p(head);
        if constexpr (sizeof...(tail)) C(" |"), printer(names + i + 1, tail...);
        else cerr << '\n';
    }
}
#define dbg(...) DBG::C(__LINE__), DBG::C(": "), DBG::printer(#__VA_ARGS__, __VA_ARGS__)