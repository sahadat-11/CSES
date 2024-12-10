//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long

int binexp(int a, int b) {
    int ans = 1 % mod; a %= mod; if (a < 0) a += mod;
    while(b) {
        if(b & 1) {
            ans = (ans * 1ll * a) % mod;
        }
        a = (a * 1ll * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
   int a, b; cin >> a >> b;
   cout << binexp(a, b) << "\n";
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