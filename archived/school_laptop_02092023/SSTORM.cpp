#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, a[4005][4005], b[4005][4005], q, k, w, r1, r2, x, y;
const int t = 1005;
void addrect(int x1, int y1, int x2, int y2, int w){
	int nx1 = x1-y1+m+t, ny1 =  x1+y1+t;
	int nx2 = x2-y2+m+t, ny2 =  x2+y2+t;
	b[nx1][ny1]+=w;
	b[nx2+1][ny1]-=w;
	b[nx1][ny2+1]-=w;
	b[nx2+1][ny2+1]+=w;
}
main(){
	cin >> n >> m >> q >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) cin >> a[i][j];
//		for (int j = 1; j <= m; j++) a[i][j] = 0;
	}
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= m; j++){
//			b[i-j+m+t][i+j+t] = a[i][j];
//		}
//	}
//	for (int i = 0; i <= 20; i++) {
//		for (int j = 0; j <= 20; j++) cout << b[i][j] << " ";
//		cout << endl;
//	}
	
	for (int i = 0, tmp; i < 2*q; i++) cin >> tmp;
	
	for (int i = 0; i < k; i++){
		cin >> w >> r1 >> r2 >> x >> y;
//		cout << x - r1 << "  "  << x+r1 << endl;
		r2--;
		addrect(x-r1,y,x+r1,y,+w);
		if (r2>=0) addrect(x-r2,y,x+r2,y,-w);
	}
	for (int i = 1; i <= n+m+t; i++) {
		for (int j = 1; j <= n+m+t; j++){
			b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
//			cout << b[i][j] << " ";
		}
//		cout << endl;
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) res+=min(b[i-j+m+t][i+j+t],a[i][j]);
//		cout << endl;
	}
	cout << res;
	
	return 0;
}
