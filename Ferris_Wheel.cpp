//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, x; cin >> n >> x; ll a[n];
  for(ll i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 0, r = n - 1, cnt = 0;
  while(l <= r) {
    ll sum = a[l] + a[r];
    if(sum > x) {
      cnt++; r--;
    }
    else {
      cnt++;
      l++; r--;
    }
  }
  cout << cnt << "\n";
  return 0;
}