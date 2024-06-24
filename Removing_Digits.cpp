//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, inf = 1e9 + 7;
#define int long long
int dp[N];

int func(int i) {
  if(i <= 9) return 1;
  if(dp[i] != -1) return dp[i];
  int ans = inf;
  int x = i;
  while(x) {
    int d = x % 10;
    if(d) {
      ans = min(ans, func(i - d) + 1);
    }
    x /= 10;
  }
  dp[i] = ans;
  return dp[i];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  cout << func(n);
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
#define int long long
int dp[N];

int func(int i) {
  if(i == 0) return 0;
  if(dp[i] != -1) return dp[i];
  int temp = i;
  vector<int> dig;
  while(temp) {
    dig.push_back(temp % 10);
    temp /= 10;
  }
  int ans = 1e9; 
  for(auto u : dig) {
    if(u == 0) continue;
    ans = min(ans, 1 + func(i - u));
  }
  return dp[i] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  cout << func(n);
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
#define ll long long
int dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  dp[0] = 0;
  for(int x = 1; x <= n; x++) {
    int temp = x;
    vector<int> dig;
    while(temp) {
      dig.push_back(temp % 10);
      temp /= 10;
    }
    int ans = inf;
    for(auto u : dig) {
      if(u == 0) continue;
      ans = min(ans, 1 + dp[x - u]);
    }
    dp[x] = ans;
  }
  cout << dp[n];
  return 0; 
}

// https://prnt.sc/nXi2JZplgZYg