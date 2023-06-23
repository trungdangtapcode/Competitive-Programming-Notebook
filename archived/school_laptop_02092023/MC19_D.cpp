#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, s[200005], val[800005];
void updt(int k, int l, int r, int x, int y){
	if (l>x||r<x) return;
	if (l==r){
		val[k] = y;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,x,y);
	updt(2*k+1,m+1,r,x,y);
	val[k] = val[2*k]+val[2*k+1];
}
int srch(int k, int l, int r, int x){
	if (val[k]<x) return -1;
	if (l==r) return l;
	int m = (l+r)/2;
	if (x<val[2*k]) return srch(2*k,l,m,x); else return srch(2*k+1,m+1,r,x-val[2*k]);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) updt(1,1,n,i,i);
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	}
	vector<int> res;
	for (int i = n; i >= 1; i--){
		int x = srch(1,1,n,s[i]);
		updt(1,1,n,x,0);
//		cout << x << " ";
		res.push_back(x);
	}
	reverse(res.begin(),res.end());
	for (auto it: res) cout << it << " ";
	
	
	return 0;
}
