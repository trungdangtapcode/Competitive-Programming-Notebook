#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, m, a[maxN], b[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	vector<int> va({0}), vb({0});
	for (int i = 1, j = n; i < j; i++, j--){
		va.push_back(a[j]-a[i]);
	}
	for (int i = 1, j = m; i < j; i++, j--){
		vb.push_back(b[j]-b[i]);
	}
	int s = va.size()-1, t = vb.size()-1;
	for (int i = 1; i <= s; i++) va[i] += va[i-1];
	for (int i = 1; i <= t; i++) vb[i] += vb[i-1];
	vector<int> ans;
	for (int k = 1; 3*k <= n+m; k++){
		auto f=[&](int x){
			assert(x<=s);
			assert(k-x<=t);
			return va[x]+vb[k-x];
		};
		int ll = max(0ll,2*k-m), rr = min(k,n-k);
		if (ll>rr) break;
		int l = ll, r = rr, mr, ml, res = 0;
		while (r-l>2){
			ml = l+(r-l)/3;
			mr = r-(r-l)/3;
			if (f(ml)>f(mr)){
				r = mr;
			} else {
				l = ml;
			}
		}
		for (int i = l; i <= r; i++) res = max(res,f(i));
		ans.push_back(res);	
	}
	cout << ans.size() << '\n';
	for (int x: ans){
		cout << x << " ";
	}
	cout << '\n';
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

