//In The Name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
int phi[N];
ll prephi[N];
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= N; i++) phi[i] = i;
    for(int i = 2; i <= N; i++) {
    	if(phi[i] == i) {
    		for(int j = i; j <= N; j += i) {
    			//phi[j] /= i;
    			//phi[j] *= (i - 1);
    			phi[j] -= phi[j] / i;
    		}
    	}
    }
    //for(int i = 1; i <= 20; i++) cout << phi[i] << "\n";
    for(int i = 1; i <= N; i++) {
    	prephi[i] = prephi[i - 1] + phi[i];
    }
    int t; cin >> t;
    while(t--) {
    	int a, b; cin >> a >> b;
    	cout << prephi[b] - prephi[a - 1] << endl;
    }
    return 0;
}