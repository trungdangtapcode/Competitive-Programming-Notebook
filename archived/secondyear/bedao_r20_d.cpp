#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
typedef pair<int,int> ii;
ii val[maxN*4];
int lazy[maxN*4], a[maxN], n, k, d, v[maxN];
void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k].first += lazy[k];
	val[2*k+1].first += lazy[k];
	lazy[k] = 0;
}
void merge(int k){
	val[k].first = max(val[2*k].first,val[2*k+1].first);
	val[k].second = (val[2*k].first==val[k].first)*val[2*k].second
		+ (val[2*k+1].first==val[k].first)*val[2*k+1].second;
//	cout << k << " " << val[k].first << " " << val[2*k].second << "\n";
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
//	cout << k << " " << l << " " << r<< " " << u << " " <<v  << "\n";
	if (u<=l&&r<=v){
		val[k].first += x;
		val[k].second = l==r;
//		cout << k << " = " << val[k].second << "\n";
		lazy[k] += x;
		return;
	}
	down(k);
	int m = (l+r)>>1;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	merge(k);
}
int getpos(int k, int l, int r){
	if (l==r) return l;
	int m = (l+r)/2;
	if (val[2*k].first>=val[2*k+1].first)
		return getpos(2*k,l,m);
	else return getpos(2*k+1,m+1,r);
}

void solve(){
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(1,1,n,i,i,a[i]-i);
//		break;
	}
	for (int i = 1; i <= k; i++) cin >> v[i];
	while (val[1].first>0){
		int p = getpos(1,1,n);
		updt(1,1,n,p,p,-1e9);
	}
	int res = (val[1].first==0)*val[1].second+(d-1)/2;
	for (int day = 1; day <= min(3*n,d); day++){
		int x = (day-1)%k+1;
		while (val[1].first>0){
			int p = getpos(1,1,n);
			updt(1,1,n,p,p,-1e9);
		}	
		int cur = 0;
        if(val[1].first == 0) cur = val[1].second;
        res = max(res,cur+(d-(day+1))/2);
	}
	cout << res;
	
//	cout << res << "\n";
//	cout << val[1].second << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

