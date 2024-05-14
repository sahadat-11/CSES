//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005, inf = 1e9;
string s[N];
bool vis[N][N];
int dx[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dy[] = {+1, 0, -1, 0, +1, -1, -1, +1};
int n, m;
int dis[N][N];
pair<int,int> par[N][N];
bool is_valid(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  pair<int, int> start, end;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'A') start = make_pair(i, j);
      if(s[i][j] == 'B') end = make_pair(i, j);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dis[i][j] = inf;
    }
  }

  queue<pair<int, int>> q;
  q.push(start);
  dis[start.first][start.second] = 0;

  while(!q.empty()) {
    auto [x, y] = q.front(); // x = first, y = second
    q.pop();

    for(int k = 0; k < 4; k++) {
      int nxt_x = x + dx[k];
      int nxt_y = y + dy[k];
      if(is_valid(nxt_x, nxt_y) and s[nxt_x][nxt_y] != '#' and dis[x][y] + 1 < dis[nxt_x][nxt_y]) {
        dis[nxt_x][nxt_y] = dis[x][y] + 1; 
        par[nxt_x][nxt_y] = make_pair(x, y);
        q.push(make_pair(nxt_x, nxt_y));
      }
    }
  }

  int ans = dis[end.first][end.second];
  if(ans == inf) cout << "NO\n";
  else {
    cout << "YES\n";
    cout << ans << "\n";
    vector<pair<int, int>> path;
    pair<int, int> cur = end;
    while(cur != start) {
      path.push_back(cur);
      cur = par[cur.first][cur.second];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for(int i = 1; i < path.size(); i++) {
      int x = path[i].first - path[i - 1].first;
      int y = path[i].second - path[i - 1].second;
      if(x == 1) cout << 'D';
      else if(x == -1) cout << 'U';
      else if(y == 1) cout << 'R';
      else if(y == -1) cout << 'L';
    }
  }
}