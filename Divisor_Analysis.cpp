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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int num_of_div = 1, sum_of_div = 1, pro_of_div = 1, div_cnt2 = 1;
  while(n--) {
    int p, power_of_p; cin >> p >> power_of_p;
    num_of_div = (num_of_div * (power_of_p + 1)) % mod; 
    sum_of_div = sum_of_div * (binexp(p, power_of_p + 1) - 1) % mod * binexp(p - 1, mod - 2) % mod;
    pro_of_div = binexp(pro_of_div, power_of_p + 1) * binexp(binexp(p, (power_of_p * (power_of_p + 1) / 2)), div_cnt2) % mod;
    div_cnt2 = (div_cnt2 * (power_of_p + 1)) % (mod - 1);
  }
  cout << num_of_div << " " << sum_of_div << " " << pro_of_div << "\n";
  return 0;
}