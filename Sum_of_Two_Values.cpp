//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x; int a[n + 1];
  for(int i = 1; i <= n; i++) cin >> a[i];
  vector<pair<int, int>> v;
  for(int i = 1; i <= n; i++) {
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  int l = 0, r = n - 1;
  while(l < r) {
     int sum = v[l].first + v[r].first;
     if(sum > x) r--;
     else if(sum < x) l++;
     else {
       cout << v[l].second << " " << v[r].second << "\n";
       return 0;
     }
  }
  cout << "IMPOSSIBLE\n";
  return 0; 
}