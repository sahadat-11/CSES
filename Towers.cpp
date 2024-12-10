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
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<int> st;
  for(int i = 0; i < n; i++) {
    auto it = st.upper_bound(a[i]);
    if(it == st.end()) { // if not found
        st.insert(a[i]);
    }
    else {
        st.erase(it);
        st.insert(a[i]);
    }
  }
  cout << (int)st.size() << "\n";
  return 0;
}