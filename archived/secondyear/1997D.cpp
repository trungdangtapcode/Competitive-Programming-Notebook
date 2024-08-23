#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], f[maxN], res;
vector<int> edge[maxN];
void dfs(int u){
	if (edge[u].empty()){
		f[u] = a[u];
		return;
	}
	int mmin = 1e9;
	for (int v: edge[u]){
		dfs(v);
		mmin = min(mmin,f[v]);
	}
	if (u==1) res = a[u]+mmin;
//	cout << u << " " << a[u] << " " << mmin << "\n";
	if (mmin>a[u]){
		int d = mmin-a[u];
		f[u] = a[u]+d/2;
	} else f[u] = mmin;
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 2; i <= n; i++){
		int p; cin >> p;
		edge[p].push_back(i);
	}
	res = -1;
	dfs(1);
//	for (int i = 1; i <= n; i++) cout << i << ": " << f[i] << "\n";
	cout << res << "\n";
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

