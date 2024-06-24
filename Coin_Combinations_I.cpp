//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, mod = 1e9 + 7;
int dp[X];
int n, required;
int coins[N];

int func(int x) {
  if(x > required) return 0;
  if(x == required) return 1;
  if(dp[x] != -1) return dp[x];
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += func(x + coins[i]);
    if(ans >= mod) ans -= mod;
  }
  dp[x] = ans;
  return dp[x];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> required;
  for(int i = 1; i <= n; i++) {
    cin >> coins[i];
  }
  int ans = func(0);
  cout << ans << "\n";
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, mod = 1e9 + 7;
int dp[X];
int n, required;
int coins[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //memset(dp, -1, sizeof dp);
  cin >> n >> required;
  for(int i = 1; i <= n; i++) {
    cin >> coins[i];
  }
  //int ans = func(0);
  dp[required] = 1;
  for(int sum = required; sum >= 0; sum--) {
    for(int i = 1; i <= n; i++) {
      if(sum + coins[i] <= required)
      dp[sum] += dp[sum + coins[i]];
      dp[sum] %= mod;
    }
  }
  // for(int i = 0; i <= required; i++) {
  //   cout << dp[i] << " ";
  // }
  cout << dp[0] << "\n";
  return 0;
}



// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 105, X = 1e6 + 7, mod = 1e9 + 7;
// int n, x, a[N], dp[X];
// int f(int sum) {
//   if(sum == 0) return 1; // supose x = 0; that represent by 1 ways;
//   int &ans = dp[sum];
//   if(ans != -1) return ans;
//   ans = 0;
//   for(int i = 1; i <= n; i++) {
//     if(sum >= a[i]) { 
//       ans += f(sum - a[i]);
//       //ans %= mod;
//       if(ans >= mod) ans -= mod;
//     }
//   }
//   return ans;
// }
// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> x;
//   for(int i = 1; i <= n; i++) cin >> a[i];
//   memset(dp, -1, sizeof dp);
//   cout << f(x);
//   return 0;
// }
// // https://prnt.sc/vBHNWrrL-FKx

// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 105, X = 1e6 + 7, mod = 1e9 + 7;
// int n, x, a[N], dp[X];
// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> x;
//   for(int i = 1; i <= n; i++) cin >> a[i];
//   dp[0] = 1;
//   for(int sum = 1; sum <= x; sum++) {
//     int &ans = dp[sum];
//     ans = 0;
//     for(int i = 1; i <= n; i++) {
//       if(sum >= a[i]) {
//         ans += dp[sum - a[i]];
//         ans %= mod;
//       }
//     }
//   }
//   cout << dp[x];
//   return 0;
// }
