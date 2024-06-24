// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 7, mod = 1e9 + 7;
// #define int long long
// int dp[N];

// struct seg {
//   int l, r, reward;
// }a[N];

// bool cmp(seg x, seg y) {
// 	return x.r < y.r;
// }

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   int n; cin >> n;
//   for(int i = 1; i <= n; i++) {
//   	cin >> a[i].l >> a[i].r >> a[i].reward;
//   }
//   sort(a + 1, a + n + 1, cmp);
//   for(int i = 1; i <= n; i++) {
//   	dp[i] = a[i].reward;
//   	for(int j = i - 1; j >= 1; j--) {
//       if(a[j].r < a[i].l) {
//       	dp[i] = max(dp[i], dp[j] + a[i].reward);
//       }
//   	}
//   }
//   int ans = 0;
//   for(int i = 1; i <= n; i++) {
//   	ans = max(ans, dp[i]);
//   }
//   cout << ans << "\n";
//   return 0;
// }
// // O(N * N)


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
#define int long long
int dp[N], pre_mx[N];

struct seg {
  int l, r, reward;
}a[N];

bool cmp(seg x, seg y) {
	return x.r < y.r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
  	cin >> a[i].l >> a[i].r >> a[i].reward;
  }
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; i++) {
  	dp[i] = a[i].reward;
  	int mx = 0;
  	// for(int j = i - 1; j >= 1; j--) {
   //    if(a[j].r < a[i].l) {
   //    	mx = max(mx, dp[j]);
   //    }
  	// }
  	// int L = 1, R = i - 1, j = 0;
  	// while(L <= R) {
  	//   int mid = (L + R) >> 1;
  	//   if(a[mid].r < a[i].l) {
   //      j = mid;
   //      L = mid + 1;
  	//   }
  	//   else {
  	//   	R = mid - 1;
  	//   }
  	// }
  	int j = lower_bound(a, a + n + 1, a[i].l ) - a;
  	mx = pre_mx[j];
  	mx += a[i].reward;
  	dp[i] = max(dp[i], mx);
  	pre_mx[i] = max(pre_mx[i - 1], dp[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
  	ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}
// O(N * log(N))