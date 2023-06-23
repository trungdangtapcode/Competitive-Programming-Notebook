#include<bits/stdc++.h>

using namespace std;

int n, m, cha[300005], len[300005];
int timcha(int x){
	int px = cha[x];
	if (px==x) return x;
	cha[x] = timcha(cha[x]);
	len[x] = (len[x]+len[px])%2;
	return cha[x];
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv&&len[u]==len[v]) return false;
	if (pu==pv) return true;
	cha[pu] = pv;
	len[pu] = (len[u]+len[v]+1)%2;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i, len[i] = 0;
	for (int i = 1, u, v; i <= m; i++){
		cin >> u >> v;
		if (!hop(u,v)){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	
	return 0;
}
