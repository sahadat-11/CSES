//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long

int binexp(int a, int b, int m) {
    int ans = 1 % m; a %= m; if (a < 0) a += m;
    while(b) {
        if(b & 1) {
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return ans;
}

void solve() {
   int a, b, c; cin >> a >> b >> c;
   int x = binexp(b, c, mod - 1);
   int ans = binexp(a, x, mod);
   cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1; 
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}