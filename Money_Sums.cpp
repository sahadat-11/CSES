//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, MX_SUM = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int n;
int a[N];
bool dp[N][MX_SUM];
bool vis[N][MX_SUM];

int func(int i, int s) {
  if(i == n + 1) return s == 0;
  if(vis[i][s]) return dp[i][s];
  vis[i][s] = true;
  bool is_posible = func(i + 1, s);
  if(s >= a[i]) is_posible |= func(i + 1, s - a[i]);
  return dp[i][s] = is_posible;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
  	cin >> a[i];
  }
  vector<int> ans;
  for(int s = 1; s < MX_SUM; s++) {
  	if(func(1, s)) {
  	  ans.push_back(s);
  	}
  }
  cout << (int)ans.size() << "\n";
  for(auto u : ans) {
  	cout << u << " ";
  }
  cout << "\n";
  return 0;
}
