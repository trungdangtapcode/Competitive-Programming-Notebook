#include <bits/stdc++.h>

using namespace std;
int m, n;
int a[1005][1005], b[2010][2010];
int f1[1005][1005], f2[1005][1005],f3[1005][1005], f4[1005][1005];

int getSum(int x, int y, int r){
	int ax1 = x;
	int ay1 = y - r;
	int ax2 = x;
	int ay2 = y + r;
	int bx1 = ax1 + ay1 - 1;
	int by1 = 1000 - ax1 + ay1;
	int bx2 = ax2 + ay2 - 1;
	int by2 = 1000 - ax2 + ay2;
	return (b[bx2][by2]-b[bx2][by1-1]-b[bx1-1][by2]+b[bx1-1][by1-1]);
}

int main(){
	
	cin >> m >> n;
	memset(b,0,sizeof(b));
	for (int i = 1; i <= m; i++){
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++){
			a[i][j] = (s[j-1]=='*');
			b[i+j-1][1000-i+j] = (s[j-1]=='*'); //clockwise - [1][1] 
			//=> counterclockwise[n+i-j][i+j-1]
			//=> clockwise - [0][0] ([i+j+1][n+1-i+j])
		}
	}
	for (int i = 1; i <= 2000; i++) for (int j = 1; j <= 2000; j++) b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	memset(f3,0,sizeof(f3));
	memset(f4,0,sizeof(f4));
	for (int i = 2; i <= m; i++){
		for (int j = 2; j <= n; j++) if ((a[i][j]==1&&a[i][j-1]==0&&a[i-1][j]==0)||a[i][j]==0){
			f1[i][j] = min(f1[i-1][j],f1[i][j-1]) + 1;
		}
	}
	for (int i = 2; i <= m; i++){
		for (int j = n-1; j >= 1; j--) if ((a[i][j]==1&&a[i][j+1]==0&&a[i-1][j]==0)||a[i][j]==0){
			f2[i][j] = min(f2[i-1][j],f2[i][j+1]) + 1;
		}
	}
	for (int i = m-1; i >= 1; i--){
		for (int j = 2; j <= n; j++) if ((a[i][j]==1&&a[i][j-1]==0&&a[i+1][j]==0)||a[i][j]==0){
			f3[i][j] = min(f3[i+1][j],f3[i][j-1]) + 1;
		}
	}
	for (int i = m-1; i >= 1; i--){
		for (int j = n-1; j >= 1; j--) if ((a[i][j]==1&&a[i][j+1]==0&&a[i+1][j]==0)||a[i][j]==0){
			f4[i][j] = min(f4[i+1][j],f4[i][j+1]) + 1;
		}
	}
	
	int res = 0, resX, resY, resR;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			int r = min(min(f1[i][j],f2[i][j]),min(f3[i][j],f4[i][j]));
			if (getSum(i,j,r)>res){
				res = getSum(i,j,r);
				resX = i;
				resY = j;
				resR = r;
			}
		}
	}
	cout << res << " " << resX << " " << resY << " " << resR << endl;
	
	//cout << getSum(2,2,1);
//	for (int i = 1; i <= 20; i++){
//		for (int j = 1; j <= 20; j++) cout << f1[i][j] << " ";
//		cout << endl;
//	}
	
	return 0;
}
