//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7, inf = 1e9;
vector<int> adj[N];
int par[N];
int main() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
    vector<int> dis(n + 1, inf);
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v : adj[u]) {
        if(dis[u] + 1 < dis[v]) {
          dis[v] = dis[u] + 1;
          q.push(v);
          par[v] = u;
        }
      }
    }
    //for(int i = 1; i <= n; i++) cout << par[i] << " ";
    if(dis[n] == inf) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    vector<int> path;
    while(n != 1) {
      path.push_back(n);
      n = par[n];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(auto u : path) cout << u << " ";
  return 0;
}