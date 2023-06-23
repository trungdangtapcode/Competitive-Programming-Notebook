#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int r, g, b, f[205][205][205], a[205], d[205], c[205];
int main(){
	cin >> r >> g >> b;
	for (int i = 1; i <= r; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= g; i++){
		cin >> d[i];
	}
	for (int i = 1; i <= b; i++){
		cin >> c[i];
	}
	sort(a+1,a+r+1);
	sort(d+1,d+g+1);
	sort(c+1,c+b+1);
	for (int i = 0; i <= r; i++) for (int j = 0; j <= g; j++) for (int k = 0; k <= b; k++){
		if (i>0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k]);
		if (j>0) f[i][j][k] = max(f[i][j][k],f[i][j-1][k]);
		if (k>0) f[i][j][k] = max(f[i][j][k],f[i][j][k-1]);
		if (i>0&&j>0) f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k]+a[i]*d[j]);
		if (j>0&&k>0) f[i][j][k] = max(f[i][j][k],f[i][j-1][k-1]+d[j]*c[k]);
		if (i>0&&k>0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1]+c[k]*a[i]);
	}
	cout << f[r][g][b];
	
	return 0;
}



/*
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int r, g, b, f[6005];
ii a[6005];
int main(){
	cin >> r >> g >> b;
	for (int i = 1; i <= r; i++){
		cin >> a[i].first;
		a[i].second = 1;
	}
	for (int i = 1+r; i <= r+g; i++){
		cin >> a[i].first;
		a[i].second = 2;
	}
	for (int i = 1+r+g; i <= r+g+b; i++){
		cin >> a[i].first;
		a[i].second = 3;
	}
	sort(a+1,a+r+g+b+1);
	for (int i = 1; i <= r+g+b; i++){
		f[i] = f[i-1];
		for (int j = 1; j < i; j++) if (a[j].second!=a[i].second)
			f[i] = max(f[i],f[j-1]+a[j].first*a[i].first);
	}
	cout << f[r+g+b];
	
	return 0;
}

*/
