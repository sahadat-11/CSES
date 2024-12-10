//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  int XOR = 0;
  for(int i = 1; i <= n; i++) {
    XOR = (XOR ^ i);
  }
  for(int i = 0; i < n - 1; i++) {
    XOR = (XOR ^ a[i]);
  }
  cout << XOR << "\n";
  return 0;
}