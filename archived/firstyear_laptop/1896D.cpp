#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e5+5;
int n, a[maxN], val[maxN], q;
void updt(int x, int v){
	for (; x <= n; x += x&-x) val[x] += v;
}
int gett(int x){
	int res= 0;
	x = min(x,n);
	for (; x; x -= x&-x) res += val[x];
	return res;
}
//string s;
bool check(int x){
	int l = 0, r = n, m;
	while (l<=r){
		m = (l+r)/2;
		int y = gett(m);
		if (y==x) return 1;
		if (y>x){
			r = m-1;
		} else l = m+1;
	}
	return gett(m)==x;
}
void solve(){
//	multiset<int> ms;
//	ms.insert(0);
	cin >> n >> q;
	set<int> s;
	for (int i = 1; i<= n; i++) val[i] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		updt(i,a[i]);
//		ms.insert(gett(i));
		if (a[i]==1) s.insert(i);
	}
	while (q--){
		int t, x, y;
		cin >> t;
		if (t==1){
			cin >> x;
			int sum = gett(n);
			if (sum<x){
				cout << "NO\n";
				continue;
			} 
			if (check(x)||check(sum-x)){
				cout << "YES\n";	
				continue;
			}
			if (s.empty()){
				cout << (x%2?"NO\n":"YES\n");
				continue;
			}
			int fi = *s.begin(), ed = *s.rbegin();
			int tmp = max(sum-gett(fi-1),gett(ed));
			if (tmp>=x){
				cout << "YES\n";
				continue;
			}
			cout << "NO\n";
		} else {
			cin >> x >> y;
//			ms.erase(ms.find(gett(x)));
			if (a[x]==1) s.erase(x);
			updt(x,-a[x]);
			a[x] = y;
			updt(x,a[x]);
			if (a[x]==1) s.insert(x);
//			ms.insert(gett(x));
//			for (int x: ms) cout << x << " "; cout << "\n";
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
