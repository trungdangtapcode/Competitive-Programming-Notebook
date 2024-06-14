#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxN = 2e5+5;
const int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};  
typedef pair<int,int> ii;
int n, x[maxN], y[maxN];
ii res[maxN];
void solve(){
	cin >> n;
	map<ii, int> mp;
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		mp[{x[i],y[i]}] = i;
	}
	
	map<ii, bool> visited;
	queue<ii> q;
	for (int i = 1; i <= n; i++){
		res[i] = {-1e9,-1e9};
		for (int j = 0; j < 4; j++){
			int xx = x[i]+dx[j], yy = y[i]+dy[j];
			if (mp.count({xx,yy})) continue;
			res[i] = {xx,yy};
			q.push({x[i],y[i]});	
			break;
		}
	}
	
	while (q.size()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int xx = x+dx[i], yy = y+dy[i];
//			cout << x << ".." << y << " -> " << xx << ".." << yy << "\n";
			if (!mp.count({xx,yy})||res[mp[{xx,yy}]]!=ii{-1e9,-1e9}) continue;
			res[mp[{xx,yy}]] = res[mp[{x,y}]];
			q.push({xx,yy});	
		}	
	}
	
	for (int i = 1; i <= n; i++){
		cout << res[i].first << " " << res[i].second << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

