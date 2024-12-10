//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> p;
  for(int i = 0; i < n; i++) {
    int st, en; cin >> st >> en;
    p.push_back({st, 1});
    p.push_back({en, -1});
  }
  sort(p.begin(), p.end());
  int ans = 0, cur = 0;
  for(int i = 0; i < 2 * n; i++) {
    cur += p[i].second;
    ans = max(ans, cur);
  }
  cout << ans << "\n";
  return 0;
}