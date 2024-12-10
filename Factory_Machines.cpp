//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t; cin >> n >> t;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 1, r = 1e18, ans = 0;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int x = 0;
    for(int i = 0; i < n; i++) {
      x += (mid / a[i]);
      if(x >= t) break;
    }
    if(x >= t) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, total;
bool isvalid(ll a[], ll t) {
	ll cnt = 0;
	for(int i = 0; i < n; i++) {
		cnt += (t / a[i]);
		if(cnt >= total) break;
	}
	return cnt >= total;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> total; ll a[n];
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
