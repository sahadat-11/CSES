//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define int long long
int dp[N];

int func(int i) {
  if(i < 0) return 0;
  if(i == 0) return 1;
  if(dp[i] != -1) return dp[i];
  dp[i] = (func(i - 1) + func(i - 2))% mod;
  dp[i] = (dp[i] + func(i - 3)) % mod; 
  dp[i] = (dp[i] + func(i - 4)) % mod; 
  dp[i] = (dp[i] + func(i - 5)) % mod; 
  dp[i] = (dp[i] + func(i - 6)) % mod; 
  return dp[i];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  int n; cin >> n;
  cout << func(n);
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define int long long
int dp[N];

int func(int i) {
  if(i < 0) return 0;
  if(i == 0) return 1;
  if(dp[i] != -1) return dp[i];
  int ans = 0;
  for(int j = 1; j <= 6; j++) {
    ans += func(i - j);
    ans %= mod;
  }
  dp[i] = ans;
  return dp[i];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  cout << func(n) << "\n";
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define int long long
int dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
  dp[4] = 8, dp[5] = 16, dp[6] = 32;
  for(int i = 7; i <= n; i++) {
    int ans = 0;
    for(int j = 1; j <= 6; j++) {
      ans = (ans + dp[i - j]) % mod;
    }
    dp[i] = ans;
  }
  cout << dp[n];
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define int long long
int dp[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  int n; cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= min(1ll*6, i); j++) {
      dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }
  cout << dp[n] << "\n";
  return 0;
}

// https://prnt.sc/ObcqJFpNa62i