#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], b[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int sa = 0, sb = 0, ps = 0, ng = 0;
	for (int i = 1; i <= n; i++){
		if (a[i]>b[i]){
			sa += a[i];
		} else if (a[i]<b[i]) {
			sb += b[i];
		} else {
			if (a[i]==1) ps += 1;
			if (a[i]==-1) ng += 1;
		}
	}
	if (sa < sb) swap(sa,sb);
	int tmp = min(sa-sb,ps);
	sb += tmp;
	ps -= tmp;
	sa += (ps+1)/2;
	sb += ps/2;
	if (sa < sb) swap(sa,sb);
	tmp = min(sa-sb, ng);
	sa -= tmp;
	ng -= tmp;
	sa -= (ng+1)/2;
	sb -= ng/2;
	cout << min(sa,sb) << "\n";
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

