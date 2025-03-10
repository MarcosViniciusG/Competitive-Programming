#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
bool visited[105][105];
pair<int,int>  bfs(int,int,int,int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
	int test,r,c,m,n,w,x,y,t;
	cin >> test;
	for(int t=1;t<=test;t++) {
		cin >> r >> c >> m >> n;
		cin >> w;
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					grid[i][j] = 0;
					visited[i][j] = false;
				}
			}
			while(w--) {
				cin >> x >> y;
				grid[x][y] = -1;
			}
			pair <int,int> ans = bfs(r,c,m,n);
			cout << "Case " << t << ": " << ans.first << " " << ans.second << "\n";
	}
  return 0;
}
pair<int,int> bfs(int r,int c,int m,int n) {
	int dr[8] = {m,m,-m,-m,n,-n,n,-n};
	int dc[8] = {n,-n,n,-n,m,m,-m,-m};
	queue <pair<int,int> > q;
	q.push(make_pair(0,0));
	visited[0][0] = true;
	while(!q.empty()) {
		pair <int,int> p = q.front();
		q.pop();
		set <pair<int,int> > adj;
		for(int k=0;k<8;k++) {
			int i = dr[k] + p.first;
			int j = dc[k] + p.second;
			if(i >= 0 && j >= 0 && i < r && j < c && grid[i][j] != -1) 
				adj.insert(make_pair(i,j));
		}
		for(auto idx : adj) {
			grid[idx.first][idx.second]++;
			if(!visited[idx.first][idx.second]) {
				visited[idx.first][idx.second] = true;
				q.push(make_pair(idx.first,idx.second));
			}
		}
	}
	int even,odd;
	even = odd = 0;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
            cout << grid[i][j] << ' ';
			if((grid[i][j] != -1 && grid[i][j] != 0) || (i == 0 && j == 0)) {
				if(grid[i][j] & 1) odd++;
				else even++;
            }
		}
        cout << '\n';
	}
	return make_pair(even,odd);
}