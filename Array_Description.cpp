//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 105, mod = 1e9 + 7;
#define int long long
int dp[N][M], a[N];
int n, m;
 
int func(int i, int last) {
  if(i == n + 1) return 1;
  int &ans = dp[i][last];
  if(ans != -1) return ans;
  int l = 1, r = m;
  if(a[i] > 0) {
  	l = r = a[i];
  }
  ans = 0;
  for(int cur = l; cur <= r; cur++) {
  	if(i == 1 or abs(last - cur) <= 1) {
  	  ans += func(i + 1, cur);
  	  ans %= mod;
  	}
  }
  return ans;
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << func(1, 0);
  return 0;
}
// O(N * M * M) // O(10^9)

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 105, mod = 1e9 + 7;
#define int long long
int dp[N][M], a[N];
int n, m;

int func(int i, int last) {
  if(i == n + 1) return 1;
  int &ans = dp[i][last];
  if(ans != -1) return ans;
  int l, r;
  if(a[i] > 0) {
  	l = r = a[i];
  }
  else {
  	if(i == 1) {
  	  l = 1, r = m;
  	}
  	else {
      l = max(1ll, last - 1);
  	  r = min(m, last + 1);
  	}
  }
  ans = 0;
  for(int cur = l; cur <= r; cur++) {
  	if(i == 1 or abs(last - cur) <= 1) {
  	  ans += func(i + 1, cur);
  	  ans %= mod;
  	}
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << func(1, 0);
  return 0;
}
// O(N * M) // O(10^7)