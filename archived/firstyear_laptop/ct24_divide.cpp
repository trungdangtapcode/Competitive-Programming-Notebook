#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+6;
int n, a[maxN], spf[maxN];
void solve(){
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i <= 1e6; i++) if (spf[i]==i){
		for (int j = 2*i; j <= 1e6; j+= i) spf[j] = i;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		int tmp = a[i];
		while (tmp>1){
			int d = spf[tmp], cnt = 0;
			while (tmp%d==0) tmp /= d, cnt++;
			mp[d] += cnt;
		}
	}
//	for (auto it: mp) cout << it.first << "," << it.second << "\n";
	int q; cin >> q;
	for (int i = 1; i <= q; i++){
		int x, y, res = 1;
		cin >> x >> y;
		while (x>1){
			int d = spf[x], cnt = 0;
			while (x%d==0) x /= d, cnt++;
			if (!mp.count(d) or mp[d]<cnt*y){
				res = 0;
			}
		}
		cout << res << "";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

