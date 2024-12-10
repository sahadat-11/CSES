//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  } 
  vector<pair<int, int>> v;
  for(int i = 1; i <= n ; i++) {
    v.push_back({a[i], i});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n - 3; i++) {
     for(int j = i + 1; j < n - 2; j++) {
        int l = j + 1, r = n - 1;
        while(l < r) {
           ll sum = v[i].first + v[j].first + v[l].first + v[r].first;
           if(sum > x) r--;
           else if(sum < x) l++;
           else if(sum == x and i != l and i != r and j != l and j != r){
             cout << v[i].second << " " << v[j].second << " " << v[l].second << " " << v[r].second;
             return 0;
         }
       }
     }
  }
  cout << "IMPOSSIBLE";
  return 0;
}

// O(N * N * N)