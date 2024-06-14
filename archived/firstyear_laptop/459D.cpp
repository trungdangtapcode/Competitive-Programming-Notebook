#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n, a[maxN];
int val[maxN], f[maxN], g[maxN];
void updt(int k, int v){
	for (; k <= n; k += k&-k) val[k] += v;
}
int query(int k){
	int res = 0;
	for (; k > 0; k -= k&-k) res += val[k];
	return res;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	unordered_map<int,int> mp;
	for (int i = 1; i<= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		f[i] = mp[a[i]];
	}
	mp.clear();
	for (int i = n; i > 0; i--){
		mp[a[i]]++;
		g[i] = mp[a[i]];
		updt(g[i],1);
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		updt(g[i],-1);
		res += query(f[i]-1);
	}
	cout << res;
	
	
	return 0;
}
