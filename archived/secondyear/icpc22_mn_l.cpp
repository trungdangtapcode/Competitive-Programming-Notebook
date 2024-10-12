#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, f[maxN][2];
string s, t, u;
void solve(){
	cin >> n;
	if (n==0) exit(0);
	cin >> s >> t >> u;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	reverse(u.begin(),u.end());
	for (int i = 0; i <= n; i++) f[i][0] = f[i][1] = 1e9;
	f[0][0] = 0;
	for (int i = 0; i < n; i++) for (int carry = 0; carry < 2; carry++){
		int a = s[i]-'0', b = t[i]-'0', c = u[i]-'0';
		f[i+1][carry] = min(f[i][carry]+1,f[i+1][carry]); 
		int x = a+b+carry, ncarry = x/10;
		if (x%10==c){
			f[i+1][ncarry] = min(f[i][carry],f[i+1][ncarry]);
		}
	}
	cout << f[n][0] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	while (1)
	solve();
}

