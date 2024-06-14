#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, q;
ii pos[maxN];
string s;
map<ii, vector<int>> mp;
bool query(int l, int r, ii x){
	auto it = lower_bound(mp[x].begin(),mp[x].end(),l);
	return (it!=mp[x].end()&&*it<=r);
}

void solve(){
	cin >> n >> q;
	cin >> s;
	s = "#" + s;
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++){
		if (s[i]=='U'){
			y++;
		} else if (s[i]=='D'){
			y--;
		} else if (s[i]=='R'){
			x++;
		} else x--;
		pos[i] = {x,y};
		mp[{x,y}].push_back(i);
	};
	for (auto it: mp){
		sort(it.second.begin(),it.second.end());
	}
	while (q--){
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		ii tmp = {pos[l-1].first+pos[r].first-x,pos[l-1].second+pos[r].second-y};
		cout << (query(1,l-1,{x,y})||query(r,n,{x,y})||query(l,r-1,tmp)||ii{x,y}==ii{0,0}?"YES":"NO") << "\n";
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
	
	return 0;
}
