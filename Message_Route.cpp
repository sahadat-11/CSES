//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
#define int long long
const int N = 2e5 + 7;
vector<int> g[N];
vector<int> dis(N, inf);
int par[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m; // n = node m = edge
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> qe;
  qe.push(1); // source
  dis[1] = 1;

  while(!qe.empty()) {
    int u = qe.front();
    qe.pop();
    for(auto v : g[u]) {
      if(dis[u] + 1 < dis[v]) {
        qe.push(v);
        dis[v] = dis[u] + 1;
        par[v] = u;
      }
    }
  }
  if(dis[n] == inf) {
    cout << "IMPOSSIBLE"; return 0;
  }
  cout << dis[n] << "\n";
  vector<int> path;
  while(n != 0) {
    path.push_back(n);
    n = par[n];
  }
  reverse(path.begin(), path.end());
  for(auto u : path) cout << u << " ";
  return 0;
}


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
