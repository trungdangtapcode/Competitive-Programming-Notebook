#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 5e5+5;
int n, a[maxN];
string s;
void solve(){
	cin >> n >> s;
	int res = -1e9, cnt = 0, res2 = 1e9;
	for (int i = 0, j = 0; i < n; i++){
		if (s[i]=='A') continue;
		cnt++;
		res = i+1;
	}
	for (int i = n-1; i >= 0; i--) if (s[i]=='A') res2 = i+1;
	cout << max(res-res2,0ll) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
