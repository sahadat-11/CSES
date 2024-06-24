//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7, mod = 1e9 + 7;
#define int long long
int dp1[N][N], dp2[N][N], a[N];
bool vis1[N][N], vis2[N][N];

// function prototype
int second_person_optimal_score(int, int);

// if the first person plays the game optimally on segment a[l.....r];
// what will be the final score on the game
int first_person_optimal_score(int l, int r) {
	if(l > r) return 0;
	if(vis1[l][r]) return dp1[l][r];
	vis1[l][r] = true;
	// first person takes a[l];
	int left_score = a[l] + second_person_optimal_score(l + 1, r);
	
    // first person takes a[r];
	int right_score = a[r] + second_person_optimal_score(l, r - 1);
	
    // first person want to maximize
	return dp1[l][r] = max(left_score, right_score);
}

int second_person_optimal_score(int l, int r) {
	if(l > r) return 0;
    if(vis2[l][r]) return dp2[l][r];
    vis2[l][r] = true;
	// second person takes a[l];
	int left_score = first_person_optimal_score(l + 1, r);
	
    // second person takes a[r];
	int right_score = first_person_optimal_score(l, r - 1);
	
    // second person want to minimize
	return dp2[l][r] = min(left_score, right_score);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
  	cin >> a[i];
  }
  cout << first_person_optimal_score(1, n);
  return 0;
}
