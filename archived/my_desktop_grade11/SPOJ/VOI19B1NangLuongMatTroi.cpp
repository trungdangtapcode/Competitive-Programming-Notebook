#include <bits/stdc++.h>

using namespace std;
int n, m, q, x = 1, y = 1, in1, in2, in3, in4, p;
int a[1005][1005], s[1005][1005];

void calc(int x1, int y1, int x2, int y2){
	x1 = (x1-1)%n+1; 
	y1 = (y1-1)%m+1;
	x2 = (x2-1)%n+1; 
	y2 = (y2-1)%m+1;
	if (x2 < x1) x2 += n;
	if (y2 < y1) y2 += m;
//	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	cout << s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j], a[i+n][j] = a[i][j+m] = a[i+n][j+m] = a[i][j];
	for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= 2*m; j++) s[i][j] = s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];	
	
	cin >> q;
	while (q--){
		cin >> p;
		if (p==0){
			cin >> in1 >> in2;
			x += in2;
			y += in1;
//			cout << " = " << x << " " << y << endl;
		} else {
			cin >> in1 >> in2 >> in3 >> in4;
			calc(x+in1-1,y+in2-1,x+in3-1,y+in4-1);
		}
	}
	
	return 0;
}

//khoang tong <= canh, de dang tinh tien
