#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

signed main()
{
    int n;
    cin >> n;

    int miny = 1e5, minx = 1e5;
    int maxy = -1, maxx = -1; 
    
    int x, y;
    vector<pair<int, pair<int,int>>> keep;
    map<int,int> remx, remy;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;

        remx[x]++;
        remy[y]++;

        miny = min(miny, y);
        maxy = max(maxy, y);
        minx = min(minx, x);
        maxx = max(maxx, x);

        keep.push_back(make_pair(i+1, make_pair(x, y)));
    }

        set<int> xminy, xmaxy, yminx, ymaxx;
        for(auto p : keep)
        {
            if(p.second.first == minx) yminx.insert(p.second.second);
            if(p.second.first == maxx) ymaxx.insert(p.second.second);
            if(p.second.second == miny) xminy.insert(p.second.first);
            if(p.second.second == maxy) xmaxy.insert(p.second.first);
        }

        vector<pair<pair<int,int>,pair<int,int>>> segcheck;
        segcheck.push_back(make_pair(make_pair(maxx, *ymaxx.rbegin()), make_pair(maxx - *xmaxy.rbegin(), *ymaxx.rbegin() - maxy)));
        segcheck.push_back(make_pair(make_pair(*xminy.rbegin(), miny), make_pair(*xminy.rbegin() - maxx, miny - *ymaxx.begin())));
        segcheck.push_back(make_pair(make_pair(minx, *yminx.begin()), make_pair(minx - *xminy.begin(), *yminx.begin() - miny)));
        segcheck.push_back(make_pair(make_pair(*xmaxy.begin(), maxy), make_pair(*xmaxy.begin() - minx, maxy - *yminx.rbegin())));

        set<int> ans;
        for(auto p : keep)
        {
            if(p.second.first == minx) ans.insert(p.first);
            if(p.second.first == maxx) ans.insert(p.first);
            if(p.second.second == miny) ans.insert(p.first);
            if(p.second.second == maxy) ans.insert(p.first);

        
            /* if(p.b.a < maxx && p.b.a > *xmaxy.rbegin() && p.b.b < maxy && p.b.b > *ymaxx.rbegin()) ans.insert(p.first);
            if(p.b.a < maxx && p.b.a > *xminy.rbegin() && p.b.b > miny && p.b.b < *ymaxx.begin()) ans.insert(p.first);
            if(p.b.a > minx && p.b.a < *xminy.begin() && p.b.b > miny && p.b.b < *yminx.begin()) ans.insert(p.first);
            if(p.b.a > minx && p.b.a < *xmaxy.begin() && p.b.b < maxy && p.b.b > *yminx.rbegin()) ans.insert(p.first); */

            bool check = false;
            for(auto e : segcheck)
            {
                int savex = p.b.a - e.a.a, savey = p.b.b - e.a.b;

                double gox = (double)savex/e.b.a, goy = (double)savey/e.b.b;
                if(gox == goy && gox > 0 && gox < 1) check = true;
            }
            if(check) ans.insert(p.first);
        }

        for(auto it = ans.begin(); it != ans.end(); it++)
        {
            cout << *it << " ";
        } cout << '\n';
}