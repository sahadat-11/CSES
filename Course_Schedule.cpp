//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int indeg[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  vector<int> zero;
  for(int i = 1; i <= n; i++) {
    if(indeg[i] == 0) zero.push_back(i);
  }
  vector<int> ans;
  while(ans.size() < n) {
    if(zero.empty()) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    int cur = zero.back();
    vis[cur] = true;
    zero.pop_back();
    ans.push_back(cur);
    for(auto v : adj[cur]) {
      indeg[v]--;
      if(!vis[v] and indeg[v] == 0) {
        zero.push_back(v);
        vis[v] = true;
      }
    }
  }
  for(auto u : ans) cout << u << ' ';
  return 0;
} 
// optimize O(V + E)


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int indeg[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    indeg[v]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(indeg[i] == 0) q.push(i);
  }
  vector<int> ans;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    ans.push_back(cur);
    for(auto v : adj[cur]) {
      indeg[v]--;
      if(indeg[v] == 0) q.push(v);
    }
  }
  if(ans.size() != n) cout << "IMPOSSIBLE";
  else for(auto u : ans) cout << u << " ";
  return 0;
} 
// optimize O(V + E)
