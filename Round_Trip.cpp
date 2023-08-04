//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int> adj[N], path;
int col[N], par[N];
bool cycle;

void dfs(int u) {
  if(cycle) return;
  col[u] = 1; // dfs call hole 1 // 1 = red
  for(auto v : adj[u]) {
    if(cycle) return;
    if(col[v] == 0) {
      par[v] = u;
      dfs(v); // dfs call akhono na hole 0 // 0 = white
    } 
    else if(col[v] == 1) {
      cycle = true;
      int st = u;
      while(u != v) {
        path.push_back(u);
        u = par[u];
      }
      path.push_back(v);
      path.push_back(st);
      reverse(path.begin(), path.end());
      return;
    }
  }
  col[u] = 2; // dfs er kaj end hole; 2 = blue;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }
  cycle = false;
  for(int i = 1; i <= n; i++) {
    if(col[i] == 0) dfs(i);
  }
  if(!cycle) cout << "IMPOSSIBLE";
  else {
  cout << path.size() << "\n";
  for(auto u : path) cout << u << " ";
  }
  return 0;
}
// https://prnt.sc/otu_v6MgqSer 
// https://prnt.sc/_Glf4yBY9CTA