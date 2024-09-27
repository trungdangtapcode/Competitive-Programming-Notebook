#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	int g = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		g = __gcd(g,a[i]);
	}
	long long res = 0;
	int cur =0, cnt = n;
	while (1){
		int tmp = 1e9;
		for (int i = 1; i<= n; i++) tmp = min(tmp,__gcd(cur,a[i]));
		res += tmp;
		cur = tmp;
		cnt--;
		if (cur==g){
			res += 1ll*cnt*g;
			break;
		}
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

