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
	s = " " + s;
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
//	for (int i = 1; i <= n; i++) cout << row[i] << " ";
//	cout << '\n';
//	for (int i = 1; i <= m; i++) cout << col[i] << " ";
//	cout << "\n";
//	
	
	x[1] = 1;
	y[1] = s[1]=='R'?-col[1]:-row[1];
	int sx = x[1], sy = y[1];
	int cx = 1, cy = 1;
	for (int i = 2; i <= n+m-1; i++){
		if (s[i-1]=='R') cy++;
		else cx++;
		if (i==n+m-1||s[i-1]!=s[i]){
			if (s[i-1]=='D'){
				x[i] = 1-sx;
				y[i] = -col[cy]-sy;
			} else {
				x[i] = 1-sx;
				y[i] = -row[cx]-sy;
			}
			sx = 0;
			sy = 0;
		} else {
			if (s[i]=='R'){
				x[i] = 1;
				y[i] = -col[cy];
			} else {
				x[i] = 1;
				y[i] = -row[cx];
			}
		}
		sx += x[i];
		sy += y[i];
	}
	int xx = 1, yy = s[n+m-2]=='R'?-col[m]:-row[n];
//	cout << xx << "x + " << yy<< "--\n";
//	cout << x[n+m-1] << "x + " << y[n+m-1]<< "--\n";
	int t = xx-x[n+m-1]==0?1:(y[n+m-1]-yy)/(xx-x[n+m-1]);
	cx = 1, cy = 1;
	a[1][1] = t*x[1]+y[1];
	
	for (int i = 2; i <= n+m-1; i++){
		if (s[i-1]=='R') cy++;
		else cx++;
		a[cx][cy] = t*x[i]+y[i];
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

