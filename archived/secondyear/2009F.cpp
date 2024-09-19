#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], pref[maxN], q;
int calcl(int p, int i){
	if (p==0) return 0;
	if (i==0) return pref[p];
	int s = (n-i)%n+1;
//	cout << "[s = " << s << " p = " << p << " i = " << i << "] ";
	if (p<s){
		return pref[p+i]-pref[i];
	} else {
		return pref[n]-pref[i]+pref[p-s+1];
	}
}
int calcr(int p, int i){
	return pref[n]-calcl(p-1,i);
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		pref[i] = pref[i-1] + a[i];
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		int idxr = (r-1)/n, idxl = (l-1)/n;
//		cout << idxl <<" " << idxr << " idx\n";
//		cout << calcl((r-1)%n+1,idxr) << " calc\n";
		cout << pref[n]*(idxr-idxl-1)+
			calcl((r-1)%n+1,idxr)+calcr((l-1)%n+1,idxl) << '\n';
	}
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

