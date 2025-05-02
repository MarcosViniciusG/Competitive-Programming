        #include <bits/stdc++.h>
        using namespace std;

        #define ll long long
        #define vll vector<ll>
        #define vvll vector<vll>
        #define x first
        #define y second
        #define pll pair<ll, ll>
        #define vpll vector<pll>
        #define eb emplace_back
        #define rep(i, a, b) for (ll i = (ll)(a); i < (b); ++i)
        #define all(xs) xs.begin(), xs.end()

        vll range;
        vpll coord;

        ll dist(ll ax, ll ay, ll bx, ll by) {
            return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        }

        ll touch(ll a, ll b) {
            ll d = dist(coord[a].x, coord[a].y, coord[b].x, coord[b].y);
            return d <= (range[a]+range[b]) * (range[a]+range[b]);
        }

        // ll dist(ll ax, ll ay, ll bx, ll by) {
        //     return abs(ax - bx) + abs(ay - by);
        // }
        
        // ll touch(ll a, ll b) {
        //     ll d = dist(coord[a].x, coord[a].y, coord[b].x, coord[b].y);
        //     if (coord[a].x != coord[b].x and coord[a].y != coord[b].y) 
        //         return d - 2 <= range[a] + range[b];
        //     return d - 1 <= range[a] + range[b];
        // }

        struct DSU {
            DSU(ll n) : parent(n), size(n, 1), mnx(n), mxx(n), mny(n), mxy(n) { 
                iota(all(parent), 0);
                rep(i, 0, n) {
                    mnx[i] = coord[i].x - range[i];
                    mxx[i] = coord[i].x + range[i];
                    mny[i] = coord[i].y - range[i];
                    mxy[i] = coord[i].y + range[i];
                }
            }

            ll setOf(ll x) {
                return parent[x] == x ? x : parent[x] = setOf(parent[x]);
            }

            void mergeSetsOf(ll x, ll y) {
                ll a = setOf(x), b = setOf(y);
                if (size[a] > size[b]) swap(a, b);
                parent[a] = b;
                if (a != b) {
                    size[b] += size[a], size[a] = 0;
                    mnx[b] = min(mnx[b], mnx[a]);
                    mny[b] = min(mny[b], mny[a]);
                    mxx[b] = max(mxx[b], mxx[a]);
                    mxy[b] = max(mxy[b], mxy[a]);
                }
            }

            vll parent, size;
            vll mnx, mxx, mny, mxy;
        };

        signed main() {
            ll m, n, k;
            cin >> m >> n >> k;
            range = vll(k);
            coord = vpll(k);
            rep(i, 0, k) {
                cin >> coord[i].x >> coord[i].y >> range[i];
                // --range[i];
            }
            DSU dsu(k);
            rep(i, 0, k) rep(j, 0, k)
                if (touch(i, j))
                    dsu.mergeSetsOf(i, j);

            rep(i, 0, k) {
                ll a = dsu.setOf(i);
                // cout << "mnx, mxx, mny, mxy: " << dsu.mnx[a] << ' ' << dsu.mxx[a] << ' ' << dsu.mny[a] << ' ' << dsu.mxy[a] << '\n';
                if (dsu.mnx[a] <= 0 and dsu.mxx[a] >= m) {
                    cout << "N\n";
                    return 0;
                }
                if (dsu.mny[a] <= 0 and dsu.mxy[a] >= n) {
                    cout << "N\n";
                    return 0;
                }
                if (dsu.mnx[a] <= 0 and dsu.mny[a] <= 0) {
                    cout << "N\n";
                    return 0;
                }
                if (dsu.mxx[a] >= m and dsu.mxy[a] >= n) {
                    cout << "N\n";
                    return 0;
                }
            }
            cout << "S\n";
        }