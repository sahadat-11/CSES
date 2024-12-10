// if its contain any numbers of children;
// 8 22
// 6 6 7 7 7 9 10 10
// ans = 3;

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int used = 0, ans = 0;
  int l = 0, r = n - 1;
  while(l < r) {
    int sum = 0;
    while(a[r] + sum <= x) {
      sum += a[r];
      r--;
      used++;
    }
    while(a[l] + sum <= x) {
      sum += a[l]; l++;
      used++;
    }
    ans++;
  }
  if(used < n) ans++;
  cout << ans << "\n";
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int used = 0, ans = 0;
  int l = 0, r = n - 1;
  while(l < r) {
    int sum = 0, cnt = 0;
    while(a[r] + sum <= x) {
      if(cnt == 2) break;
      sum += a[r];
      r--;
      used++; cnt++;
    }
    while(a[l] + sum <= x) {
      if(cnt == 2) break;
      sum += a[l]; l++;
      used++; cnt++;
    }
    ans++;
    //cout << cnt << "\n";
  }
  if(used < n) ans++;
  cout << ans << "\n";
  return 0;
}


//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x; int a[n];
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0, r = n - 1, cnt = 0;
  while(l <= r) {
    int sum = a[l] + a[r];
    if(sum > x) {
      cnt++; r--;
    }
    else {
      cnt++;
      l++; r--;
    }
  }
  cout << cnt << "\n";
  return 0;
}

