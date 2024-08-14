#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5005, mod = 998244353;
int n, q, v[maxN], p[maxN], f[maxN];
void solve(){
	cin >> n >> q;
	for (int i = 1; i <= q; i++) cin >> p[i] >> v[i];
	for (int i = 1; i <= q; i++){
		for (int j = i-1; j >= 1; j--){
			if (v[j]<=v[i]) continue;
			if (p[j]==p[i]) return cout << "0\n", void();
			if (p[j]<p[i]){
				if (f[j]==1||f[i]==-1) return cout << "0\n", void();
				f[j] = -1;
				f[i] = 1;
			}
			if (p[j]>p[i]){
				if (f[j]==-1||f[i]==1) return cout << "0\n", void();
				f[j] = 1;
				f[i] = -1;
			}
		}
	}
	int res = 1;
	for (int i = 1; i <= q; i++) if (f[i]==0){
		res = 2*res%mod;
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

//https://pastebin.pl/view/22b8fb19
