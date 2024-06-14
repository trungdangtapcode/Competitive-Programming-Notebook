#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN], val[maxN], b[maxN];
void updt(int x, int v){
	for (; x <= n; x += x&-x) val[x] += v;
}
void rs(){
	for (int i = 1; i <= n; i++) val[i] = 0;
	for (int i = 1; i <= n; i++) updt(i,1);
}
int gett(int x){
	int res = 0;
	for (; x > 0; x -= x&-x) res += val[x];
	return res;
}
int query(int l, int r){
	if (l<=r) return gett(r)-gett(l-1);
	else return gett(n)-gett(l-1)+gett(r);
}
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	b[n+1] = n;
	rs();
	vector<int> vec;
	for (int i = n; i >= 1; i--){
		updt(b[i],-1);
		int x = b[i+1];
		int res = (i-query(b[i],x))%i;
//		cout << res << " " << query(b[i],x) << "\n";
		vec.push_back(res);
	}
	reverse(vec.begin(),vec.end());
	for (int x: vec) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

