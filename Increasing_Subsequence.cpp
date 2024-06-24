//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7, inf = 1e9 + 7;
#define int long long
int dp[N], a[N];
int t[4 * N];

int merge(int l, int r) { // change this
  return max(l, r);
}

int query(int n, int b, int e, int i, int j) { //(i, j) = range
  if(b > j or e < i) return -inf; // totally out
  if(b >= i and e <= j) {// totally in
    return t[n];
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = (b + e) / 2;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void update(int n, int b, int e, int i, int x) {
  if(b > i or e < i) return;
  if(b >= i and e <= i) {
    t[n] = max(t[n], x);
    return;
  }
  int l = 2 * n, r = 2 * n + 1;
  int mid = (b + e) / 2;
  update(l, b, mid, i, x);
  update(r, mid + 1, e, i, x);
  t[n] = merge(t[l], t[r]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  set<int> st;
  for(int i = 1; i <= n; i++) {
    st.insert(a[i]);
  }
  int ind = 1;
  map<int, int> mp;
  for(auto x : st) {
    if(!mp[x]) {
      mp[x] = ind;
      ind++;
    }
  }
  for(int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
    // for(int j = 1; j <= i; j++) {
    //   if(a[j] < a[i]) {
    //     dp[i] = max(dp[i], 1 + dp[j]);
    //   }
    // }
    int mx = query(1, 1, N, 1, a[i] - 1);
    mx++;
    dp[i] = max(dp[i], mx);
    update(1, 1, N, a[i], dp[i]);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  
  return 0;
}

// O(N * log(N))