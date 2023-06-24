#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5+5;
int f[maxN][105], n, a[maxN], m, l;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1, p = 1; i <= n; i++){
		while (p<i&&a[i]-a[p]>l) p++;
		for (int j = 1; j <= m; j++){
			f[i][j] = max(f[i-1][j],f[p-1][j-1]+(i-p+1));
		}
	}
	cout << f[n][m];
	
	return 0;
}

/*
doc thanh mot cai de khac luon =))
https://lqdoj.edu.vn/submission/2378209
/*
