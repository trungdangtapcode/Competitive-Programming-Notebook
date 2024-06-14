#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+5, maxM = 25, maxLM = (1<<20)+5;
int n, m, b[maxM], f[maxLM];
pii nxt[maxN][maxM], trace[maxLM], a[maxN];
vector<int> res[maxM];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) a[i].second = i;
	sort(a+1,a+n+1);
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int j = 1; j <= m; j++){
		for (int i = 1, ii = n; i <= n; i++){
			while (ii&&(b[j]+ii-1)/ii<=a[i].first) ii--;
			ii++;
			nxt[i][j] = (i+ii-1>n?pii{1e9,-1}:pii{i+ii,i});
//			cout << j<<"."<<b[j] << " " << i << "." <<a[i] << " -> " << ii<<"."<<nxt[i][j].first << "\n";	
		}
		for (int i = n-1; i > 0; i--){
			nxt[i][j] = min(nxt[i][j],nxt[i+1][j]);
		}
	}
	for (int mask = 0; mask < (1<<m); mask++) f[mask] = 1e9;
	f[0] = 1;
	for (int mask = 0; mask < (1<<m); mask++){
		if (f[mask]>n) continue;
		for (int i = 0; i < m; i++) if ((mask&(1<<i))==0){
			int nmask = mask|(1<<i);
//			cout << f[nmask] << " " << nxt[f[mask]][i+1].first << "\n";
			if (f[nmask]<=nxt[f[mask]][i+1].first) continue;
			f[nmask] = min(f[nmask],nxt[f[mask]][i+1].first);
//			cout << bitset<5>(mask) << " -> "<< bitset<5>(nmask) << " " << f[nmask] << "\n";
			trace[nmask] = {mask,nxt[f[mask]][i+1].second};
		}
	}
//	cout << f[(1<<m)-1] << "\n";
	int cur = (1<<m)-1;
	if (f[cur]==1e9){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	while (cur){
//		cout << bitset<5>(cur) << "\n";
//		cout << f[cur]-trace[cur].second << " ";
//		for (int i = trace[cur].second; i < f[cur]; i++) cout << a[i].second << " ";
//		cout << "\n";
		int p = __lg(cur^trace[cur].first)+1; 
		for (int i = trace[cur].second; i < f[cur]; i++) res[p].push_back(a[i].second);
		cur = trace[cur].first;
	}
	for (int i= 1; i <= m; i++){
		cout << res[i].size() << " ";
		for (int x: res[i]) cout << x << " ";
		cout << "\n";
	}
	
	return 0;
}
