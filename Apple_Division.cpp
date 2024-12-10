//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> subsets(vector<int>& nums) {
  int n = nums.size();
  int sub_cnt = (1 << n); // (2^n);
  vector < vector < int >> all_subsets;
  for (int mask = 0; mask < sub_cnt - 1; mask++) {
    vector < int > subset;
    for (int i = 0; i < n; i++) {
      if (mask & (1ll << i)) {
        subset.push_back(nums[i]);
      }
    }
    all_subsets.push_back(subset);
  }
  return all_subsets;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector < int > a(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  int ans = 1e18;
  auto all_subsets = subsets(a);
  for (auto subset: all_subsets) {
    for (int ele: subset) {
      sum1 += ele;
    }
    int sum2 = total - sum1;
    ans = min(ans, abs(sum2 - sum1));
  }
  cout << ans << "\n";
  return 0;
}