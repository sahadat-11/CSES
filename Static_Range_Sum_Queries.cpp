//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
#define int long long
int pre[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) { // 1 based index
  	pre[i] = pre[i - 1] + a[i];
  }
  while(q--) {
    int l, r; cin >> l >> r;
    cout << pre[r] - pre[l - 1] << "\n";
  }
  return 0;
}