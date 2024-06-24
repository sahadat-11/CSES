//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int binexp(long long a, long long b, int mod) {
  int ans = 1 % mod; a %= mod; if (a < 0) a += mod;
  while (b) {
    if (b & 1) ans = (long long) ans * a % mod;
    a = (long long) a * a % mod;
    b >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void precal() { // O(n)
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = binexp(p1, mod1 - 2, mod1);
  ip2 = binexp(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

using T = pair<int, int>;

T mul(T p, int x) {
  p.first = 1LL * p.first * x % mod1;
  p.second = 1LL * p.second * x % mod2;
  return p;
}

T mul(T a, T b) { // change this
  T p;
  p.first = 1LL * (a.first * b.first) % mod1;
  p.second = 1LL * (a.second * b.second) % mod2;
  return p;
}

T merge(T l, T r) { // change this
  T p;
  p.first = (l.first + r.first) % mod1;
  p.second = (l.second + r.second) % mod2;
  return p;
}

struct Hasing {
  vector<T> t;
  string s;
  int n;
  Hasing() {}
  Hasing(string _s) {
    s = _s;
    n = s.size();
    t.resize(n * 4);
    build(1, 0, n - 1);
  }
  void build(int n, int b, int e) {
    if(b == e) {
      t[n] = mul(pw[b], s[b]);
      return;
    }
    int l = 2 * n, r = 2 * n + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = merge(t[l], t[r]);
  }
  T query(int n, int b, int e, int i, int j) { //(i, j) = range
    if(b > j or e < i) return {0, 0}; // totally out
    if(b >= i and e <= j) {// totally in
      return t[n];
    }
    int l = 2 * n, r = 2 * n + 1;
    int mid = (b + e) / 2;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
  void update(int n, int b, int e, int i, char c) {
    if(b > i or e < i) return;
    if(b >= i and e <= i) {
      t[n] = mul(pw[b], c);
      return;
    }
    int l = 2 * n, r = 2 * n + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, c);
    update(r, mid + 1, e, i, c);
    t[n] = merge(t[l], t[r]);
  }
  T substr_hash(int l, int r) {
    return mul(query(1, 0, n - 1, l, r), ipw[l]);
  }
}S, R;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  precal();
  S = Hasing(s);
  R = Hasing(r);

  while(q--) {
    int tp; cin >> tp;
    if(tp == 1) {
      int pos; char c; cin >> pos >> c;
      pos--;
      S.update(1, 0, n - 1, pos, c);
      R.update(1, 0, n - 1, n - pos - 1, c);
    }
    else {
      int l, r; cin >> l >> r;
      l--; r--;
      if(S.substr_hash(l, r) == R.substr_hash(n - r - 1, n - l - 1)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}


