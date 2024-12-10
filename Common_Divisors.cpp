// //In The Name of ALLAH
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 7, mod = 1e9 + 7;
// #define int long long
// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   int n; cin >> n;
//   vector<int> a(n);
//   for(int i = 0; i < n; i++) {
//     cin >> a[i];
//   }
//   int ans = 1;
//   for(int i = 0; i < n; i++) {
//     for(int j = i + 1; j < n; j++) {
//       ans = max(ans, __gcd(a[i], a[j]));
//     }
//   }
//   cout << ans << "\n";
//   return 0;
// }
// // O(N * N);

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
#define int long long
int cnt[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for(int i = N; i >= 1; i--) {
    int x = 0;
    for(int j = i; j < N; j += i) {
      x += cnt[j];
      if(x >= 2) {
        cout << i << "\n";
        return 0;
      }
    }
  }
  return 0;
}


