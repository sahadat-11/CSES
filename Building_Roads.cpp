//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
  visited[u] = true;
  for(auto v : adj[u]) {
    if(!visited[v]) {
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> component;
  for(int u = 1; u <= n; u++) {
    if(!visited[u]) {
      component.push_back(u);
      dfs(u);
    }
  }
  cout << component.size() - 1 << "\n";
  for(int i = 1; i < component.size(); i++) {
    cout << component[i - 1] << " " << component[i] << "\n";
  }
  return 0;
}
