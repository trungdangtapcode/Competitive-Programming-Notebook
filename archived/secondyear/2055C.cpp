#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e3+5;
int n, m;
string s;
int row[maxN], col[maxN], a[maxN][maxN], x[maxN], y[maxN];
void solve(){
	cin >> n >> m;
	cin >> s;
	s = " " + s + " ";
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	int cx = 1, cy = 1;
	for (int i = 1; i <= n+m-1; i++){
		if (s[i]=='D'){
			a[cx][cy] = -row[cx];
			row[cx] += a[cx][cy];
			col[cy] += a[cx][cy];
			cx++;
		} else {
			a[cx][cy] = -col[cy];
			row[cx] += a[cx][cy];
			col[cy] += a[cx][cy];
			cy++;
		}
	}
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i = 1; i <= n; i++){
		for (int j =1 ; j<= m; j++){
			cout << a[i][j] << " ";
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
		cout << "\n";
	}
//	for (int i = 1; i <= n; i++) cout << row[i] << " ";
//	for (int i = 1; i <= m; i++) cout << col[i] << " ";
//	cout << "==\n";
}


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

