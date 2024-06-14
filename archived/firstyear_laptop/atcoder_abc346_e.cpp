#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 6e5+5;
int h, w, m, t[maxN], a[maxN], x[maxN], row[maxN], col[maxN], cntrow, cntcol, res[maxN];
void solve(){
	cin >> h >> w >> m;
	for (int i = h+w+1; i <= h+w+m; i++){
		cin >> t[i] >> a[i] >> x[i];
	}
	for (int i = 1; i <= h; i++) t[i] = 1, a[i] = i, x[i] = 0; 
	for (int i = h+1; i <= h+w; i++) t[i] = 2, a[i] = i-h, x[i] = 0; 
	m += h+w;
	for (int i = 1; i <= h; i++) row[i] = -1;
	for (int i = 1; i <= w; i++) col[i] = -1;
	for (int i = m; i >= 1; i--){
		if (t[i]==1){
			if (row[a[i]]!=-1) continue;
			row[a[i]] = x[i];
			cntrow++;
			res[x[i]] += w-cntcol;
		} else {
			if (col[a[i]]!=-1) continue;
			col[a[i]] = x[i];
			cntcol++;
			res[x[i]] += h-cntrow; 
		}
	}
//	for (int i = 1; i <= 10; i++) cout << i << " = " << res[i] << "\n";
	int cnt = 0; for (int i = 0; i <= 2e5; i++) cnt += (res[i]!=0);
	cout << cnt << "\n";
	for (int i = 0; i <= 2e5; i++) if (res[i]!=0){
		cout << i << " " << res[i] << "\n";
	}
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

