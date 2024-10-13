#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
int n, m, p[maxN], cha[maxN], f[maxN];
int timcha(int x){
	return (x==cha[x]?x:cha[x]=timcha(cha[x]));
}
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		cha[i] = i;
	} 
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		x = timcha(p[x]), y = timcha(p[y]);
		cha[x] = y;
	}
	for (int i = 1; i <= n; i++){
		for (int j = n; j >= 1; j--) if (timcha(p[i])==timcha(j)){
			f[j] = max(f[j-1]+1,f[j]);
		}
		for (int j = 1; j <= n; j++) f[j] = max(f[j],f[j-1]);
	}
	cout << f[n] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

