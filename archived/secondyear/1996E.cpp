#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, f[maxN];
const int mod = 1e9+7;
string s;
void solve(){
	cin >> s;
	n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; i++) f[i] = f[i-1] + (s[i]=='0'?-1:1);
	map<int,int> mp;
	map<int, long long> mp2;
	long long res = 0;
	mp2[0] = 1;
	for (int i = 1; i <= n; i++){
		res += 1ll*mp2[f[i]]%mod*(n-i+1)%mod;
//		mp[f[i]]++;
		mp2[f[i]] += i+1;
	}
	cout << res%mod << "\n";
	
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

