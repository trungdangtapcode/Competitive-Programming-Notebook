#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e3+3;
typedef pair<int,int> ii;
int n, k;
int f[maxN][maxN], g[maxN][maxN], trace[maxN][maxN];
string s;

void updt(int i, int j, int newf, int newg, int tr){
	if (f[i][j]>newf){
		f[i][j] = newf;
		g[i][j] = newg;
		trace[i][j] = tr;
		return;	
	}
	if (f[i][j]==newf){
		if (g[i][j]>newg){
			f[i][j] = newf;
			g[i][j] = newg;
			trace[i][j] = tr;
			return;
		}
		return;
	}
	return;
}

void solve(){
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++) f[i][j] = g[i][j] = 1e9;	
		f[0][i] = g[0][i] = 0;
	}
	
	// f[i][j] = cost when you used j times
	// when not choose f[i][j] = f[i-1][j]+min(g[i-1][j],(s[i]==')')) 
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			// not choose to remove
			updt(i, j, f[i-1][j]+min(g[i-1][j],int(s[i]==')')), g[i-1][j]+(s[i]=='(')-min(g[i-1][j],int(s[i]==')')),
				j);
			// choose to remove
			updt(i, j+1, f[i-1][j], g[i-1][j], j);
		}
	}
	int res = 1e9, resi = 0;
	for (int i = 0; i <= k; i++){
		if (res>f[n][i]){
			res = f[n][i];
			resi = i;
		}
	}
//	cout << res << "\n";
	string vres;
	for (int i = n; i >= 1; i--){
		if (trace[i][resi]==resi){
			vres.push_back('0');
		} else {
			vres.push_back('1');
		}
		resi = trace[i][resi];
	}
	reverse(vres.begin(), vres.end());
	cout << vres << "\n";
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

