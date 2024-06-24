 //In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t; cin >> t;
   while(t--) {
     int n; cin >> n;
     vector<int> a(n);
     for(int i = 0; i < n; i++) cin >> a[i];
     sort(a.begin(), a.end());
     set<int> st;
     int ans = 0;
     for(int i = n - 1; i >= 0; i--) {
     	int cur = a[i], cnt = 1;
     	st.insert(a[i]);
     	for(int j = i - 1; j >= 0; j--) {
     	  int temp = (cur * a[j]) / __gcd(cur, a[j]);
     	  if(temp == a[i] or st.find(temp) == st.end()) {
     	  	cnt++;
     	  	if(temp != a[i]) {
     	  		ans = max(ans, cnt);
     	  	}
     	  	cur = temp;
     	  }
     	}
     }
     cout << ans << "\n";
   }
   return 0;
}
