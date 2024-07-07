#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5, mod = 1e9+7;
string s;
int f[maxN][2][3];
void solve(){
	cin >> s;
	int n = s.length();
	s = " " + s;
	f[0][1][2] = 1;
	for (int i = 1; i <= n; i++){
		memset(f[i],0,sizeof(f[i]));
		for (int np = 0; np < 2; np++){
			//last = 0: O
			(f[i][np][0] += f[i-1][np][0])%=mod;
			if (s[i]=='K') (f[i][np][2] += f[i-1][np][0])%=mod;
			
			//last = 1: K
			(f[i][np][1] += f[i-1][np][1])%=mod;
			if (s[i]=='O') (f[i][!np][2] += f[i-1][np][1])%=mod;
			
			//last = 2: None
			(f[i][np][2] += f[i-1][np][2])%=mod;
			if (s[i]=='O') (f[i][np][0] += f[i-1][np][2])%=mod;
			if (s[i]=='K') (f[i][np][1] += f[i-1][np][2])%=mod;
		}
	}
//	for (int i = 1; i <= n; i++){
//		cout << i << ":\n";
//		for (int np = 0; np < 2; np++) for (int last = 0; last <= 2; last++){
//			cout << "np = " << np << " last = " << last << " => " << f[i][np][last] << "\n";  
//		}
//	}
	cout << f[n][1][2] << "\n";
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

