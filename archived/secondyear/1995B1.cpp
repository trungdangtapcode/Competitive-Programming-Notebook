#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
typedef pair<int,int> ii;
ii a[maxN];
int n, m, k[maxN], c[maxN];
int calc(int ka, int kb, int ca, int cb){
//	if (ka*ca+kb*cb<=m) return ka*ca+kb*cb;
//	int y = (m-ka*ca)/kb;
//	return y*kb+ka*ca;
	if (ka!=kb-1) return 0;
	// k(x+y)<=m-y
	int k = ka, x = ca, y = cb;
	int rem = m%k, div = m/k;
	int tmp = min({x,div});
//	cout << k << " " << x << " " << y << " "<< rem << " " << div << "\n";
	x -= tmp;
	div -= tmp;
	int res = tmp*k;
	if (m-res>=k+1){
		int tmp = min({(m-res)/(k+1),y});
		res += tmp*(k+1);
		y -= tmp;
	}
	res += min({m-res,y,tmp});
//	cout << div << " " << rem << "\n";
	return res;
}

void solve(){
	int n0;
	map<int,int> mp;
	cin >> n0 >> m;
	for (int i = 1; i <= n0; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	n = 0;
	for (auto it: mp){
		a[++n] = it;
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) k[i] = a[i].first, c[i] = a[i].second;
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res,min(m/k[i],c[i])*k[i]);
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

