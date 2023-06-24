#include<bits/stdc++.h>

using namespace std;

#define int long long

int par[300005], cnt[300005], probVex[300005], u[300005], v[300005], n, k;
vector<int> edge[300005];
const int p = 998244353;

int getpow(int a, int b){
	int res = 1;
	while (b){
		if (b&1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}
int inv(int x){
	return getpow(x,p-2);
}

void dfs(int p, int u){
	par[u] = p;
	cnt[u] = probVex[u];
	for (int v: edge[u]) if (v!=p){
		dfs(u,v);
		cnt[u] += cnt[v];
	}
}

main(){
	cin >> n >> k;
	for (int i = 1, x; i <= k; i++){
		cin >> x;
		probVex[x] = 1; //probability to have butterfly at vertex i
	}
	for (int i = 1; i < n; i++){
		cin >> u[i] >> v[i];
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
	}
	dfs(0,1);
	int res = 0;
	for (int i = 1; i <= n; i++){
		res = (res+cnt[i]*(k-cnt[i]))%p;
	}
	for (int i = 1; i < n; i++){
		if (par[u[i]]==v[i]) swap(u[i],v[i]);
		int probUV = (probVex[u[i]]*(1-probVex[v[i]])%p+p)%p; //probability U to V: U has and V NOT has
		int probVU = (probVex[v[i]]*(1-probVex[u[i]])%p+p)%p;
		int nodeU = k-cnt[v[i]], nodeV = cnt[v[i]];
		int diff = probUV*(nodeU-1-nodeV)%p + probVU*(nodeV-1-nodeU)%p;
		res = ((res+diff*inv(2))%p+p)%p;
		probVex[u[i]] = probVex[v[i]] = (probVex[u[i]]+probVex[v[i]])*inv(2)%p;
	}
	cout << res*inv(k*(k-1)/2%p)%p << "\n";
//	cout << 2*inv(2) << " " << res << endl;
	
	return 0;
}
