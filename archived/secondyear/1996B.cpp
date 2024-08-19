#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
int n, k;
string s[maxN];
void solve(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i+=k){
		for (int j = 0; j < n; j+=k) cout << s[i][j];
		cout << "\n";
	};
	
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

