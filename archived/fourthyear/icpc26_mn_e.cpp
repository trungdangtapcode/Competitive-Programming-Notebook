#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 6e6+5;
int k, q, w[N];
int val[4*N][2], lazy[4*N], l[4*N], r[4*N], ncnt=1, root=1;

void pushd(int idx){
	if (!l[idx]) return;
	if (!lazy[idx]) return;
	int ll = l[idx], rr = r[idx];
	lazy[ll] ^= 1, lazy[rr] ^= 1;
	swap(val[ll][0], val[ll][1]);
	swap(val[rr][0], val[rr][1]);
	lazy[idx] = 0;
}

void updt(int idx, int ll, int rr, int kk, int u, int v){
	if (ll>v||rr<u) return;
	if (u<=ll&&rr<=v){
		swap(val[idx][0], val[idx][1]);
		lazy[idx] ^= 1;
		return;
	}
	int mm = (ll+rr)/2;
	if (!l[idx]){
		l[idx] = ++ncnt;
		val[l[idx]][1] = w[kk-1];
		r[idx] = ++ncnt;
		val[r[idx]][1] = w[kk-1];
	}
	pushd(idx);
	updt(l[idx], ll, mm, kk-1, u, v);
	updt(r[idx], mm+1, rr, kk-1, u, v);
	val[idx][0] = min({val[l[idx]][0]+val[r[idx]][0], val[l[idx]][1]+val[r[idx]][1]+w[kk]});
	val[idx][1] = min({val[l[idx]][1]+val[r[idx]][1], val[l[idx]][0]+val[r[idx]][0]+w[kk]});
}

void solve(){
	cin >> k >> q;
	for (int i = 0; i <= k; i++){
		cin >> w[i];
		if (i) w[i] = min(w[i],w[i-1]<<1);
	}
	val[root][1] = w[k];
	while (q--){
		int l, r;
		cin >> l >> r;
		updt(root, 0, (1ll<<k)-1, k, l, r);
		cout << val[root][0] << "\n";
	}
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

