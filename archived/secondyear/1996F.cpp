#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], b[maxN], res, k;
typedef pair<int,int> ii;
ii calc(int mmin){
	int cur = 0, total = 0;
	for (int i = 1; i <= n; i++){
		int x = a[i];
		if (x<mmin) continue;
		int cnt = (x-mmin)/b[i]+1;
		total += cnt;
		cur += cnt*x-b[i]*cnt*(cnt-1)/2;
		if (total>k) return {total,cur};
//		cout << i << ". " << cnt << " " << cnt*x-b[i]*cnt*(cnt-1)/2 << "\n";
	}
//	cout << total << " = " << cur << "\n";
//	if (total<=k) res = min(res,cur);
	return {total,cur};
}

void solve(){
//	n = 2e5, k = 199999;
//	for (int i =1 ; i<= n; i++) a[i] = 1e9;
//	for (int i =1 ; i<= n; i++) b[i] = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	res = 0;
	//h=1e9+1 =)) and so ans_m-1=1e9
	int l = 0, h = 1e9+1, m, ans_m = -1, ans_t = -1;
	while (l<=h){
		m = (l+h)/2;
		auto it = calc(m);
		if (it.first<=k){
			res = it.second;
			ans_m = m;
			ans_t = it.first;
			h = m-1;
		} else l = m+1;
	}
//	cout << res << " " << ans_t << " " << ans_m << "\n"; 
//	for (int i = 1; i <= n; i++){
//		while (a[i]>=0){
//			cout << a[i] << " -> ";
//			a[i] -= b[i];
//		}
//		cout << "\n";
//	}	
	if (ans_m>0) res += (k-ans_t)*(ans_m-1);
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

