#include<bits/stdc++.h>

using namespace std;
#define int long long
int x, y, z, k;
void solve(){
	cin >> x >> y >> z >> k;
	int res = 0;
	for (int i = 1; i <= x; i++) for (int j = 1; j <= y; j++){
		int s = i*j;
		if (k%s) continue;
		int h = k/s;
		if (h>z) continue;
		res = max(res,(x-i+1)*(y-j+1)*(z-h+1));
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

