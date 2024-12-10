//In The Name of ALLAH
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  o_set<pair<int, int>> st;
  vector<int> ans;
  for(int i = 0; i < k; i++) {
    st.insert({a[i], i});
  }
  auto mid = (st.find_by_order((k - 1) / 2));
  ans.push_back(mid->first);
  for(int i = k; i < n; i++) {
    st.erase(st.lower_bound({a[i - k], i - k}));
    st.insert({a[i], i});
    auto mid = (st.find_by_order((k - 1) / 2));
    ans.push_back(mid->first);
  }
  for(auto u : ans) {
    cout << u << " ";
  }
  return 0;
}
// https://www.geeksforgeeks.org/median-of-sliding-window-in-an-array/
// https://cses.fi/problemset/task/1076/