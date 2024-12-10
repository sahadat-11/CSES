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
    int x, y; cin >> x >> y;
    p.push_back({x, y});
  }
  sort(p.begin(), p.end());
  int sum = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    sum += p[i].first;
    ans += (p[i].second - sum);
  }
  cout << ans << "\n";
  return 0;
}