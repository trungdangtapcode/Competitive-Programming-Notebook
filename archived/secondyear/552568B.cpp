#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, k, a[maxN];
bool check(int x){
	int res =0;
	for (int i =1; i <= n; i++) res += min(x,a[i]);
	return res<=k;
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += a[i];
	}
	if (sum<k){
		cout << -1 << "\n";
		return;
	}
	int l = 0, h = 1e14, m, ans;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			l = m+1;
			ans = m;
		} else h = m-1;
	}
	for (int i = 1; i <= n; i++){
		k -= min(a[i],ans);
		a[i] -= min(a[i],ans);
	}
	deque<int> d;
	for (int i = 1; i <= n; i++){
		if (a[i]>0) d.push_back(i);
	}
	while (k){
		int p = d.front(); d.pop_front();
		a[p]--;
		k--;
		if (a[p]>0) d.push_back(p);
	}
	while (d.size()){
		cout << d.front() << " ";
		d.pop_front();
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}
//https://codeforces.com/contest/84/B

