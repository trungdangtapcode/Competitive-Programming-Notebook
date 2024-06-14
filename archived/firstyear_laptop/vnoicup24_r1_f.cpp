#include<bits/stdc++.h>

using namespace std;
const int maxN = 3e5+5, mod = 1e9+7;
int n, f[maxN], prv[maxN], k, g[maxN];
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	for (int i = 0; i < 26; i++) prv[i] = -1;
	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i <= n; i++){
		f[i] = f[i-1]*2%mod;
		g[i] = g[i-1]*2%mod;
		if (prv[s[i]-'a']!=-1){
			f[i] -= 2*g[prv[s[i]-'a']-1]%mod;
			g[i] -= g[prv[s[i]-'a']-1];
		}
		prv[s[i]-'a'] = i;
		f[i] += mod;
		f[i] %= mod;
		cout << s[i]<< f[i] <<". ";
	}
	cout << f[n]-1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t >> k;
	while (t--)
	solve();
}

