//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
string s[N];
bool vis[N][N];
int di[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dj[] = {+1, 0, -1, 0, +1, -1, -1, +1};
int n, m;
bool is_valid(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}
void dfs(int i, int j) {
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int nxt_i = i + di[k];
    int nxt_j = j + dj[k];
    if (is_valid(nxt_i, nxt_j) and s[nxt_i][nxt_j] == '.' and !vis[nxt_i][nxt_j]) {
      dfs(nxt_i, nxt_j);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int components = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.' and !vis[i][j]) {
        dfs(i, j);
        components++;
      }
    }
  }
  cout << components << '\n';
  return 0;
}
