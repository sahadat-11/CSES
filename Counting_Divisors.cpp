//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int divs[N];
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 1; i < N; i++) {
     for(int j = i; j < N; j += i) {
       divs[j]++;
     }
  }
  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    cout << divs[x] << "\n";
  }
  return 0;
}