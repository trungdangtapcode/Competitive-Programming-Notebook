#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int n, val1[maxN], val2[maxN], prv[maxN], b[maxN], a[maxN], f[maxN];
void rs(){
	for (int i = 1; i <= n+1; i++) val1[i] = val2[i] = -1e9;
}
void updt(int x, int y, int z){
	int tmp = x;
	for (; x <= n+1; x += x&-x) val1[x] = max(val1[x],y-z);
	x = tmp;
	for (; x > 0; x -= x&-x) val2[x] = max(val2[x],y+z);
}
int query1(int x){
	int res = -1e9;
	for (; x > 0; x-= x&-x) res = max(res,val1[x]);
	return res;
}
int query2(int x){
	int res = -1e9;
	for (; x <= n+1; x += x&-x) res = max(res,val2[x]);
	return res;
}

void solve(){
	cin >> n;
	rs();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) prv[i] = prv[i-1] + a[i];
	vector<int> vec;
	for (int i = 0; i <= n; i++) vec.push_back(prv[i]);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 0; i <= n; i++) b[i] = lower_bound(vec.begin(),vec.end(),prv[i])-vec.begin()+1;
	updt(b[0],0,0);
	int res = 0;
	map<int,int> mp;
	mp[b[0]] = 0;
	for (int i = 1; i <= n; i++){
		f[i] = max(query1(b[i]-1)+i, query2(b[i]+1)-i);
		if (mp.count(b[i])) f[i] = max(f[i],mp[b[i]]);
		updt(b[i],f[i],i);
		if (mp.count(b[i])) mp[b[i]] = max(mp[b[i]],f[i]);
		else mp[b[i]] = f[i];
//		cout << "f[" << i << "] = " << f[i] << "\n";
	}
	cout << f[n] << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

