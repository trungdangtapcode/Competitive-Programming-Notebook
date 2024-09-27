#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, q, a[maxN], cnt[maxN];
int f(int l, int r){
	if (l==0) return cnt[r];
	r = min(r,n);
	return cnt[r]-cnt[l-1];
}
int check(int x, int m){
	int sum = 0;
	for (int i = 0; i <= n; i += x){
		sum += f(i,i+m);
	}
	return sum>n/2;
}
void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cnt[a[i]]++;
	for (int i = 1; i <= n; i++){
		cnt[i] += cnt[i-1];
	}
	map<int,int> mp;
	while (q--){
		int x; cin >> x;
		if (mp.count(x)){
			cout << mp[x] << "\n";
			continue;
		}
		int l = 0, r = x-1, res = -1, m;
		while (l<=r){
			m = (l+r)>>1;
			if (check(x,m)){
				res = m;
				r = m-1;
			} else l = m+1;
		}
		mp[x] = res;
		cout << res << " ";
	}
	cout << "\n";
//	exit(0);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

