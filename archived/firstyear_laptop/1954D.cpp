#include<bits/stdc++.h>

using namespace std;

const int maxN = 5e3+5, mod = 998244353;
int n, a[maxN], f[maxN];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	sort(a+1,a+n+1);
	f[0] = 1;
	for (int j = 5000; j >= 1; j--) f[j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 5000; j >= a[i]; j--){
			(res += 1ll*f[j-a[i]]*max(a[i],(j+1)/2)%mod)%= mod;
			(f[j] += f[j-a[i]])%=mod;
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

