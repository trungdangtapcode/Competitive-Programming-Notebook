#include<bits/stdc++.h>

using namespace std;
string s, t;
void solve(){
	cin >> s >> t;
	int res = 1e9;
	for (int i = 0; i < t.length(); i++){
		int p = i;
		for (char c: s){
			if (p<t.length()&&c==t[p]) p++;
		}
		res = min(res,i+(int)t.length()-p+(int)s.length());
	}
	cout << res << "\n";
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

