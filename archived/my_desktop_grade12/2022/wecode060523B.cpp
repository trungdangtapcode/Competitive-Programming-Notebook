#include<bits/stdc++.h>

using namespace std;
int n, m, a[205][205];
typedef pair<int,int> ii;
const ii d[] = {{0,1},{1,0},{0,-1},{-1,0}};
bool ch[205][205];
ii goNext(ii x, int &dir){
	ii y = {x.first+d[dir].first, x.second+d[dir].second};
	if (y.first>=n||y.second>=m||y.first<0||y.second<0||ch[y.first][y.second]){
		return goNext(x,(++dir)%=4);
	} else {
		ch[y.first][y.second] = 1;
		return y;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	ii pos = {0,-1};
	for (int i = 0, dir = 0; i < n*m; i++){
		pos = goNext(pos,dir);
		cout << a[pos.first][pos.second] << " ";
	}
	
	
	return 0;
}
