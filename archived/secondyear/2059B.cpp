#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (k==n){
		int res = 1;
		for (int i = 2, j = 1; i <= n; i += 2, j++){
			if (a[i]!=j) break;
			res++;
		}
		cout << res << "\n";
	} else {
		for (int i = 2; i <= n-k+2; i++){
			if (a[i]!=1){
				cout << 1 << "\n";
				return;
			}
		}
		cout << 2 << "\n";
	}
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

