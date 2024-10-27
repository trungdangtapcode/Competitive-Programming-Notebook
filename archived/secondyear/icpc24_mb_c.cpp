#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx","sse2")
#pragma GCC optimize("unroll-loops")

using namespace std;
const int maxN = 1e6+6;
int n, m, a[maxN], mod, smod[maxN];
long long s[maxN], mp[maxN];
void solve(){
	cin >> n >> m >> mod;
	if (n>m){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[j*n+i];
			}
		}
		swap(n,m);
	} else {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i*m+j];
//				a[i*m+j] = abs(rand())%mod;
			}
		}
	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			cout << a[i*m+j] << " ";
//		}
//		cout << "\n";
//	}
	for (int i = 0; i < mod; i++) mp[i] = 1e15;
	long long res = 0;
	for (int i = 0; i < n; i++){
		memset(s,0,sizeof(s));
		memset(smod,0,sizeof(smod));
		for (int j = i; j < n; j++){
			for (int k = 0; k < m; k++){
				s[k] += a[j*m+k];
				smod[k] += a[j*m+k];
				if (smod[k]>=mod) smod[k] -= mod;
			}
			if (1ll*(j-i+1)*m*(mod-1)<res) continue;
			mp[0] = 0;
			int prefmod = 0;
			long long pref = 0;
			for (int k = 0; k < m; k++){
				pref += s[k];
				prefmod += smod[k];
				if (prefmod>=mod) prefmod -= mod;
				res = max(res,pref-mp[prefmod]);
				mp[prefmod] = min(mp[prefmod],pref);
			}
			
			mp[0] = 1e15;
			pref = 0;
			prefmod = 0;
			for (int k = 0; k < m; k++){
				pref += s[k];
				prefmod += smod[k];
				if (prefmod>=mod) prefmod -= mod;
				mp[prefmod] = 1e15;
			}
		}
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	solve();
}

