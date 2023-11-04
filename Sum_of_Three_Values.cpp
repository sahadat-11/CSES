//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x; int a[n + 1];
  for(int i = 1; i <= n ; i++) cin >> a[i];
  vector<pair<int,int>> v;
  for(int i = 1; i <= n ; i++) {
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n - 2; i++) {
     int l = i + 1, r = n - 1;
     while(l < r) {
       ll sum = v[i].first + v[l].first + v[r].first;
       if(sum > x) r--;
       else if(sum < x) l++;
       else if(sum == x and i != l and i != r){
         cout << v[i].second << " " << v[l].second << " " << v[r].second;
         return 0;
       }
     }
  }
  cout << "IMPOSSIBLE";
  return 0;
}