#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, m;
void solve(){
	cin >> n >> m;
	int x = 0, y = 0;
	set<int> s;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if (a==-1) x++;
		else if (a==-2) y++;
		else s.insert(a);
	}
	vector<int> v(s.begin(),s.end());
	int l = v.size();
	int curR = m-l, curL = 0;
	int res = max(x+l,y+l);
	for (int i = 0; i < l; i++){
		int a = v[i];
		int diff = v[i]-(i?v[i-1]:0)-1;
		curR -= diff;
		curL += diff;
		res = max(res,min(x,curL)+min(y,curR)+l);
	}
	if (res>m) res = m;
	cout << res << "\n";
//	exit(0);
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
//https://codeforces.com/contest/1824/problem/A
