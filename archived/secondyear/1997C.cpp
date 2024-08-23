#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	s = " " + s;
	int pref = 0;
	int res = 0;
	for (int i = n-1; i >= 1; i-=2){
		char c = s[i+1];
		pref += c==')'?1:-1;
		if (pref>0){
			if (!(i>1&&s[i-1]=='('&&pref==1)) pref--, res++;
			else pref++, res+=3; 
		} else {
			assert(0);
		}
	}
	cout << res << "\n";
}
int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

