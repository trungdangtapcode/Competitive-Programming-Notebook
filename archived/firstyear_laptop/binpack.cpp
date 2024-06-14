#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> ii;
const int maxN = 1e6+5;
int n, l, a[maxN];
ii f[maxN], g[maxN];
//gp_hash_table<int,ii> f, g;
int main(){
	cin >> l >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n<=20){
		int ans = 1e9;
		for (int mask = 0; mask < (1<<n); mask++){
			int s[] = {0,0}, res = 0;
			for (int i = 0; i < n; i++){
				bool c = ((mask>>i)&1);
				if (s[c]+a[i]>l) res++, s[c] = 0;
				s[c] += a[i];
			} 
			for (int i = 0; i < 2; i++) if (s[i]) res++;
			ans = min(ans,res);
		}
		cout << ans << "\n";
		return 0;
	}
	for (int i = 1; i <= n; i++){
		for (int x = 0; x <= l; x++) f[x] = {1e9,0};
		for (int x = 0; x <= l; x++){
			f[x] = min(f[x],
				ii{g[x].first+(g[x].second+a[i]>l),g[x].second+a[i]>l?a[i]:g[x].second+a[i]});
			f[x+a[i]>l?a[i]:x+a[i]] = min(f[x+a[i]>l?a[i]:x+a[i]],
				ii{g[x].first+(x+a[i]>l),g[x].second});
		}
		for (int x = 0; x <= l; x++) g[x] = f[x];
	}
	int res = 1e9;
	for (int x = 0; x <= l; x++){
		res = min(res,f[x].first+(f[x].second!=0)+(x!=0));
	}
	
	cout << res  << "\n";
	return 0;
}

/*
	vector<int> q;
	q.push_back(0);
	g[0] = {0,0};
	for (int i = 1; i <= n; i++){
		vector<int> tmp;
		for (int x: q) f[x] = f[x+a[i]>l?0:x+a[i]] = {1e9,0}; 
		for (int x: q){
//			int x = q.front(); q.pop();
			f[x] = min(f[x],
				ii{g[x].first+(g[x].second+a[i]>l),g[x].second+a[i]>l?a[i]:g[x].second+a[i]});
			f[x+a[i]>l?a[i]:x+a[i]] = min(f[x+a[i]>l?a[i]:x+a[i]],
				ii{g[x].first+(x+a[i]>l),g[x].second});
			tmp.push_back(x);
			tmp.push_back(x+a[i]>l?a[i]:x+a[i]);
		}
		sort(tmp.begin(),tmp.end());
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
		for (int x: tmp) g[x] = f[x];
		q.clear();
		for (int x: tmp) q.push_back(x);
	}
	int res = 1e9;
	for (int x: q){
		res = min(res,f[x].first+(f[x].second!=0)+(x!=0));
	}
*/
