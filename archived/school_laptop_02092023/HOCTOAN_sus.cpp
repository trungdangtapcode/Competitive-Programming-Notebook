#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[2001105], b[2001105], n, m, q, k[2001005][5], c[2001005];
int idx(int i, int j){
	return (m+2)*i+j+50;
}
int vien(int x, int y, int u, int v){
	return max({b[idx(x-1,m)],b[idx(n,y-1)],c[idx(u+1,1)],c[idx(1,v+1)]});
}
main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[idx(i,j)];
		}
	}
	cin >> q;
	int tmp = q;
	while (q--){
		cin >> k[q][0] >> k[q][1] >> k[q][2] >> k[q][3] >> k[q][4];
		b[idx(k[q][0],k[q][1])] += k[q][4];
		b[idx(k[q][0],k[q][3]+1)] -= k[q][4];
		b[idx(k[q][2]+1,k[q][1])] -= k[q][4];
		b[idx(k[q][2]+1,k[q][3]+1)] += k[q][4];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) b[idx(i,j)] += b[idx(i-1,j)]+b[idx(i,j-1)]-b[idx(i-1,j-1)];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) a[idx(i,j)] += b[idx(i,j)];
//		cout << endl;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			b[idx(i,j)] = max({b[idx(i,j)],b[idx(i-1,j)],b[idx(i,j-1)],a[idx(i,j)]});
		}
	}
	for (int i = n; i > 0; i--){
		for (int j = m; j > 0; j--){
			c[idx(i,j)] = max({c[idx(i,j)],c[idx(i+1,j)],c[idx(i,j+1)],a[idx(i,j)]});
		}
	}
	int res = 1e9;
	for (int i = 0; i < tmp; i++){
		int tmp = vien(k[i][0],k[i][1],k[i][2],k[i][3]);
		if (tmp>=c[idx(1,1)]){
			res = min(res,tmp);
		} else {
			res = min(res,max(c[idx(1,1)]-k[i][4],tmp));
		}
	}
	cout << res;
	
	return 0;
}
