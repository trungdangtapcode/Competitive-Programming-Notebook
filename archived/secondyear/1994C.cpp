#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], nxt[maxN], f[maxN], x;
void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long sum = 0;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<n&&sum<=x) sum += a[++j];
		if (sum>x) nxt[i] = j+1;
		else nxt[i] = -1;
		sum -= a[i];
	}
	long long res = 0;
	f[n+1] = 0;
	for (int i = n; i >= 1; i--){
		if (nxt[i]!=-1) f[i] = f[nxt[i]]+1;
		else f[i] = 0;
		res += n-i+1-f[i];
	}
//	for (int i = 1; i<= n; i++) cout << nxt[i] << " "; cout << "\n";
//	for (int i = 1; i<= n; i++) cout << f[i] << " "; cout << "\n";
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

