//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
#define ll long long
int dp[N];
int rec(int i) {
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
    ans = min(ans, 1 + rec(i - u));
  }
  return dp[i] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n; cin >> n;
  cout << rec(n);
  return 0;
}
// https://prnt.sc/srnX931A99EH

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


