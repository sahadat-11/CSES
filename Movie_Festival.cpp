//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
void solve() {
   int n; cin >> n; int st[n], en[n];
   for(int i = 0; i < n; i++) {
     cin >> st[i] >> en[i];
   } 
   vector<pair<int,int>> v;
   for(int i = 0; i < n; i++) {
   	 v.push_back({en[i], st[i]});
   }
   sort(v.begin(), v.end());
   int cnt = 1;
   int last = v[0].first;
   for(int i = 1; i < n; i++) {
     if(v[i].second >= last) {
     	cnt++;
     	last = v[i].first;
     }
   }
   cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1; 
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
// it can contain same as one end and another start (>=)