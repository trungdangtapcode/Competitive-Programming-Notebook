#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int n, a[maxN], sz[maxN], cha[maxN], prv[maxN], sum[maxN], nxt[maxN];

struct dsu{
	dsu(){
		for (int i = 1; i <= n; i++){
			cha[i] = i;
			sz[i] = 1;
			sum[i] = a[i];
			nxt[i] = (i)%n+1;
			prv[i] = (i-2+n)%n+1;
		}
	}
	int timcha(int u){
		return (u==cha[u]?u:cha[u]=timcha(cha[u]));
	}
	void hop(int u, int v){
		u = timcha(u), v= timcha(v);
		if (u==v) return;
		cha[v] = u;
		sum[u] += sum[v];
		sz[u] += sz[v];
		nxt[u] = nxt[v];
	}
};

bool check(int x){
	dsu d;
	for (int i = 1; i <= n; i++) if (a[i]<=x){
		while (1){
			int u = d.timcha(i);
			if (sz[u]==n) return 1;
			int fw = d.timcha(nxt[u]), bw = d.timcha(prv[u]);
			if (x+sum[u]>=sum[bw]) d.hop(bw,u);
			else if (x+sum[u]>=sum[fw]) d.hop(u,fw);
			else break;
		}
	}
	return 0;
}

main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int l = 0, h = 1e14, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)) res = m, h = m-1;
		else l = m+1;
	}
	cout << res;
	
	return 0;
}

//nham de: https://oj.vnoi.info/src/3380250	
