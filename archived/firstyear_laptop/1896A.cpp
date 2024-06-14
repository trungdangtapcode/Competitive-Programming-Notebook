#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 5e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (a[1]!=1) cout << "NO\n";
	else cout << "YES\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
