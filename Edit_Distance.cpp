//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 1e9;
string a, b;
int n, m;
// min operations to convert a[i .....(n-1)] to v[j.... (n-1)];
int dp[N][N];
int f(int i, int j) {
	if(i == n and j == m) return 0;
	if(i == n) return m - j;
	if(j == m) return n - i;
	int &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = inf;
	// if(a[i] == b[i]) 
	if(a[i] == b[j]) {
	  ans = min(ans, f(i + 1, j + 1));
	}
	// replace a[i];
    ans = min(ans, 1 + f(i + 1, j + 1));

    // add new char;
	ans = min(ans, 1 + f(i, j + 1));

	// remove a[i];
	ans = min(ans, 1 + f(i + 1, j));
	return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  n = a.size(); m = b.size();
  cout << f(0, 0);
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
string a, b;
int n, m;
int dp[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  n = a.size(); m = b.size();
  for(int i = 0; i <= n; i++) {
  	for(int j = 0; j <= m; j++) {
       if(i == 0) dp[i][j] = j;
       else if(j == 0) dp[i][j] = i;
       else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
       else {
       	 dp[i][j] = 1 + min(dp[i - 1][j - 1], (min(dp[i][j - 1], dp[i - 1][j])));
       }
  	}
  }
  cout << dp[n][m];
  return 0;
}

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 1e9;
string a, b;
int n, m;
int dp[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  n = a.size(); m = b.size();
 // memset(dp, -1, sizeof dp);
  for(int i = 1; i <= n; i++) {
  	dp[i][0] = i;
  }

  for(int j = 1; j <= m; j++) {
  	dp[0][j] = j;
  }
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
  	for(int j = 1; j <= m; j++) {
       if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
       else {
       	 dp[i][j] = 1 + min(dp[i - 1][j - 1], (min(dp[i][j - 1], dp[i - 1][j])));
       }
  	}
  }
  cout << dp[n][m];
  return 0;
}



//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 1e9 + 7;
#define int long long
int dp[N][N];
int n, m;
string a, b;

int func(int i, int j) {
  if(i == n) {
    if(j == m) return 0;
    return m - j;
  }
  if(j == m) {
    if(i == n) return 0;
    return n - i;
  }
  if(dp[i][j] != -1) return dp[i][j];
  int ans = inf;
  if(a[i] == b[j]) {
    ans = min(ans, func(i + 1, j + 1));
  }
  ans = min(ans, func(i + 1, j + 1) + 1);

  ans = min(ans, func(i, j + 1) + 1);

  ans = min(ans, func(i + 1, j) + 1);
  
  dp[i][j] = ans;

  return dp[i][j];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> a >> b;
  n = a.size(), m = b.size();
  cout << func(0, 0);
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 1e9;
string a, b;
int n, m;
// min operations to convert a[i .....(n-1)] to v[j.... (n-1)];
int dp[N][N];
int f(int i, int j) {
 if(i == n) {
   if(j == m) {
      return 0;
   }
   return m - j;
 }
 if(j == m) {
   return n - i;
 }
 int &ans = dp[i][j];
 if(ans != -1) return ans;
 ans = inf;
 // if(a[i] == b[i]) 
 if(a[i] == b[j]) {
   ans = min(ans, f(i + 1, j + 1));
 }
 // replace a[i];
    ans = min(ans, 1 + f(i + 1, j + 1));

    // add new char;
 ans = min(ans, 1 + f(i, j + 1));

 // remove a[i];
 ans = min(ans, 1 + f(i + 1, j));
 return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  n = a.size(); m = b.size();
  cout << f(0, 0);
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5005, inf = 1e9 + 7;
#define int long long
int dp[N][N];
int n, m;
string a, b;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  n = a.size(), m = b.size();
  for(int i = 0; i <= n; i++) {
   dp[i][m] = n - i;
  }
  for(int i = 0; i <= m; i++) {
   dp[n][i] = m - i;
  }
  for(int i = n - 1; i >= 0; i--) {
    for(int j = m - 1; j >= 0; j--) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i + 1][j + 1];
      }
      else {
        dp[i][j] = 1 + min(min(dp[i + 1][j + 1], dp[i][j + 1]), dp[i + 1][j]);
      }
    }
  }

  cout << dp[0][0] << "\n";
  return 0;
}
