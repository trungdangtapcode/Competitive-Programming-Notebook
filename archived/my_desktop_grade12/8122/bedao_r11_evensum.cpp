#include<bits/stdc++.h>

using namespace std;

int n, q, a[100005];
int val[400005], lazy[400005];
void down(int k, int l, int r, int m){
	int t = lazy[k];
	if (t==0) return;
	val[2*k] = (m-l+1)-val[2*k];
	val[2*k+1] = (r-m)-val[2*k+1];
	lazy[2*k] ^= t;
	lazy[2*k+1] ^= t;
	lazy[k] = 0;
}

void updt(int k, int l, int r, int u, int v, int x){
	if (x==0) return;
	if (l>v||r<u) return;
//	cout << u << " " << v << " " << l << " " << r << endl;
	if (u<=l&&r<=v){
		val[k] = (r-l+1)-val[k];
		lazy[k] ^= x;
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = val[2*k] + val[2*k+1];
}

int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	
	return gett(2*k,l,m,u,v) + gett(2*k+1,m+1,r,u,v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	updt(1,1,n+1,1,n+1,0);
	for (int i = 2; i <= n+1; i++){
		cin >> a[i-1];
		updt(1,1,n+1,i,n+1,a[i-1]%2);
	}
	for (int i = 1; i <=  n+1; i++) cout << gett(1,1,n+1,i,i) << " "; cout << endl;
//	for (int i = 1; i <= 100; i++) cout << i << " - " << val[i] << " " << lazy[i] << endl;
	while (q--){
		int p, x, y;
		cin >> p >> x >> y;
		if (p==1){
			if (a[x]%2==y%2) continue;
			updt(1,1,n+1,x+1,n+1,1);
			a[x] = y%2;
//			for (int i = 1; i <=  n+1; i++) cout << gett(1,1,n+1,i,i) << " "; cout << endl;
		} else {
			int cnt0 = gett(1,1,n+1,x,y+1), l = y-x+2, cnt1 = l-cnt0;
			cout << 1ll*cnt0*(cnt0-1)/2+1ll*cnt1*(cnt1-1)/2 << "\n";
		}
	}
	
	return 0;
}
