#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], cnt[20], cur;

void add(int x){
	for (int i = 0; i < 20; i++) if (x>>i&1){
		cnt[i]++;
		if (cnt[i]==1) cur++;
	}
}
void del(int x){
	for (int i = 0; i < 20; i++) if (x>>i&1){
		if (cnt[i]==1) cur--;
		cnt[i]--;
	}
}

void solve(){
	cin >> n;
	int ss = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ss |= a[i];
	}
	int num = __builtin_popcount(ss);
	int res = 1;
	memset(cnt,0,sizeof(cnt));
	cur = 0;
	int last = 0;
	for (int i = 1, r = 0; i <= n; i++){
		while (cur < num && r < n){
			r++;
			add(a[r]);
		}
		if (cur==num)
			res = max(res,r-i+1), last = i;
		else res = max(res,n-last+1);
		del(a[i]);
	}
	cout << res << "\n";
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

