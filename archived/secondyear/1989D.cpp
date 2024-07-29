#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
typedef pair<int,int> ii;
int n, b[maxN], m, f[maxN];
ii a[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++){
		a[i].second = a[i].first-b[i];
	}
	sort(a + 1, a + n+1);
	int ptr = 1, mmin = 1e9;
	f[0] = 0;
	for (int i = 1; i <= 1e6; i++){
		while (ptr<=n&&i>=a[ptr].first){
			mmin = min(mmin,a[ptr].second);
			ptr++;
		}
		if (mmin>i) continue;
		f[i] = f[i-mmin]+2;
	}
	long long res = 0;
	for (int i = 1; i <= m; i++){
		int c; cin >> c;
		if (c<=1e6){
			res += f[c];
			continue;
		}
		int tmp = (c-1e6+mmin-1)/mmin;
		res += 2*tmp + f[c-tmp*mmin];
	}
	cout << res << "\n";
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

