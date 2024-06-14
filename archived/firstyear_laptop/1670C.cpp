#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5, mod = 1e9+7;
int n, a[maxN], b[maxN], inva[maxN], invb[maxN], fixedpos[maxN], d[maxN], sz[maxN];
int cha[maxN];
int timcha(int x){
	return (x==cha[x]?x:cha[x] = timcha(cha[x]));
}
void rs(){
	for (int i = 1; i<= n; i++) cha[i] = i, sz[i] = 1;
}
void hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return;
	cha[v] = u;
	sz[u] += sz[v];
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) inva[a[i]] = i, invb[b[i]] = i;
	rs();
	for (int i = 1; i <= n; i++){
		fixedpos[i] = 0;
		hop(i,inva[b[i]]);
		hop(i,invb[a[i]]);
	};
	for (int i = 1; i <= n; i++){
		cin >> d[i];
		if (d[i]!=0) fixedpos[timcha(i)] = 1;
	}
	int res = 1;
	for (int i = 1; i <= n; i++) if (d[i]==0&&!fixedpos[timcha(i)]&&sz[timcha(i)]>1){
		res = 2ll*res%mod;
		fixedpos[timcha(i)] = 1;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

