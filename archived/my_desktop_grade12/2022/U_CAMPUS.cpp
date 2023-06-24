#include<bits/stdc++.h>

using namespace std;
int n, m;
string a[105];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a[0].assign(m+2,'L');
	a[n+1].assign(m+2,'L');
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = "L" + a[i] + "L";
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		if (a[i][j]=='F'&&a[i-1][j]!='B'&&a[i][j-1]!='B') a[i][j] = 'B';
	}
	for (int i = 1; i <= n; i++){
		cout << a[i].substr(1,m) << "\n";
	}
	
	return 0;
}
