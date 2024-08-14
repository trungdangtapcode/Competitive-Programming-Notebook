#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n;
string s;
void solve(){
	cin >> n >> s;
	int cnt = 0, one = 0;
	for (int i = 1; i <= n; i++){
		cnt += s[i-1]=='0'&&(s[i]=='1'||i==n);
		one += s[i-1]=='1';
	}
	cout << (one>cnt?"Yes\n":"No\n");
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

