#include<bits/stdc++.h>

using namespace std;
int n, m, d, p[500005], pt[500005], a[500005];
void solve(){
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) pt[p[i]] = i;
	int res = 1e9;
	assert(m>=2);
	for (int i = 1; i <= m; i++){
		cin >> a[i];
		if (i>1){
//			if (pt[a[i]]>pt[a[i-1]]+d||pt[a[i]]<pt[a[i-1]]){
//				res = 0;
//				break;
//				return
//			};
			res = min(res,pt[a[i]]-pt[a[i-1]]);
			if (1+d<n) res = min(res,pt[a[i-1]]+d+1-pt[a[i]]); 
		}
	}
//	if (pt[a[1]]-1>=pt[a[1]]+d+1-pt[2]) res = min(res,pt[a[1]]+d+1-pt[a[2]]);
//	if (res==1e9) res/= 0;
//	if (res!=1e9) cout << res; else cout << "0\n";
	cout << max(0,res);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while (t--){
		solve();
		cout << "\n";
	}
	return 0;
}
