#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, l[maxN], r[maxN], w[maxN], val[maxN*4], pref[maxN][30];

void updt(int k, int l, int r, int u, int x){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	val[k] = val[2*k]|val[2*k+1];
}
int gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		return val[k];
	}
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)|gett(2*k+1,m+1,r,u,v);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= 4*n; i++) val[i] = 0;
	for (int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
//		cout << bitset<6>(l[i]) << " " << bitset<6>(r[i]) << " => ";
		if (l[i]==r[i]) w[i] = r[i];
		else w[i] = r[i] - (r[i]&( (2<<__lg(l[i]^r[i])) -1));
		r[i] -= w[i];
		l[i] -= w[i];
		updt(1,1,n,i,w[i]);
		for (int j = 29; j >= 0; j--) pref[i][j] = pref[i-1][j] + (r[i]>>j&1);
//		cout << bitset<6>(w[i]) << " " << bitset<6>(l[i]) << " " << bitset<6>(r[i]) << "\n";
	}
	int q; cin >> q;
	while (q--){
		int x, y;
		cin >> x >> y;
		int res = gett(1,1,n,x,y);
		for (int i = 29; i >= 0; i--){
			int cnt = pref[y][i]-pref[x-1][i] + (res>>i&1);
			if (cnt>1){
				res |= (2<<i)-1;
				break;
			} else if (cnt==1){
				res |= (1<<i);
			}
		}
		cout << res << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
