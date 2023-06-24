#include <bits/stdc++.h>

using namespace std;
long long int val[400005], lazy[400005];
int l[100005], r[100005], d[100005];
int n, m;
const long long int INF = 1e15;

void downT(int k){
	val[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updateT(int k, int l, int r, int u, int v, int x){
	if (r<u||l>v) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	downT(k);
	int m = (l+r)/2;
	updateT(2*k,l,m,u,v,x);
	updateT(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}
long long int getT(int k, int l, int r, int u, int v){
	if (r<u||l>v) return -INF;
	if (u<=l&&r<=v){
		return val[k];
	}
	downT(k);
	int m = (l+r)/2;
	return max(getT(2*k,l,m,u,v),getT(2*k+1,m+1,r,u,v));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> l[i] >> r[i] >> d[i];
		updateT(1,1,n,l[i],r[i],d[i]);
	}
	long long int res = INF;
	for (int i = 0; i < m; i++){
		updateT(1,1,n,l[i],r[i],-d[i]);
		res = min(res,getT(1,1,n,1,n));
		updateT(1,1,n,l[i],r[i],d[i]);
	}
	cout << res;
	//for (int i = 1; i <= n; i++) cout << getT(1,1,n,i,i) << " ";
	
	return 0;
}
