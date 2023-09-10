//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
string s[N];
int n, dp[N][N]; 
int f(int i, int j) {
  if(i >= n or j >= n) return 0;
  if(s[i][j] == '*') return 0;
  if(i == n - 1 and j == n - 1) return 1;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = f(i, j + 1); // go right
  ans += f(i + 1, j); // go down
  ans %= mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cout << f(0, 0);
  return 0;
}