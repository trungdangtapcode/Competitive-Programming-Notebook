#include<bits/stdc++.h>

using namespace std;
int n, a;
void solve(){
	cin >> n;
	int last = -1, mmax = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a;
		if (last>a){
			int x = last-a;
			res += x;
			mmax = max(mmax,x);
			a = last;
		}
		last = a;
	}
	cout << res+mmax << '\n';
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

