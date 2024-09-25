#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, d, k, l[maxN], r[maxN], g[maxN], s[maxN], t[maxN];
void solve(){
	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++) s[i] = t[i] = 0;
	for (int i = 1; i <= k; i++){
		cin >> l[i] >> r[i];
		s[l[i]]++;
		t[r[i]]++;
	}
	for (int i = 1, j = 0, cur = 0; i <= n-d+1; i++){
		while (j<i+d-1){
			j++;
			cur += s[j]; 
		}
		g[i] = cur;
		cur -= t[i];
	}
	int res1 = 1, res2 = 1;
	for (int i = 2; i <= n-d+1; i++){
		if (g[res1]<g[i]) res1 = i;
		if (g[res2]>g[i]) res2 = i;
	}
	cout << res1 << " " << res2<< "\n";
//	exit(0);
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

