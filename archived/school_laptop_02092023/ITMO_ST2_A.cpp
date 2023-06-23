#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, pref[400005], suff[400005], sum[400005], seg[400005];
void updt(int k, int l, int r, int x, int y){
	if (r<x||l>x) return;
	if (r==x&&l==x){
		seg[k] = sum[k] = pref[k] = suff[k] = y;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,y);
	updt(2*k+1,m+1,r,x,y);
	pref[k] = max(pref[2*k],pref[2*k+1]+sum[2*k]);
	suff[k] = max(suff[2*k+1],suff[2*k]+sum[2*k+1]);
	seg[k] = max({seg[2*k],seg[2*k+1],suff[2*k]+pref[2*k+1]});
	sum[k] = sum[2*k]+sum[2*k+1];
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		updt(1,1,n,i,a);
	}
	cout << max(seg[1],0ll) << "\n";
	int i, v;
	while (m--){
		cin >> i >> v;
		updt(1,1,n,i+1,v);
		cout << max(seg[1],0ll) << "\n";
	}
	
	return 0;
}
