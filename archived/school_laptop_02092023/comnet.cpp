#include<bits/stdc++.h>

using namespace std;

int n, m, q, u[1000005], v[1000005], c[1000005], cc[1000005];
int cha[100005];
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[u] = v;
	return true;
}
void reset(){
	for (int i = 1; i <= n; i++) cha[i] = i;
}

void solve(){
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> c[i];
	}
	while (q--){
		int k, s;
		cin >> k >> s;
		for (int i = 1; i <= m; i++) cc[i] = c[i];
		while (s--){
			int t, c;
			cin >> t >> c;
			cc[t] = c;
		}	
		reset();
		for (int i = 1; i <= m; i++) if (cc[i]<cc[k]) hop(u[i],v[i]);
		cout << (timcha(u[k])==timcha(v[k])?"YES\n":"NO\n");
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	
	return 0;
}
