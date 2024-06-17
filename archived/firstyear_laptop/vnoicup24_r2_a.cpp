#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e4+5;
int n, x, a[maxN];
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res = 0;
	for (int i = 1, l = 1; i <= n; i++){
		if (x*l>=a[i]){
			res++;
			l++;
		} 
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

