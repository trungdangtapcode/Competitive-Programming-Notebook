#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const ii d[] = {{0,1},{1,0},{0,-1},{-1,0}};
int n, t, k, res[205][205];
bool ch[205][205];
ii goNext(ii x, int &dir){
	ii y = {x.first+d[dir].first, x.second+d[dir].second};
	if (y.first>=n||y.second>=n||y.first<0||y.second<0||ch[y.first][y.second]){
		return goNext(x,(++dir)%=4);
	} else {
		ch[y.first][y.second] = 1;
		return y;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> t >> k;
	ii pos = {0,-1};
	for (int i = 0, dir = 0, num = t-k; i < n*n; i++){
		//cout << pos.first << " " << pos.second << " dir = " << dir<< "\n";
		pos = goNext(pos,dir);
		res[pos.first][pos.second] = (num+=k);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) cout << res[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}
