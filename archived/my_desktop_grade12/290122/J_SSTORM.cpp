#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m, q, k, a[505][505];
long long pref[1005][1005];
ii rotate45(int i, int j){
	return {i+j-1,j-i+n};
}
void updte(int r, int x, int y, long long val){
	if (r<0) return;
	ii ul = rotate45(x,y-r), dr = rotate45(x,y+r);
	ul.first = max(ul.first,1); ul.second = max(ul.second,1);
	dr.first = min(dr.first,m+n); dr.second = min(dr.second,m+n);
	pref[ul.first][ul.second]+=val;
	pref[dr.first+1][ul.second]-=val;
	pref[ul.first][dr.second+1]-=val;
	pref[dr.first+1][dr.second+1]+=val;
}

int main(){
	cin >> n >> m >> q >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	for (int i = 1, cc; i <= q; i++) cin >> cc >> cc;
	for (int i = 0, r1, r2, x, y, w; i < k; i++){
		cin >> w >> r1 >> r2 >> x >> y;
		updte(r1,x,y,w);		
		updte(r2-1,x,y,-w);
	}
	for (int i = 1; i <= n+m; i++) for (int j = 1; j <= n+m; j++){
		pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int iv = rotate45(i,j).first, jv = rotate45(i,j).second;
//			cout << pref[iv][jv] << " ";
			res += min(pref[iv][jv],1ll*a[i][j]);
		}
//		cout << "\n";
	}
	cout << res;
//	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
//		int iv = rotate45(i,j).first, jv = rotate45(i,j).second;
//		pref[iv][jv] = a[i][j];
//	}
//	for (int i = 1; i <= n+m; i++){
//		for (int j = 1; j <= n+m; j++) cout << pref[i][j] << " ";
//		cout << "\n";
//	}
	
	
	
	return 0;
}
