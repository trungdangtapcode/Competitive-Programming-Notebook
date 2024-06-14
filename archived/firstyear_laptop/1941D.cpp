#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e3+5;
bool f[maxN][maxN];
int n, m, x, r[maxN], c[maxN];
void dfs(int u, int k, bool check = 1){
	if (f[u][k]) return;
	f[u][k] = check;
	if (k>m) return;
	if (c[k]==0) dfs((u+r[k])%n,k+1), dfs((u-r[k]+n)%n,k+1);
	else dfs((u+r[k]*c[k]+n)%n,k+1);
}

void solve(){
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < n; j++) f[j][i] = f[j][m+1] = 0;
		char ch;
		cin >> r[i] >> ch;
		c[i] = (ch=='?'?0:ch=='0'?1:-1);
	}
	dfs(x-1,1,1);
	vector<int> res;
	for (int i = 1; i <= n; i++){
		bool flag = 0;
		for (int j = m+1; j <= m+1; j++) if (f[i-1][j]){
			flag = 1;
			break;
		}
		if (flag) res.push_back(i);
	}
	cout << res.size() << "\n";
	for (int x: res) cout << x << " "; cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

