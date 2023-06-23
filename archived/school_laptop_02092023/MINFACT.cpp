#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define int long long
int spf[1000005], k, a;
map<int,int> mp;
int cur, p, cnt, tmp;
vector<pair<int,int>> v;
bool check(int n){
	for (auto it: v){
		cur = 0, p = it.first, cnt = it.second, tmp = n;
		while (tmp>1){
			cur += (tmp/p);
			tmp /= p;
		}
		if (cur<cnt*k) return 0;
	}
	return 1;
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	freopen("MINFACT.INP","r",stdin);
	freopen("MINFACT.OUT","w",stdout);
	
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e6; i++) if (spf[i] == i) for (int j = i*i; j <= 1e6; j+=i) spf[j] = i;
	
	int t; cin >> t;
	while (t--){
		cin >> a >> k;
		int l = 0, h = a*k, m, res;
		mp.clear();
		v.clear();
		while (a>1){
			mp[spf[a]]++;
			a /= spf[a];
		}
		for (auto it: mp){
			v.push_back(it);
		}
		while (l<=h){
			m = (l+h)>>1;
			if (check(m)){
				h = m-1;
				res = m;
			} else l = m+1;
		}
		cout << res << "\n";
	}
	
	return 0;
}
