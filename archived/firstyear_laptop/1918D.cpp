#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, a[maxN], f[maxN];
bool check(int x){
	for (int i = 1; i <= n+1; i++) f[i] = 1e18;
	multiset<int> ms;
	ms.insert(0);
	for (int i = 1, j = 1, sum =0; i <= n+1; i++){
		while (sum>x) ms.erase(ms.find(f[j-1])), sum -= a[j++];
		f[i] = min(f[i],*ms.begin()+a[i]);
		sum += a[i];
		ms.insert(f[i]);
	} 
	return f[n+1]<=x;
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n+1] = 0;
	int l = 0, h = 1e18, m, res;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			h = m-1;
		} else l = m+1;
	}	
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
