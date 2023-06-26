#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
struct itmax{
	int val[400005], n;
	itmax(int _n){
		n = _n;
		memset(val,0,sizeof(val)); //then -1
	}
	void updt(int k, int l, int r, int u, int x){
		if (u>r||u<l) return;
		if (l==r){
			val[k] = x;
			return;
		}
		int m = (l+r)/2;
		updt(2*k,l,m,u,x);
		updt(2*k+1,m+1,r,u,x);
		val[k] = max(val[2*k],val[2*k+1]);
	}
	int gett(int k, int l, int r, int u, int v){
		if (u>r||v<l) return -1;
		if (u<=l&&r<=v) return val[k];
		int m = (l+r)/2;
		return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
	}
	void update(int u, int x){
		updt(1,1,n,u,x);
	}
	int query(int u, int v){
		return gett(1,1,n,u,v);
	}
} pos(1);
struct bitsum{
	int val[100005], n;
	bitsum(int _n){
		n = _n;
		memset(val,0,sizeof(val));
	}
	void update(int u, int x){
		for (; u <= n; u += u&-u) val[u] += x;
	}
	int query(int u){
		int res = 0;
		for (; u; u -= u&-u) res += val[u];
		return res;
	}
	int query(int u, int v){
		return query(v)-query(u-1);
	}
} pref(1);
struct node{
	int minl = -1, minr = -1, sum = 0, maxl = -1, maxr = -1, 
	minp = 1e9, maxp = -1e9, mins = 1e9, maxs = -1e9, 
	maxsum = -1e9, minsum = 1e9, maxpos1 = -1, maxpos2 = -1, minpos1 = -1, minpos2 = -1;
	ii res = {-1,-1};
	node operator+(node x){
		node res;
		res.sum = sum + x.sum;
		res.minp = min(minp,x.minp+sum);
		res.minl = (minp<x.minp+sum?minl:x.minl);
		res.mins = min(mins+x.sum,x.mins);
		res.minr = (mins+x.sum<x.mins?minr:x.minr);
		res.maxp = max(maxp,x.maxp+sum);
		res.maxl = (maxp>x.maxp+sum?maxl:x.maxl);
		res.maxs = max(maxs+x.sum,x.maxs);
		res.maxr = (maxs+x.sum>x.maxs?maxr:x.maxr);
		res.maxsum = max({maxs+x.maxp,maxsum,x.maxsum});
		res.minsum = min({mins+x.minp,minsum,x.minsum});
		if (maxs+x.maxp==res.maxsum){
			res.maxpos1 = maxr;
			res.maxpos2 = x.maxl;
		} else if (maxsum==res.maxsum){
			res.maxpos1 = maxpos1;
			res.maxpos2 = maxpos2;
		} else {
			res.maxpos1 = x.maxpos1;
			res.maxpos2 = x.maxpos2;
		}
//		if (res.minsum==-3){
//			cout << "there -3\n";
//			cout << minr << "\n";
//		}
		if (mins+x.minp==res.minsum){
			res.minpos1 = minr;
			res.minpos2 = x.minl;
		} else if (minsum==res.minsum){
			res.minpos1 = minpos1;
			res.minpos2 = minpos2;
		} else {
			res.minpos1 = x.minpos1;
			res.minpos2 = x.minpos2;
		}
		return res;
	}
} val[400005];
int n, k0, a[100005], q;
void updt(int k, int l, int r, int u, int v){
	if (u>r||u<l) return;
	if (l==r){
		node x;
		x.minl = x.minr = x.maxl = x.maxr = x.maxpos1 = x.maxpos2 = x.minpos1 = x.minpos2 = u, 
		x.sum = x.minp = x.mins = x.maxp = x.maxs = x.maxsum = x.minsum = v;
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v);
	updt(2*k+1,m+1,r,u,v);
	val[k] = val[2*k]+val[2*k+1];
}
ii solve(int l, int r){
//	cout << pref.query(l,r) << " climax\n";
	int l0 = l, r0 = r;
	int prefl = pref.query(l-1);
	int x = prefl + k0;
	while (l<=r){
		int m = (l+r)/2;
		int tmp1 = (pref.query(m)-x);
		int tmp2 = (pref.query(l)-x);
		int tmp3 = (pref.query(r)-x);
		if (tmp1==0) return {l0,m};
		if (tmp1*tmp2<=0){ //<= not <
			r = m-1;
		} else l = m+1;
	}
	cout << l0 << ".." << r0 << "\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
	for (int i = 1; i <= n; i++) cout << pref.query(i) << " "; cout << "\n";
	cout << "error\n";
	assert(0);
	return {-1,-1};
}
node findd(int k, int l, int r, int u, int v){
	if (u>r||v<l){
		node x;
		return x;
	}
	if (u<=l&&r<=v){
		node x = val[k];
//		cout << x.minsum << " " << x.minpos1 << " " << x.minpos2 << "--\n";
		if (k0>0&&x.maxsum>=k0){
			x.res = solve(x.maxpos1,x.maxpos2);
		} else if (k0<0&&x.minsum<=k0){
			x.res = solve(x.minpos1,x.minpos2);
		}
		return x;
	}
	int m = (l+r)/2;
	node tmp1 = findd(2*k,l,m,u,v);
	if (tmp1.res.first!=-1) return tmp1;
	node tmp2 = findd(2*k+1,m+1,r,u,v);
	if (tmp2.res.first!=-1) return tmp2;
	node x = tmp1 + tmp2;
	if (k0>0&&x.maxsum>=k0){
		x.res = solve(x.maxpos1,x.maxpos2);
	} else if (k0<0&&x.minsum<=k0){
		x.res = solve(x.minpos1,x.minpos2);
	}
	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	pos.n = n; pref.n = n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i]*a[i-1]==-1) pos.update(i,i);
		else pos.update(i,-1);
		pref.update(i,a[i]);
		updt(1,1,n,i,a[i]);
	}
//	cout << val[1].maxpos1 << " " << val[1].maxpos2 << "\n";
//	k0 = -2;
//	ii x = solve(2,3);
//	cout << x.first << " " << x.second << "\n";
//	k0 = -2;
//	node y = findd(1,1,n,1,5);
//	ii x = y.res;
//	cout << x.first << " " << x.second << "\n";
//	return 0;
	while (q--){
		int p, u, v, x;
		cin >> p;
		if (p==1){
			cin >> u >> x;
			pref.update(u,x-a[u]);
			if (x*a[u-1]==-1) pos.update(u,u); else pos.update(u,-1);
			if (x*a[u+1]==-1) pos.update(u+1,u+1); else pos.update(u+1,-1);
			updt(1,1,n,u,x);
			a[u] = x;
//			cout << "updated\n";
//			for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
//			for (int i = 1; i <= n; i++) cout << pref.query(i) << " "; cout << "\n";
//			for (int i = 1; i <= n; i++) cout << pos.query(i,i) << " "; cout << "\n";
		} else {
			cin >> u >> v >> k0;
			if (k0==0){
				int x = pos.query(u+1,v);
				if (x==-1) cout << -1 << "\n";
				else cout << x-1 << " " << x << "\n";
			} else {
				node y = findd(1,1,n,u,v);
				ii x = y.res;
				if (x.first==-1) cout << -1 << "\n";
				else cout << x.first << " " << x.second << "\n";
			};
		}
	}
	
	return 0;
}
