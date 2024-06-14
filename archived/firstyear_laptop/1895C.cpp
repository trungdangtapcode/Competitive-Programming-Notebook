#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, pref[6][65], l[maxN], sum[maxN], suff[6][65];
string s[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		l[i] = s[i].length();
		sum[i] = 0;
		for (char c: s[i]) sum[i] += c - '0';
		pref[l[i]][sum[i]]++;
		suff[l[i]][sum[i]]++;
	}
	int res =0;
	for (int i = 1; i <= n; i++){
		int cur = 0;
//		cout << i << " " << l[i] << ": ";
		for (int j = 0; j < l[i]; j++){
			cur += s[i][j] - '0';
			int need = cur - (sum[i]-cur);
			int nl = (j+1)-(l[i]-j-1);
			if (need<=0||nl<=0) continue;
//			cout << nl << " " << need << " => " << pref[nl][need]<< "\n";
			res += pref[nl][need];
		}
	}
	for (int i = 1; i <= n; i++){
		int cur = 0;
//		cout << i << ": ";
		for (int j = l[i]-1; j > 0; j--){
			cur += s[i][j] - '0';
			int need = cur - (sum[i]-cur);
			int nl = (l[i]-j)-(j);
			if (need<=0||nl<=0) continue;
//			cout << nl << " " << need << " => " << pref[nl][need]<< "\n";
			res += suff[nl][need];
		}
	}
	cout << res;
}

main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--) 
	solve();
	
	return 0;
}
