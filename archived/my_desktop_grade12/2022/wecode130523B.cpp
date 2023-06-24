#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, a[2005][2005], d[2005][2005];
const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		d[i][j] = -1;
	};
	if (a[1][1]==0) return cout << -1, 0;
	queue<ii> q;
	q.push({1,1});
	d[1][1] = 0;
	while (q.size()){
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			ii v = {u.first+dx[i],u.second+dy[i]};
			if (v.first<1||v.second<1||v.first>n||v.second>n||a[v.first][v.second]==0||d[v.first][v.second]!=-1) continue;
			d[v.first][v.second] = d[u.first][u.second] + 1;
			q.push(v);
		}
	}
	cout << d[n][n];
	
	return 0;
}
