//count of different ways to express N as the sum of 1, 3 and 4
//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define ll long long
ll ways[N];
int num_ways(int i) {
	if(i == 1) return 1;
	if(i == 2) return 1;
	if(i == 3) return 2;
	if(i == 4) return 4;
	if(ways[i] != -1) return ways[i];
	ways[i] = (ways[i - 1] + ways[i - 3] + ways[i - 4]) % mod;
    return ways[i];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ways[1] = 1, ways[2] = 1, ways[3] = 2, ways[4] = 4;
  for(int i = 5; i < N; i++) {
    ways[i] = (ways[i - 1] + ways[i - 3] + ways[i - 4]) % mod;
  }
  int n; cin >> n;
  cout <<ways[n];
  return 0;
}
// complexity O(n) (recursive);

//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
#define ll long long
ll ways[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ways[1] = 1, ways[2] = 1, ways[3] = 2, ways[4] = 4;
  for(int i = 5; i < N; i++) {
    ways[i] = (ways[i - 1] + ways[i - 3] + ways[i - 4]) % mod;
  }
  int n; cin >> n;
  cout <<ways[n];
  return 0;
}
// complexity O(n) (iterative);

