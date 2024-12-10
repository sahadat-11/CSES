//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  map<char, int> mp;
  int n = s.size();
  for(int i = 0; i < n; i++) {
    mp[s[i]]++;
  }
  int cnt = 0; char c = '@';
  for(auto [val, fre] : mp) {
    if(fre & 1) {
      cnt++;
      c = val;
    }
  }
  if(cnt > 1) {
    cout << "NO SOLUTION\n";
  }
  else {
    string x;
    for(auto [val, fre] : mp) {
      for(int i = 0; i < fre / 2; i++) {
        x.push_back(val);
      }
    }
    cout << x;
    if(c != '@') cout << c;
    reverse(x.begin(), x.end());
    cout << x;
  }
  return 0;
}