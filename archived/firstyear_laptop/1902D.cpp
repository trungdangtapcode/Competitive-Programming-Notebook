#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, q;
string s;
ii pos[maxN];
set<ii> val[maxN*4];

void build(int k, int l, int r){
	if (l==r){
		val[k].insert(pos[l]);
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	for (ii x: val[2*k]) val[k].insert(x);
	for (ii x: val[2*k+1]) val[k].insert(x);
}
bool query(int k, int l, int r, int u, int v, ii x){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		return (val[k].find(x)!=val[k].end());
	}
	int m = (l+r)/2;
	return query(2*k,l,m,u,v,x)||query(2*k+1,m+1,r,u,v,x);
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
	}
	build(1,1,n);
//	for (auto it: val[1]) cout << it.first << "," << it.second << "\n"; 
//	cout << query(1,1,n,1,n,{-1,0});
	while (q--){
		int x, y, l, r;
		cin >> x >> y >> l >> r;
		ii tmp = {pos[l-1].first+pos[r].first-x,pos[l-1].second+pos[r].second-y};
		cout << (query(1,1,n,1,l-1,{x,y})||query(1,1,n,r,n,{x,y})||query(1,1,n,l,r-1,tmp)||ii{x,y}==ii{0,0}?"YES":"NO") << "\n";
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
