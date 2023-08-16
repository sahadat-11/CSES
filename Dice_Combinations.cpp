//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define ll long long
ll dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  ll n; cin >> n;
  dp[0] = 1;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= min(1ll*6, i); j++) {
      dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }
  cout << dp[n] << "\n";
  return 0;
} 

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define ll long long
ll dp[N];
ll cnt(ll n) {
  if(n < 0) return 0;
  if(n == 0) return 1;
  if(dp[n] != -1) return dp[n];
  dp[n] = (cnt(n - 1) + cnt(n - 2))% mod;
  dp[n] = (dp[n] + cnt(n - 3)) % mod; 
  dp[n] = (dp[n] + cnt(n - 4)) % mod; 
  dp[n] = (dp[n] + cnt(n - 5)) % mod; 
  dp[n] = (dp[n] + cnt(n - 6)) % mod; 
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  ll n; cin >> n;
  cout << cnt(n);
  return 0;
}