// // //In The Name of ALLAH
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N = 1e3 + 7, mod = 1e9 + 7;
// // string s[N];
// // int n, dp[N][N]; 
// // int f(int i, int j) {
// //   if(i >= n or j >= n) return 0;
// //   if(s[i][j] == '*') return 0;
// //   if(i == n - 1 and j == n - 1) return 1;
// //   int &ans = dp[i][j];
// //   if(ans != -1) return ans;
// //   ans = f(i, j + 1); // go right
// //   ans += f(i + 1, j); // go down
// //   ans %= mod;
// //   return ans;
// // }
// // int main() {
// //   ios_base::sync_with_stdio(0);
// //   cin.tie(0);
// //   memset(dp, -1, sizeof dp);
// //   cin >> n;
// //   for(int i = 0; i < n; i++) {
// //     cin >> s[i];
// //   }
// //   cout << f(0, 0);
// //   return 0;
// // }


// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 7, mod = 1e9 + 7;
// #define int long long
// int dp[N][N], n;
// char s[N][N];

// int func(int i, int j) {
//   if(i >= n or j >= n) return 0;
//   if(s[i][j] == '*') return 0;
//   if(i == n - 1 and j == n - 1) {
//     return 1;
//   }
//   if(dp[i][j] != -1) return dp[i][j];
//   int ans = 0;
//   if(s[i][j + 1] != '*') {
//     ans = (ans + func(i, j + 1)) % mod;
//   }
//   if(s[i + 1][j] != '*') {
//     ans = (ans + func(i + 1, j)) % mod;
//   }
//   dp[i][j] = ans;
//   return dp[i][j];
// }

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   memset(dp, -1, sizeof dp);
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       cin >> s[i][j];
//     }
//   }
//   cout << func(0, 0);
//   return 0;
// }


// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 7, mod = 1e9 + 7;
// #define int long long
// int dp[N][N], cnt, n;
// char s[N][N];

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       cin >> s[i][j];
//     }
//   }
//   if(s[n - 1][n - 1] != '*') {
//     dp[n - 1][n - 1] = 1;
//   }
//   for(int i = n - 1; i >= 0; i--) {
//     for(int j = n - 1; j >= 0; j--) {
//       if(i == n - 1 and j == n - 1) continue;
//       int ans = 0;
//       if(s[i][j] == '*') dp[i][j] = 0;
//       if(s[i][j + 1] != '*') {
//         ans = (ans + dp[i][j + 1]) % mod;
//       }
//       if(s[i + 1][j] != '*') {
//         ans = (ans + dp[i + 1][j]) % mod;
//       }
//       if(s[i][j] == '*') ans = 0;
//       dp[i][j] = ans;
//     }
//   }
//   cout << dp[0][0] << "\n";
//   return 0;
// }


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
#define int long long
int dp[N][N], cnt, n;
char s[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }
  if(s[0][0] != '*') {
    dp[0][0] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0 and j == 0) continue;
      int ans = 0;
      if(s[i][j] == '*') dp[i][j] = 0;
      if(j - 1 >= 0 and s[i][j - 1] != '*') {
        ans = (ans + dp[i][j - 1]) % mod;
      }
      if(i - 1 >= 0 and s[i - 1][j] != '*') {
        ans = (ans + dp[i - 1][j]) % mod;
      }
      if(s[i][j] == '*') ans = 0;
      dp[i][j] = ans;
    }
  }
  cout << dp[0][0] << "\n";
  return 0;
}