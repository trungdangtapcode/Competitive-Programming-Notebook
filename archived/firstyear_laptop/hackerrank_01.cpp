#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e7+5;
int n, val[maxN], f[maxN];
long long a[maxN];
void rs(){
	
}
void updt(int x, int y){
	for (; x <= n; x += x&-x) val[x] = max(val[x], y);
}
int query(int x){
	int res = -1;
	for (; x; x -= x&-x) res = max(res,val[x]);
	return res;
}

void solve(){
	cin >> n;
	vector<long long> vec;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) vec.push_back(a[i]);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(vec.begin(),vec.end(), a[i])-vec.begin()+1;
	int res = 0;
	for (int i = 1; i <= n; i++){
		f[i] = 1;
		f[i] = max(f[i],query(a[i]-1)+1);
		updt(a[i],f[i]);
		res = max(res,f[i]);
	}
	cout << res;
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

