#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, len[maxN];
vector<int> vec[maxN];
int offset = 0, coffset[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, c;
		cin >> a >> c;
		vec[c].push_back(a);
	}
	for (int c = 1; c <= 1e5; c++){
		len[c] = vec[c].size();
		for (int i = 1; i < len[c]; i++)
			vec[c][i] += vec[c][i-1];
	}
	int q;
	cin >> q;
	while (q--){
		int op, col, x, y;
		cin >> op;
		if (op==1){
			cin >> col >> x;
			offset += x;
			coffset[col] -= x;
		} else {
			cin >> col >> y;
			int l = 0, h = len[col]-1, res = -1, m;
			while (l<=h){
				m = (l+h)>>1;
				//(offset+coffset)*(m+1)+pref[m]<=x
				if ((offset+coffset[col])*(m+1)+vec[col][m]<=y){
					l = m+1;
					res = m;
				} else h = m-1;
			}				
			cout << res+1 << "\n";	
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

