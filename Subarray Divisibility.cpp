//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int,int> mp;
  mp[0] = 1; // if the sum is 0;
  int sum = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    cnt += mp[(sum % n + n) % n];
    mp[(sum % n + n) % n]++;
  }
  cout << cnt << "\n";
  return 0;
}
