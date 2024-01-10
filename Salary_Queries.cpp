#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  o_set<pair<int, int>> st;
  map<int, int> mp;
  int n, q; cin >> n >> q; int a[n + 1];
  int id = 1;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    st.insert({a[i], id++});
    mp[i] = a[i];
  }
  while(q--) {
    char c; cin >> c;
    if(c == '?') {
      int a, b; cin >> a >> b;
      cout << st.order_of_key({b + 1, 0}) - st.order_of_key({a, 0}) << "\n";
    }
    else {
      int k, x; cin >> k >> x;
      auto idx = st.lower_bound(make_pair(mp[k], 0));
      st.erase(idx);
      st.insert({x, id++});
      mp[k] = x;
    }
  }
  return 0;
}


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q; int a[n + 1];
  int id = 1;
  o_set<pair<int, int>> st; // pair for duplicate value;
  pair<int, int> salary[n + 1]; // pair er array
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    salary[i] = {a[i], id++};
    st.insert(salary[i]);
  }
  while(q--) {
    char c; cin >> c;
    if(c == '?') {
      int a, b; cin >> a >> b;
      cout << st.order_of_key({b + 1, 0}) - st.order_of_key({a, 0}) << "\n";
    }
    else {
      int k, x; cin >> k >> x;
      auto idx = salary[k];
      st.erase(idx);
      salary[k] = {x, id++};
      st.insert(salary[k]);
    }
  }
  return 0;
}