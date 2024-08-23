#include<bits/stdc++.h>

using namespace std;
int n, x;
void solve(){
	cin >> n >> x;
	long long res = 0;
	for (int c = 1; c <= x; c++){
		for (int b = 1; b <= x; b++){
			int tmp = min((n-b*c)/(b+c),x-c-b);
			if (tmp<=0) break;
			res += tmp;
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

