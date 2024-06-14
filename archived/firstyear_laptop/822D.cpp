#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e6+5, mod = 1e9+7;
int t, l, r;
long long f[maxN];
bool np[maxN];
void solve(){
	cin >> t >> l >> r;
	np[0] = np[1] = 1;
	for (int i = 2; i*i <= 5e6; i++) if (!np[i]){
		for (int j = i*i; j <= 5e6; j += i){
			np[j] = 1;
		}
	}
	vector<int> p;
	for (int i = 2; i <= 5e6; i++) if (!np[i]) p.push_back(i);
	for (int i = 1; i <= 5e6; i++) f[i] = 1ll*i*(i-1)/2;
	for (int i = 2; i <= 5e6; i++){
		for (int j = 0; j < p.size() && i*p[j] <= 5e6; j++)
			f[i*p[j]] = min(f[i*p[j]],f[i]+1ll*p[j]*(p[j]-1)/2*i);
	}
	
	int base = 1, res = 0;
	for (int i = l ; i <= r; i++){
		(res += 1ll*f[i]%mod*base%mod)%=mod;
		base = 1ll*base*t%mod;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

