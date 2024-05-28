//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
bool isvalid(ll a[], ll t) {
	ll sum = 0, cnt = 1;// if the total sum is less than t;
	for(int i = 0; i < n; i++) {
		if(a[i] > t) return 0;
		if(a[i] + sum > t) {
			cnt++;
			sum = a[i];
		}
		else sum += a[i];
	}
	return cnt <= k;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k; ll a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  ll l = 0, h = 1e18, ans = 0;
  while(l <= h) {
  	ll mid = l + (h - l) / 2;
  	if(isvalid(a, mid)) {
  		ans = mid;
  		h = mid - 1;
  	}
  	else l = mid + 1;
  }
  cout << ans << "\n";
  return 0;
}
