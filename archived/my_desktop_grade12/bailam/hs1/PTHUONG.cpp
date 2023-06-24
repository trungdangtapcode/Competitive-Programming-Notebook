#include<bits/stdc++.h>

using namespace std;
int n, r;
long long int a[1005][1005], b[2005][2005];

long long int getSum(int x1, int y1, int x2, int y2){
	return (b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1]);
}
long long int sumR(int x, int y, int r){
	int x0 = x+y, y0 = -x+y+n;
	int x1 = max(x0-r,1), y1 = max(y0-r,1), x2 = min(x0+r,2*n), y2 = min(y0+r,2*n);
	return getSum(x1,y1,x2,y2);
}

int main(){
	freopen("PTHUONG.INP","r",stdin);
	freopen("PTHUONG.OUT","w",stdout);
	
	cin >> n >> r;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		b[i+j][-i+j+n] = a[i][j];
	}
	for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= 2*n; j++){
		b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	}
	long long int res = 0;
	for (int i = r+1; i <= n-r; i++) for (int j = r+1; j <= n-r; j++){
		res = max(res,sumR(i,j,r));
	}
	cout << res;
	
	
	return 0;
}
