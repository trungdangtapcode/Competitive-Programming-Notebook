#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, bit[maxN], val[maxN*4], q;

void bit_updt(int x, int y){
	for (; x <= n; x += x&-x) (bit[x] += y)%=26;
}
void bit_range(int l, int r, int x){
	bit_updt(l,x);
	bit_updt(r+1,-x);
}
int bit_query(int x){
	int res = 0;
	for (; x > 0; x -= x&-x) (res += bit[x])%=26;
	return (res%26+26)%26;
}

void it_updt(int k, int l, int r, int u, int x){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	it_updt(2*k,l,m,u,x);
	it_updt(2*k+1,m+1,r,u,x);
	val[k] = val[2*k]||val[2*k+1];
}
int it_query(int k, int l, int r, int u, int v){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return it_query(2*k,l,m,u,v)||it_query(2*k+1,m+1,r,u,v);
}

void pos_update(int i){
	if (i>n||i<1) return;
	int cur = 0;
	if (i>1){
		cur |= bit_query(i-1)==bit_query(i);
	}
	if (i>2){
		cur |= bit_query(i-2)==bit_query(i);
	}
	it_updt(1,1,n,i,cur);
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) bit[i] = 0;
	for (int i = 1; i <= n*4; i++) val[i] = 0;
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		c = tolower(c);
		int a = c-'a';
		bit_range(i,i,a);
		pos_update(i);
	}
//	for (int i = 1; i <= n; i++) cout << it_query(1,1,n,i,i) << " "; cout << "\n";
	for (int i = 0; i < q; i++){
		int t, l, r, x;
		cin >> t;
		if (t==1){
			cin >> l >> r >> x;
			bit_range(l,r,x);
			pos_update(l);
			pos_update(l+1);
			pos_update(r+1);
			pos_update(r+2);
		} else {
			cin >> l >> r;
			if (l==r){
				cout << "YES\n";
				continue;
			}
			int res = it_query(1,1,n,l+2,r);
			res |= (bit_query(l)==bit_query(l+1));
			cout << (res?"NO\n":"YES\n");
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

