//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  if(n == 2 or n == 3) {
    cout << "NO SOLUTION\n";
  }
  else {
    for(int i = 2; i <= n; i += 2) cout << i << " ";
    for(int i = 1; i <= n; i += 2) cout << i << " ";
  }
  return 0;
}