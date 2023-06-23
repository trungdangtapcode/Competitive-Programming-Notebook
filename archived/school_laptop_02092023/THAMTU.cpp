#include<bits/stdc++.h>

using namespace std;

int cha[100005], n, m, p, sz[100005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	if (sz[pu]>sz[pv]) swap(pu,pv);
	cha[pu] = pv;
	sz[pv] += sz[pu];
}

int main(){
	freopen("input.txt","r",stdin);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = 1;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		hop(u,v);
	}
	int res = 1, tplt = 0;
	for (int i = 1; i <= n; i++)  if (cha[i]==i){
		res = 1ll*res*sz[i]%p;
		tplt++;
	}
	for (int i = 0; i < tplt - 2; i++) res = 1ll*res*n%p;
	if (tplt==1) return cout << 0,0;
	cout << res; 
	
	return 0;
}
