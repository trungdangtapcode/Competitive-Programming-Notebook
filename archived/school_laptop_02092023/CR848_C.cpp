#include<bits/stdc++.h>

using namespace std;
int n, k, f[100005];
string c, a, b;
long long calc(int mask){
//	cout << bitset<8>(mask) << "\n";
	for (int i = 0; i < n; i++){
		int x = lower_bound(c.begin(),c.end(),a[i])-c.begin();
		f[i] = (a[i]==b[i]||(mask&(1<<x)));
	}
	long long res = 0;
	for (int i = 0; i < n; i++){
		if (f[i]==0) continue;
		int j = i+1;
		while (f[j]&&j<n) j++;
		int l = j-i;
		res += 1ll*l*(l+1)/2;
		i = j-1;
	}
	return res;
}
void solve(){
	cin >> n >> k >> a >> b;
	c = a;
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	long long res = 0;
	for (int i = 0; i < (1<<c.length()); i++) if (__builtin_popcount(i)<=k) res = max(res,calc(i));
	cout << res << "\n";
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
