#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], c;
void solve(){
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int cc = 0;
	for (int i = 1; i <= n; i++){
		if (a[i]>c){
			break;
		}
		cc = i;
	}
	int tmp = 1, res = 0;
	for (int i = cc; i >= 1; i--){
		if (a[i]*tmp>c) res++;
		else {
			tmp *= 2;
			tmp = min(tmp, (int)2e9);
		}
	}
	cout << res + (n-cc) << "\n";
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

