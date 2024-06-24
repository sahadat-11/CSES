//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, inf = 1e9;
int n, x, a[N], dp[N][X];
int f(int i, int sum) {
  if(sum > x) return inf;
  if(i == n + 1) {
    if(sum == x) return 0;
    return inf;
  }
  int &ans = dp[i][sum];
  if(ans != -1) return ans;
  ans = f(i + 1, sum);
  ans = min(ans, 1 + f(i, sum + a[i])); // for multiple taken;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for(int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  int ans = f(1, 0);
  if(ans >= inf) cout << -1;
  else cout << ans << "\n";
  return 0;
}

// memory complexity high


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, inf = 1e9 + 7;
int dp[N][X];
int n, required;
int coins[N];

int func(int i, int x) {
  if(x > required) return inf;
  if(i == n + 1) {
    if(x == required) return 0;
    return inf;
  }
  if(dp[i][x] != -1) return dp[i][x];
  int ans = func(i + 1, x); // not take this
  ans = min(ans, 1 + func(i, x + coins[i])); // take this
  dp[i][x] = ans;
  return dp[i][x];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> required;
  for(int i = 1; i <= n; i++) {
    cin >> coins[i];
  }
  int ans = func(1, 0);
  if(ans == inf) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, inf = 1e9;
int n, x, a[N], dp[N][X];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for(int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0] = 0;
  for(int sum = 1; sum <= x; sum++) {
    dp[0][sum] = inf;
  }
  for(int i = 1; i <= n; i++) {
    for(int sum = 1; sum <= x; sum++) {
      dp[i][sum] = dp[i - 1][sum];
      if(sum >= a[i]) dp[i][sum] = min(dp[i][sum], 1 + dp[i][sum - a[i]]);
    }
  }
  if(dp[n][x] >= inf) cout << -1;
  else cout << dp[n][x] << "\n";
  return 0;
}
// 400 mb

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 105, X = 1e6 + 7, inf = 1e9;
int n, x, a[N], dp[2][X];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for(int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0] = 0;
  for(int sum = 1; sum <= x; sum++) {
    dp[0][sum] = inf;
  }
  for(int i = 1; i <= n; i++) {
    for(int sum = 1; sum <= x; sum++) {
      dp[1][sum] = dp[0][sum];
      if(sum >= a[i]) dp[1][sum] = min(dp[1][sum], 1 + dp[1][sum - a[i]]);
    }
    for(int sum = 1; sum <= x; sum++) {
      dp[0][sum] = dp[1][sum];
    }
  }
  if(dp[0][x] >= inf) cout << -1;
  else cout << dp[0][x] << "\n";
  return 0;
}
// 8 mb
// https://prnt.sc/cLJ7CNIeknTG
//every state depend current and previous state;
//0 for previous state and 1 for current state;
//end of every state this state was previous state;
