//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 1e9 + 7;
#define int long long
int dp[N][N * (N + 1) / 2];
int n;

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

int Inverse(int n) {
	return binexp(2, mod - 2);
}

int func(int i, int s) {
  if(i == n + 1) return s == 0;
  int &ans = dp[i][s];
  if(ans != -1) return ans;
  ans = func(i + 1, s);
  if(s >= i) {
  	ans += func(i + 1, s - i);
  	ans %= mod;
  } 
  return dp[i][s] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  int total = n * (n + 1) / 2;
  if(total % 2) {
  	cout << "0\n";
  }
  else {
  	cout << (func(1, total / 2) * Inverse(2)) % mod;
  }
  return 0;
}