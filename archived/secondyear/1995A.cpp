#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	int res = 0;
	if (k<=0) return cout << res << "\n", void();
	res++;
	k -= n;
	if (k<=0) return cout << res << "\n", void();
	
	for (int i = n-1; i > 0; i--){
		res++;
		k -= i;
		if (k<=0) return cout << res << "\n", void();
		res++;
		k -= i;
		if (k<=0) return cout << res << "\n", void();
	}
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

