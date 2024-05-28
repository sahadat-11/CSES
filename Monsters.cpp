//In The Name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7, inf = 1e9 + 7;
//#define int long long
int n, m;
char a[N][N];
bool can_go[N][N];
pair<int, int> par[N][N];

int dx[] = {0, 0, -1, +1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

bool isValid(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}
vector<vector<int>> bfs(vector<pair<int, int>> dd) {
	vector<vector<int>> d(n, vector<int>(m, inf));
	queue<pair<int, int>> q;
	for(auto [u, v] : dd) {
	  q.push({u, v});
	  d[u][v] = 0;
	}
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
        for(int k = 0; k < 4; k++) {
	    int nxt_x = x + dx[k];
	    int nxt_y = y + dy[k];
	    if(isValid(nxt_x, nxt_y) and a[nxt_x][nxt_y] != '#' and d[x][y] + 1 < d[nxt_x][nxt_y]) {
	      d[nxt_x][nxt_y] = d[x][y] + 1;
	      q.push({nxt_x, nxt_y});
	   }
     }
	}
    return d;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<pair<int, int>> ami, monsters;
  for(int i = 0; i < n; i++) {
  	for(int j = 0; j < m; j++) {
  	  cin >> a[i][j];
  	  if(a[i][j] == 'A') {
        ami.push_back({i, j});
  	  }
  	  else if(a[i][j] == 'M') {
  	  	monsters.push_back({i, j});
  	  }
  	}
  }
  auto distance_from_me = bfs(ami);
  auto distance_from_mosters = bfs(monsters);
  
  // for(int i = 0; i < n; i++) {
  // 	for(int j = 0; j < m; j++) {
  // 	  cout << distance_from_me[i][j] << " ";
  // 	}
  // 	cout << "\n";
  // }

  for(int i = 0; i < n; i++) {
  	for(int j = 0; j < m; j++) {
  	  if(distance_from_me[i][j] < distance_from_mosters[i][j]) {
  	  	can_go[i][j] = true;
  	  } 
  	}
  }
  
  // for(int i = 0; i < n; i++) {
  // 	for(int j = 0; j < m; j++) {
  // 	 if(can_go[i][j]) {
  // 	 	cout << i << j << "\n";
  // 	 }
  // 	}
  // }

  vector<vector<int>> d(n, vector<int>(m, inf));
  queue<pair<int, int>> q;
  q.push(ami[0]);
  d[ami[0].first][ami[0].second] = 0;

  while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
        for(int k = 0; k < 4; k++) {
	    int nxt_x = x + dx[k];
	    int nxt_y = y + dy[k];
	    if(isValid(nxt_x, nxt_y) and can_go[nxt_x][nxt_y] and d[x][y] + 1 < d[nxt_x][nxt_y]) {
	      d[nxt_x][nxt_y] = d[x][y] + 1;
	      q.push({nxt_x, nxt_y});
	      par[nxt_x][nxt_y] = make_pair(x, y);
	    }
      }
	}
    
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
		  if(i == 0 or i == n - 1 or j == 0 or j == m - 1) {
		  	if(d[i][j] != inf) {
		  	  cout << "YES\n";
		  	  cout << d[i][j] << "\n";
		  	  vector<pair<int, int>> path;
		  	  pair<int, int> start = ami[0];
		  	  pair<int, int> cur = make_pair(i, j);
              while(cur != start) {
              	path.push_back(cur);
              	cur = par[cur.first][cur.second];
              }
              path.push_back(start);
              reverse(path.begin(), path.end());
              for(int i = 1; i < path.size(); i++) {
              	int x = path[i].first - path[i - 1].first;
              	int y = path[i].second - path[i - 1].second;
              	if(x == 1) cout << 'D';
              	else if(x == -1) cout << 'U';
              	else if(y == 1) cout << 'R';
              	else if(y == -1) cout << 'L';
              }
              return 0;
		  	}
		  }
		}
	}
	cout << "NO\n";
  return 0;
}