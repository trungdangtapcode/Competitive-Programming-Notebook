#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], cnt[maxN], f[maxN], r[maxN];
long long res;
int mmax;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	res = 0;
	
	for (int i = 0; i <= n; i++) cnt[i] = f[i] = 0, r[i] = n;
	mmax = 0;
	for (int i = 1; i <= n; i++){
		res += a[i];
		if (cnt[a[i]]){
			mmax = max(mmax,a[i]);
		}
		cnt[a[i]]++;
		a[i] = mmax;
	}
	for (int i = 0; i <= n; i++) cnt[i] = f[i] = 0, r[i] = n;
	mmax = 0;
	for (int i = 1; i <= n; i++){
		res += a[i];
		if (cnt[a[i]]){
			mmax = max(mmax,a[i]);
		}
		cnt[a[i]]++;
		a[i] = mmax;
		f[mmax]++;
		r[mmax] = i;
	}
	
	for (int i = 1; i <= n; i++){
//		res += 1ll*i*f[i]*(f[i]+1)/2;
//		res += 1ll*(n-r[i])*f[i];
		res += 1ll*(n-i+1)*a[i];
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

