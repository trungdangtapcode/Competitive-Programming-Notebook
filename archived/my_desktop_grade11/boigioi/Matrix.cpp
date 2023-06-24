#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[155][155];

int timS(int x1, int y1, int x2, int y2){
	return (a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1]);
}
int timW(int x1, int y1, int x2, int y2){
	if (x1==x2||y1==y2) return timS(x1,y1,x2,y2);
	return (timS(x1,y1,x2,y2)-timS(x1+1,y1+1,x2-1,y2-1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(a,0,sizeof(a));
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		if (!a[i][j]) a[i][j]--;
		a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}	
//	for (int i = 1; i <= m; i++){
//		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
//		cout << endl;
//	}
		
	int W = 0, X = 0;
	for (int x1 = 1; x1 <= m; x1++) for (int y1 = 1; y1 <= n; y1++){
		for (int x2 = x1; x2 <= m; x2++) for (int y2 = y1; y2 <= n; y2++){
			//myMax = max(myMax,timW(x1,y1,x2,y2));
			if (W < timW(x1,y1,x2,y2)) W = timW(x1,y1,x2,y2), X = 0;
			if (W == timW(x1,y1,x2,y2)) X++;// cout << X << "<-";
//			if (timW(x1,y1,x2,y2)==6)
//				cout << x1 << " " << y1 << " " << x2 << " " << y2 << "   " << timW(x1,y1,x2,y2) << endl;
		}
	}
	
	cout << W << " " << X;
	
	
	return 0;
}
