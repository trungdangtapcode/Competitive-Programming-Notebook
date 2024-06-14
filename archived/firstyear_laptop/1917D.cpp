#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx","sse2")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd()% (h - l + 1);
}
const int maxN = 4e5+5, B = 19, mod = 998244353;
int n, k, nk, a[maxN], b[maxN], cnt[55], mp[maxN];
int val[maxN];
void rs(){
	for (int i = 1; i <= nk; i++) val[i] = 0;
}
void updt(int x, int y){
	assert(x>0);
	for (; x <= nk; x += (x&-x)) val[x] += y;
}
int gett(int x){
	int res = 0;
	x = min(x,nk);
	x = max(x,(int)0);
	for (; x > 0; x -= (x&-x)) res += val[x];
	return res;
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> b[i];
//	for (int i = 1; i <= n; i++) a[i] = Rand(1,n)*2-1;
//	for (int i = 1; i <= k; i++) b[i] = Rand(0,k-1);
	nk = k+1;
	rs();
	long long res = 0;
	for (int i = 0; i <= k+B; i++) mp[i] = 0;
	for (int i = 1; i <= k; i++) mp[b[i]]++, updt(b[i]+1,1), (res += 1ll*n*(gett(nk)-gett(b[i]+1))%mod);
//	cout << res << ".. 1\n ";
	int larB = 0; 
	for (int i = 1; i <= k; i++) (larB += gett(b[i]+1-B-1))%=mod;
	for (int j = 0; j <= B; j++){
		cnt[j+B] = 0;
		for (int i = 1; i <= k; i++){
			(cnt[j+B] += (mp[b[i]+j]))%=mod; //b[..] - b[i] = j
		}
//		if (j>0) assert(cnt[j+B]==cnt[-j+B]);
	}
//	cout << "hi\n";
	nk = 2*n;
	rs();
//	for (int i = -5; i <= 5; i++){
//		cout << i << ": " << cnt[i+B] << "\n";
//	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= B; j++){
			int x = (a[i]<<j);
			int tmp = gett(nk)-gett(x);
			(res += 1ll*(tmp)*cnt[j+B]%mod);
			if (tmp==0) break;	
		}
		for (int j = -1; j >= -B; j--){
			int x = (a[i]>>(-j));
			if (x==0) (res += 1ll*(i-1)*cnt[-j+B]%mod);
			else (res += 1ll*(gett(nk)-gett(x))*cnt[-j+B]%mod);
		}
		(res += 1ll*larB*(i-1)%mod)%=mod;
		updt(a[i],1);
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}
