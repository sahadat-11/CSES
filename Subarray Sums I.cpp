//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n, k; cin >> n >> k; int a[n];
   for(ll i = 0; i < n; i++) {
   	cin >> a[i];
   }
   ll cnt = 0;
   map<ll, ll> mp;
   mp[0] = 1;
   ll sum = 0;
   for(ll i = 0; i < n; i++) {
   	 sum += a[i];
   	 cnt += mp[sum - k];
   	 mp[sum]++;
   }
   cout << cnt << "\n";
   return 0;
}
//https://prnt.sc/q7ynFLvLrp-D
//https://prnt.sc/dPbQO_I3BHtG
//https://prnt.sc/EZHA0d2PBBJQ