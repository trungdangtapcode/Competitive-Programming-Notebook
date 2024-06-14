#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 998244353, modhash1 = 1e9+7, modhash2 = (1<<31)-1, maxN = 3e5+5;
int n;
int hash1[maxN], hash2[maxN], f[maxN];
string s;
void dfs(int u){
//	cout << u << " " << n << " nod\n";
	if (2*u+1>n){
		hash1[u] = s[u]-'A'+1;
		hash2[u] = s[u]-'A'+1;
		f[u] = 1;
		return;
	}
	int l = 2*u, r = 2*u+1;
	dfs(l), dfs(r);
	hash1[u] = ((s[u]-'A'+1) + (hash1[l]^hash1[r])*13 + (hash1[l]*hash1[r]*7)%modhash1)%modhash1;
	hash2[u] = ((s[u]-'A'+1) + (hash2[l]^hash2[r])*13 + (hash2[l]*hash2[r]*7)%modhash2)%modhash2;
	f[u] = f[l]*f[r]%mod;
	if (hash1[l]==hash1[r]&&hash2[l]==hash2[r]);// cout << u << "--\n";
	else (f[u] *= 2)%=mod;
//	cout << u << " = " << f[u] << " hash = " << hash1[u]<< " " << hash1[l] << " " << hash1[r] << "\n";
}
void solve(){
	cin >> n >> s;
	n = (1ll<<n)-1;
	s = " " + s;
	dfs(1);
	cout << f[1];	
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

