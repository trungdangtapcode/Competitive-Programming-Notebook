#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5+5;
typedef pair<int,int> ii;
int n, x, c[maxN], d[maxN];
ii l[maxN], r[maxN];

void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> l[i].first >> r[i].first >> c[i];
		d[i] = r[i].first-l[i].first+1;
		l[i].second = r[i].second = i;
	}
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	map<int,int> mp;
	int res = 2e9+1;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<n&&r[j+1].first < l[i].first){
			j++;
			int idx = r[j].second;
			if (!mp.count(d[idx])) mp[d[idx]] = 1e9;
			mp[d[idx]] = min(mp[d[idx]], c[idx]);
		}
		int idx = l[i].second;
		if (mp.count(x-d[idx])) res = min(res,c[idx]+mp[x-d[idx]]);
	}
	cout << (res==2e9+1?-1:res) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

