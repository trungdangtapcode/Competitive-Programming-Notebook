#include<bits/stdc++.h>

using namespace std;
#define itn long long
const int maxN = 2e5+5;
typedef pair<int,int> ii;
ii a[maxN];
int n, m, k[maxN], c[3maxN];
int calc(int ka, int kb, int ca, int cb){
	if (ka*ca+kb*cb<=m) return ka*ca+kb*cb;
	int y = (m-ka*ca)/kb;
	return y*kb+ka*ca;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) k[i] = a[i].first, c[i] = a[i].second;
	int res = 0;
	for (int i = 1; i < n; i++){
		res = max(res,calc(k[i],k[i+1],c[i],c[i+1]));
	}
	cout << res << "\n";
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

