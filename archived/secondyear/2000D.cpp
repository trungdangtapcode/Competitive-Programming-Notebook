#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], pref[maxN];
string s;
void solve(){
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	cin >> s;
	s = " " + s;
	int cnt = 0;
	for (int i = 1, j = n; i <= n; i++){
		if (s[i]=='R') continue;
		while (i<j&&s[j]=='L') j--;
		if (i<j&&s[j]=='R') res += (pref[j]-pref[i-1]);//*(++cnt); 
//		cout << i << ".." << j << " " << << "\n";
		j--;
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

