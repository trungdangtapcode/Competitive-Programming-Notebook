#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
const int base = 31;
const int p = 1e9+7;

int val[800005], pl[800005], pr[800005], lazy[800005];
int basepow[200005], invtpow[200005], invtnum[200005], prefpow[200005];

void build(int k, int l, int r){
	pl[k] = l; pr[k] = r;
	if (l==r){
		val[k] = 1ll*a[l]*basepow[l]%p;
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
void down(int k){
	if (lazy[k]==1){
		val[2*k] = ((prefpow[pr[2*k]]-prefpow[pl[2*k]-1])%p+p)%p;
		val[2*k+1] = ((prefpow[pr[2*k+1]]-prefpow[pl[2*k+1]-1])%p+p)%p;
		lazy[2*k] = lazy[2*k+1] = 1;
//		return;
	}
	if (lazy[k]==2){
		val[2*k] = (2ll*(prefpow[pr[2*k]]-prefpow[pl[2*k]-1])%p+p)%p;
		val[2*k+1] = (2ll*(prefpow[pr[2*k+1]]-prefpow[pl[2*k+1]-1])%p+p)%p;
		lazy[2*k] = lazy[2*k+1] = 2;
//		return;
	}
	lazy[k] = 0;
}
void update(int k, int l, int r, int u, int v, int x){
	if (u>r||v<l) return;
	if (u<=l&&r<=v){
		val[k] = (1ll*(prefpow[r]-prefpow[l-1])*x%p+p)%p;
		lazy[k] = x;
		return;
	}
	down(k);
	int m = (l+r)/2;
	update(2*k,l,m,u,v,x);
	update(2*k+1,m+1,r,u,v,x);
	val[k] = (val[2*k]+val[2*k+1])%p;
}
int getSum(int k, int l, int r, int u, int v){
	if (u>r||v<l) return 0;
	if (u<=l&&r<=v){
		return val[k];
	}
	down(k);
	int m = (l+r)/2;
	return (getSum(2*k,l,m,u,v)+getSum(2*k+1,m+1,r,u,v))%p;
}
int getHash(int l, int r){
	return 1ll*getSum(1,1,n,l,r)*invtpow[l-1]%p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//01 => [1,2]
	string s;
	cin >> s;
	n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; ++i){
//		char c;
//		cin >> c;
		a[i] = s[i]-'0'+1;
	}
	basepow[0] = 1;
	prefpow[0] = 1; //vloz
	for (int i = 1; i <= n; ++i) basepow[i] = 1ll*basepow[i-1]*base%p;
	for (int i = 1; i <= n; ++i) prefpow[i] = (prefpow[i-1]+basepow[i])%p;
	invtpow[0] = invtnum[0] = invtnum[1] = 1;
	for (int i = 2; i <= base; ++i) invtnum[i] = 1ll*invtnum[p%i]*(p-p/i)%p;
	for (int i = 1; i <= n; ++i) invtpow[i] = 1ll*invtpow[i-1]*invtnum[base]%p;
	
	build(1,1,n);
	
	int q, op, u, v, x;
	cin >> q;
	while (q--){
		cin >> op >> u >> v >> x;
		if (op==1){
			update(1,1,n,u,v,x+1);
		} else {
			cout << (getHash(u,u+x-1)==getHash(v,v+x-1));
//			cout <<"<=== " <<getHash(u,u+x-1) << " " << getHash(v,v+x-1) << endl;
		}
	}
	
//	update(1,1,n,4,5,1);
//	cout << getHash(2,3) << " " << getHash(6,7);
//	cout << invtnum[base];
	
	return 0;
}
