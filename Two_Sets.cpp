//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int f = true;
  vector<int> v1, v2;
  while(n) {
    if(f) {
        v1.push_back(n);
        n--;
        if(n == 0) break;
        v2.push_back(n);
        if(n == 0) break;
        n--;
    }
    else {
        v2.push_back(n);
        n--;
        if(n == 0) break;
        v1.push_back(n);
        if(n == 0) break;
        n--;
    }
    f ^= 1;
  }
  int sum1 = 0, sum2 = 0;
  for(auto u : v1) sum1 += u;
  for(auto u : v2) sum2 += u;
  if(sum1 == sum2) {
    cout << "YES\n";
    cout << v1.size() << "\n";
    for(auto u : v1) cout << u << " "; cout << "\n";
    cout << v2.size() << "\n";
    for(auto u : v2) cout << u << " "; cout << "\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}