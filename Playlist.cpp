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
  int l = 0, ans = 0;
  map<int, int> mp;
  for(int r = 0; r < n; r++) {
    if(mp.find(a[r]) == mp.end()) {
        mp[a[r]] = r;
    }
    else {
        if(mp[a[r]] >= l) {
            l = mp[a[r]] + 1;
        }
        mp[a[r]] = r;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << "\n";
  return 0;
}