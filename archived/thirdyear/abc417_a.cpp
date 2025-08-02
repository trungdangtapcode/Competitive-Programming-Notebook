#include<bits/stdc++.h>

using namespace std;
int n, a, b;
string s;
void solve(){
	cin >> n >> a >> b >> s;
	cout << s.substr(a,n-a-b) << "\n";
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

