#include <bits/stdc++.h>

using namespace std;

int n, q, a[500005], qr[500005], ql[500005];
int nxt[500005], prv[500005];
map<int,int> m;
int res[500005];
vector<pair<int,int>> val[2000005];

void update(int k, int l, int r, int x, int y){
	if (x<l||x>r) return;
	val[k].push_back({qr[y],y});
	if (l==r) return;
	int m = (l+r)/2;
	update(2*k,l,m,x,y);
	update(2*k+1,m+1,r,x,y);
}
void updateSweep(int k, int l, int r, int u, int v, int x, int y){
	if (v<l||u>r) return;
	if (u<=l&&r<=v){
		val[k].push_back({x,-1});
		val[k].push_back({y,-2});
		return;
	}
	int m = (l+r)/2;
	updateSweep(2*k,l,m,u,v,x,y);
	updateSweep(2*k+1,m+1,r,u,v,x,y);
}
void solve(int k, int l, int r){
	int cnt = 0;
	sort(val[k].begin(),val[k].end());
	for (auto it: val[k]){
		if (it.second==-1) cnt++;
		else if (it.second==-2) cnt--;
		else res[it.second] += cnt;
	}
	if (l==r) return;
	int m = (l+r)/2;
	solve(2*k,l,m);
	solve(2*k+1,m+1,r);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> ql[i] >> qr[i], update(1,1,n,ql[i],i);
	
	m.clear();
	for (int i = 1, pos; i <= n; i++){
		pos = 0;
		if (m.count(a[i])) pos = m[a[i]];
		prv[i] = pos;
		m[a[i]] = i;
	}
	prv[0] = 0;
	m.clear();
	for (int i = n, pos; i >= 1; i--){
		pos = n+1;
		if (m.count(a[i])) pos = m[a[i]];
		nxt[i] = pos;
		m[a[i]] = i;
	}
	nxt[n+1] = n+1;
	
	for (int i = 1; i <= n; i++){
		if (nxt[i]==n+1) continue;
		updateSweep(1,1,n,prv[i]+1,i,nxt[i],nxt[nxt[i]]);
	}
	
	solve(1,1,n);
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
	
	return 0;
}
