#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e6+6;
int l, r, seg[maxN];
void solve(){
	cin >> l >> r;
	//u(4d-u) >= l => 4d >= (l+u-1)/u+u
	// d < u
	// 4u-4 >= (l+u-1)/u+u
	// 3u-4-(l+u-1)/u
	//u(4d-u) <= r => 4d <= r/u+u
	for (int u = 1; u <= 8e6; u++){
		int x = (l+u-1)/u+u;
//		cout << u << " " << 3*u-4-(l+u-1)/u << "\n";
//		cout << u << " " << max((x+3)/4,0ll)<< "\n";
		for (int d = max((x+3)/4,0ll); d < u; d++){
			if (u*(4*d-u)>r) break;
			cout << u*(4*d-u) << " " << u << " " <<d << " " << x<< " " << (x+3)/4 << "\n";
			seg[u*(4*d-u)-l]++;
		}
	}
	int res = 0;
	for (int i = l; i <= r; i++){
//		cout << i << " = " << seg[i-l] << "\n";
		res += seg[i-l]==1;
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

