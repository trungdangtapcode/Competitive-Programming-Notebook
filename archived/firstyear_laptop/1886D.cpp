#include<bits/stdc++.h>

using namespace std;
#define int long long

string s;
const int maxN = 2e6+5, mod = 998244353;
int n, m, val[maxN];
void updt(int k, int l, int r, int u, int x){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	val[k] = val[2*k]*val[2*k+1]%mod;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++){
		if (s[i]=='?') updt(1,1,n,i,i-1);
		else updt(1,1,n,i,1);
	}
	cout << val[1] << "\n";
	for (int i = 1; i <= m; i++){
		char c;
		int u;
		cin >> u >> c;
		s[u] = c;
		if (s[u]=='?') updt(1,1,n,u,u-1);
		else updt(1,1,n,u,1);
		cout << val[1] << "\n";
	}
	
	return 0;
}
