//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0, mx = a[0];
  for(int i = 1; i < n; i++) {
    cnt += max(0ll, mx - a[i]);
    mx = max(mx, a[i]);
  }
  cout << cnt << "\n";
  return 0;
}