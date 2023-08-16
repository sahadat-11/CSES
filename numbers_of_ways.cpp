//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
int nums_ways(int i) {
  if(i == 1) return 1;
  if(i == 2) return 1;
  if(i == 3) return 2;
  return nums_ways(i - 1) + nums_ways(i - 3);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  cout << nums_ways(n);
  return 0;
}
// complexity O(2^n);

//count of different ways to express N as the sum of 1 and 3

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define ll long long
ll ways[N];
int nums_ways(int i) {
  if(i == 1) return 1;
  if(i == 2) return 1;
  if(i == 3) return 2;
  if(ways[i] != -1) return ways[i];
  ways[i] = (nums_ways(i - 1) + nums_ways(i - 3)) % mod;
  return ways[i];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(ways, -1, sizeof(ways));
  int n; cin >> n;
  cout << nums_ways(n);
  return 0;
}
// complexity O(n) (recursive);
// https://prnt.sc/w_r96b5cBtuG

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define ll long long
ll ways[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ways[1] = 1, ways[2] = 1, ways[3] = 2;
  for(int i = 4; i < N; i++) {
    ways[i] = (ways[i - 1] + ways[i - 3]) % mod;
  }
  int n; cin >> n;
  cout <<ways[n];
  return 0;
}
// complexity O(n) (iterative);