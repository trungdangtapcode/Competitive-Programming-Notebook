#include<bits/stdc++.h>

using namespace std;

int n, m;
map<pair<int,int>,bool> mp;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		if (u>v) swap(u,v);
		mp[{u,v}] = 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		int cur = 1, l = i-1, r = i+1;
		while (mp.count({l,r})) --l, ++r, cur += 2;
		res = max(res,cur);
		cur = 0,  l = i, r = i+1;
		while (mp.count({l,r})) --l, ++r, cur += 2;
		res = max(res,cur);
	}
	cout << res;
	
	return 0;
}
