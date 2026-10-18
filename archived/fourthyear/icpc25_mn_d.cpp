#include<bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1e9+7, K=10005;
int n, k, inv[55], f[K][55];
typedef pair<int,int> ii;
int calc(int p, int e){
//	cout << p << " " << e << "\n";
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int i = 1; i <= e; i++) f[0][i] = f[0][i-1]*p%MOD;
//	cout << f[0][e] << "\n";
	
	for (int kk = 1; kk <= k; kk++)
	for (int i = 0; i <= e; i++){
		for (int j = 0; j <= i; j++) (f[kk][i] += f[kk-1][j])%= MOD;
		f[kk][i] = f[kk][i]*inv[i+1]%MOD;
//		cout << f[kk][i] << "\n";
	}
	return f[k][e];
}

void solve(){
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= 50; i++){
		inv[i] = MOD-(MOD/i)*inv[MOD%i]%MOD;
	}
	cin >> n >> k;
	int tmp = n;
	vector<ii> fac;
	for (int i = 2; i*i <= tmp; i++) if (tmp%i==0){
		int cnt = 0;
		while (tmp%i==0) tmp /= i, cnt++;
		fac.push_back({i,cnt});
	}
	if (tmp>1){
		fac.push_back({tmp,1});
	}
	int res = 1;
	for (auto it: fac){
		int p = it.first, cnt = it.second;
		res = res*calc(p, cnt)%MOD;
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

