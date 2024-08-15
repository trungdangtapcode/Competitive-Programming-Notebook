#include<bits/stdc++.h>

using namespace std;
string s, t;
int n;
void solve(){
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++){
		if (s[i]=='0'&&t[i]=='1'){
			cout << "NO\n";
			return;
		}
		if (s[i]=='1'){
			cout << "YES\n";
			return;
		}
	}
	cout << "YES\n";
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

