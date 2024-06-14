#include<bits/stdc++.h>

using namespace std;
#define int __int128
const int maxN = 5e5+5;
int n, a[maxN];
struct node{
	int sum = 0, suff = 0, pref = 0, maxsum = -1e9;
	node operator+(node x){
		node res;
		res.sum = sum + x.sum;
		res.suff = max(suff+x.sum,x.suff);
		res.pref = max(pref,sum+x.pref);
		res.maxsum = max({maxsum,x.maxsum,suff+x.pref});
		return res;
	}
} val[4*maxN];

void updt(int k, int l, int r, int u, int v){
	if (l>u||r<u) return;
	if (l==r){
		node x;
		x.sum = x.pref = x.suff = x.maxsum = v;
		val[k] = x;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,v);
	updt(2*k+1,m+1,r,u,v);
	val[k] = val[2*k] + val[2*k+1];
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long tmp;
	cin >> tmp;
	n = tmp;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		a[i] = tmp;
		updt(1,1,n,i,a[i]);
	}
	for (int i = 1, p; i <= n; i++){
		tmp = val[1].maxsum;
		cout << tmp << "\n";
		cin >> tmp;
		p = tmp;
		a[p] = -1e18;
		updt(1,1,n,p,a[p]);
	}
}
