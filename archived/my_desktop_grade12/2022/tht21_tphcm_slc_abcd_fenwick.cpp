/*
A: a 0 0 0 0
B: a a a a a
C: a 2a 3a 4a 5a
D: a 3a 6a 10a 15a
	(i-l)^2/2 + (i-l)/2
    i^2/2 + i(-l+1/2) - l/2 + l^2/2
*/

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7, inv2 = 1ll*(mod-mod/2)%mod;
struct bit{
	int val[400055], n;
	bit(int _n){
		n = _n+5;
		memset(val,0,sizeof(val));
	}
	void updt(int i, int v){
		for (; i < n; i += i&-i) (val[i] += v)%= mod;
	}
	int get(int i){
		int res = 0;
		for (; i > 0; i -= i&-i) (res += val[i])%= mod;
		return res;
	}
	void update(int l, int r, int v){
		updt(l,v);
		updt(r+1,mod-v);
	}
} f0(4e5), f1(4e5), f2(4e5);

void updt(int l, int r, int st, int mul){
	st--;
	f0.update(l,r,(-1ll*st*inv2%mod+1ll*st*st%mod*inv2%mod+mod)%mod*mul%mod);
	f1.update(l,r,1ll*(-st+inv2+mod)%mod*mul%mod);
	f2.update(l,r,1ll*inv2*mul%mod);
}
int gett(int pos){
	int res = 0;
	(res += f0.get(pos))%= mod;
	(res += 1ll*f1.get(pos)*pos%mod)%= mod;
	(res += 1ll*f2.get(pos)*pos%mod*pos%mod)%= mod;
	return res;
}
int n, a[400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(i,n,i,a[i]);
	}
	
	int q; cin >> q;
	while (q--){
		char c;
		int x, y;
		cin >> c >> x;
		if (c=='U'){
			cin >> y;
			int diff = (y-a[x])%mod;
			(diff += mod)%= mod;
			a[x] = y; 
			updt(x,n,x,diff);
		} else if (c=='B'){
			int x0 = gett(x-2), x1 = gett(x-1), x2 = gett(x);
			int res = (x2-x1)-(x1-x0);
			((res%= mod)+= mod)%=mod;
			cout << res << "\n";
		} else if (c=='C'){
			int x0 = gett(x-2), x1 = gett(x-1), x2 = gett(x);
			int res = (x2-x1);
			((res%= mod)+= mod)%=mod;
			cout << res << "\n";
		} else if (c=='D'){
			int x0 = gett(x-2), x1 = gett(x-1), x2 = gett(x);
			int res = x2;
			((res%= mod)+= mod)%=mod;
			cout << res << "\n";
		}
	}
	
	return 0;
}
