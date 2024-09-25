#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	k-=1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int g = 0;
	for (int i = 1; i <= n; i++){
		g = __gcd(g,a[i]);
	}
	if (n!=1) for (int i = 1; i <= n; i++) a[i] = (i-1)*g;
	int mex = 0;
	for (int i = 1; i <= n; i++){
		int d = a[i]-mex;
		if (k>=d){
			mex = a[i]+1;
		} else {
			break;
		}
		k -= d;
	}
	mex += k;
	cout << mex << '\n';
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

