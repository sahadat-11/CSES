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
  int sum = 0, mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(a[i], mx);
  }
  cout << max(2 * mx, sum);
  return 0;
}