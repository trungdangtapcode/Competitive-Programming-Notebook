#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, x;
void solve(){
	cin >> n >> x;
	int res = -1, last;
	for (int i = 0,a; i < n; i++){
		cin >> a;
		if (i){
			res = max(res,a-last);
		} else res = a;
//		cout << res << " " << a << "\n";
		last = a;
	}
	cout << max(res,2*(x-last)) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
