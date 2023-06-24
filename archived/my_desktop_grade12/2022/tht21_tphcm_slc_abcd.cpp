#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
typedef pair<long long, long long> ii;
ii operator+(const ii& a, const ii& b){
	return {(a.first+b.first)%mod,(a.second+b.second)%mod};
}
ii& operator+=(ii& a, const ii& b){
	return a = (a+b);
}
ii& operator*=(ii& a, const int& b){
	a = {a.first*b, a.second*b};
	return a;
}
ostream& operator<<(ostream& cout, const ii& x){
	cout << x.first << ", " << x.second << "\n";
	return cout;
}
long long sumToN(int n){
	return 1ll*n*(n+1)/2%mod;
}
long long sumRange(int l, int r){
	return (sumToN(r)-sumToN(l-1));
}
int n;
long long val[2000005], a[2000005];
ii lazy[2000005];

void down(int k, int l, int r, int m){
	if (lazy[k]==ii{0,0}||l==r) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	(val[2*k] += sumRange(l,m)*lazy[k].first+(m-l+1)*lazy[k].second)%=mod;
	(val[2*k+1] += sumRange(m+1,r)*lazy[k].first+(r-m)*lazy[k].second)%=mod;
	lazy[k] = {0,0};
}

void updt(int k, int l, int r, int u, int v, long long x, long long y){
	if (l>v||u>r) return;
	if (u<=l&&r<=v){
		(val[k] += sumRange(l,r)*x + (r-l+1)*y)%=mod;
		lazy[k] += {x,y};		
		return;
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	updt(2*k,l,m,u,v,x,y);
	updt(2*k+1,m+1,r,u,v,x,y);
	val[k] = (val[2*k] + val[2*k+1])%mod;
}
long long gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return 0;
	if (u<=l&&r<=v){
		return val[k];
	}
	int m = (l+r)/2;
	down(k,l,r,m);
	return (gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v))%mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(1,1,n,i,n,a[i],-(i-1)*a[i]%mod);
	}
	int q; cin >> q;
	while (q--){
		char c;
		long long i, y;
		cin >> c >> i;
		if (c=='U'){
			cin >> y;
			updt(1,1,n,i,n,(y-a[i]),-(i-1)*(y-a[i])%mod);
			a[i] = y;
		} else if (c=='C'){
			cout << (gett(1,1,n,i,i)%mod+mod)%mod << "\n";
		} else if (c=='D'){
			cout << (gett(1,1,n,1,i)%mod+mod)%mod << "\n";
		} else if (c=='B'){
			long long x0 = gett(1,1,n,i-1,i-1), x1 = gett(1,1,n,i,i);
			cout << ((x1 - x0)%mod+mod)%mod << "\n";
		} else if (c=='A'){
			long long x0 = gett(1,1,n,i-2,i-2), x1 = gett(1,1,n,i-1,i-1), x2 = gett(1,1,n,i,i);
			cout << (((x2-x1)-(x1-x0))%mod+mod)%mod << "\n";
		}
	}
	
	
	return 0;
}
