#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, l[maxN], r[maxN], f[maxN], k;
string s;
void solve(){
	cin >> n >> k;
	cin >> s;
	s = "$" + s;
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int i = 1; i <= k; i++){
		cin >> l[i];
	}
	for (int i = 1; i <= k; i++){
		cin >> r[i];
	}
	int q; cin >> q;
	while (q--){
		int x;
		cin >> x;
		int y = upper_bound(l+1,l+k+1,x)-l-1;
//		cout << y << "x \n";
		x = min(x,r[y]-x+l[y]);
		f[x]++;
	}
	for (int i = 1; i <= k; i++){
		for (int j = l[i]+1; j <= r[i]; j++){
			f[j] += f[j-1];
		}
		for (int j = l[i]; j <= r[i]; j++){
			int x = min(j,l[i]+r[i]-j);
			cout << (f[x]%2==0?s[j]:s[l[i]+r[i]-j]) << "";
		}
	}
	cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
