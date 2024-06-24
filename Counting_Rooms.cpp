//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
bool vis[N][N];
string s[N];
int n, m; 
int dx[] = {0, 0, -1, +1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

bool isValid(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}

void dfs(int x, int y) {
  vis[x][y] = true;
  for(int k = 0; k < 4; k++) {
      int nxt_x = x + dx[k];
      int nxt_y = y + dy[k];
      if(isValid(nxt_x, nxt_y) and s[nxt_x][nxt_y] == '.' and !vis[nxt_x][nxt_y]) {
        dfs(nxt_x, nxt_y);
     }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> s[i];
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(isValid(i, j) and s[i][j] == '.' and !vis[i][j]) {
        cnt++;
        dfs(i, j);
     }
    }
  }
  cout << cnt << "\n";
  return 0;
}