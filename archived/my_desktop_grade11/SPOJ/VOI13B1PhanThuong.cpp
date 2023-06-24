#include <bits/stdc++.h>

using namespace std;
int k;
vector<pair<int,int>> frees, gift;
long long int res = 0;
int a[65][65];
int cnt[9][9], hang[9], cot[9], cheoChinh[30], cheoPhu[30];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

void calc(){
	long long int sum = 0; int x, y;
	for (auto it: gift){
		x = it.first, y = it.second;
		if (cnt[x][y]||hang[x]||cot[y]||cheoChinh[x-y+8]||cheoPhu[x+y]) sum += a[x][y];
	}
	res = max(res,sum);
}
//void calc2(){
//	for (int i = 1; i <= 8; i++);;
//}

void dat(int n, int x, int y, int v){
	if (n==1||n==2){ //hau hoac xe
		hang[x]+=v; cot[y]+=v;
	}
	if (n==1||n==3){ //hau hoac chot
		cheoChinh[x-y+8]+=v; cheoPhu[x+y]+=v;
	}
	if (n==0) for (int i = 0; i < 8; i++){ //ma la 0 thi toi uu hon 4
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1||xx>8||yy<1||yy>8) continue;
		cnt[xx][yy]+=v;
	}
}

bool check[9][9];
int dem = 0;
void dequy(int n){
	if (n>3){
		calc();
		//if (dem%100==1)cout << 100*(dem++) + 1 << '\n'; else dem++;
		return;
	}
	int i, j;
	for (auto it: frees){
		i = it.first, j = it.second;
		if (check[i][j]) continue;
		//if (n==0) cout << n ;
		dat(n,i,j,1);
		check[i][j] = true;
		dequy(n+1);
		dat(n,i,j,-1);	
		check[i][j] = false;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> k;
	for (int i = 0; i < k; i++){
		int x, y, t;
		cin >> x >> y >> t;
		a[x][y] = t;
		gift.push_back({x,y});
	}
	for (int i = 1; i <= 8; i++) for (int j = 1; j <= 8; j++) if (a[i][j]==0) frees.push_back({i,j});
	dequy(0);
	cout << res;
	
}
