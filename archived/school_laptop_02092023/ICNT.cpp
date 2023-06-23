#include<bits/stdc++.h>

using namespace std;
#define int long long

multiset<int> s[200005];
int val[200005], n, a[200005], q, x, y, tmp = 0;
void build(int k, int l, int r){
	if (l==r){
		s[k].insert(a[l]);
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	for (auto x: s[2*k+1]){
		val[k] += distance(s[2*k].upper_bound(x),s[2*k].end());
	}
	val[k] += val[2*k]+val[2*k+1];
	s[k] = s[2*k];
	s[k].insert(s[2*k+1].begin(),s[2*k+1].end());
}
void updt(int k, int l, int r, int u, int x, int y){
	if (l>u||r<u) return;
	if (l==r){
		s[k].erase(s[k].find(x));
		s[k].insert(y);
		return;
	}
	int m = (l+r)/2;
//	int tmp = 0;
	if (u<=m){
		updt(2*k,l,m,u,x,y);
		tmp -= distance(s[2*k+1].begin(),s[2*k+1].lower_bound(x));
		tmp += distance(s[2*k+1].begin(),s[2*k+1].lower_bound(y));
	} else {
		updt(2*k+1,m+1,r,u,x,y);
		tmp -= distance(s[2*k].upper_bound(x),s[2*k].end());
		tmp += distance(s[2*k].upper_bound(y),s[2*k].end());
	}
	s[k].erase(s[k].find(x));
	s[k].insert(y);
//	cout << l << " " <<r << " " << distance(s[2*k+1].begin(),s[2*k+1].lower_bound(y)) << endl;
//	for (auto x: s[2*k+1]) cout << x <<"-"; cout << endl;
//	cout << "find " << x << endl;
//	val[k] += tmp;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
//	updt(1,1,n,1,4,1);
//	updt(1,1,n,2,3,1);
	cin >> q;
	int sum = 0;
	while (q--){
		cin >> x >> y;
		y = (y+sum)%2000000001-1000000000;
//		tmp = 0;
		updt(1,1,n,x,a[x],a[x]+y);
		a[x] = a[x]+y;
		cout << val[1]+tmp << "\n";
		sum += val[1]+tmp;
	}
	
//	cout << val[1];
//	for (auto x: s[1]) cout << x << " ";
	
	return 0;
}
