//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
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
  deque<int> dq;
  vector<int> ans;
  for(int i = 0; i < k; i++) {
    while(!dq.empty() and a[i] <= a[dq.back()]) {
       dq.pop_back(); 
    }
    dq.push_back(i);
  }
  ans.push_back(a[dq.front()]);
  for(int i = k; i < n; i++) {
    while(!dq.empty() and dq.front() <= i - k) {
      dq.pop_front();
    }
    while(!dq.empty() and a[i] <= a[dq.back()]) {
       dq.pop_back(); 
    }
    dq.push_back(i);
    ans.push_back(a[dq.front()]);
  }
  for(auto u : ans) {
    cout << u << " ";
  }
  return 0;
}