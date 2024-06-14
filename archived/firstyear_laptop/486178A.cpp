#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int n, m;
int d[maxN][maxN];
string s[maxN];
typedef pair<int,int> ii;
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) d[i][j] = 1e9;
	d[0][0] = 0;
	deque<ii> q;
	q.push_back({0,0});
	while (!q.empty()){
		int ux = q.front().first, uy = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++){
			int vx = ux + dx[i], vy = uy + dy[i];
			if (vx<0||vx>=n||vy<0||vy>=m) continue;
			int c = (s[ux][uy]!=s[vx][vy]);
			if (d[ux][uy]+c<d[vx][vy]){
				d[vx][vy] = d[ux][uy] + c;
				if (c) q.push_back({vx,vy});
				else q.push_front({vx,vy});
			}
		}
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++) cout << d[i][j] << " ";
//		cout << '\n';
//	}
	cout << d[n-1][m-1] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
