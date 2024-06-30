#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
const int maxN = 1e2+5;
int n, m, a[maxN][maxN];

int neighbor(int x, int y){
	int res = -1e9;
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i], yy = y + dy[i];
		if (xx>n||xx<1||yy>m||yy<1) continue;
		res = max(res,a[xx][yy]);
	}
	return res;
}

void solve(){
	cin >> n >> m;
	vector<iii> v;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
//			v.push_back({a[i][j],{i,j}});
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int x = neighbor(i,j);
			if (x<a[i][j]) a[i][j] = x;
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

