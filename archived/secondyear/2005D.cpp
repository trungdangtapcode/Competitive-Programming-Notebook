#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, a[maxN], b[maxN], sa[maxN], sb[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sa[n+1] = sb[n+1] = 0;
	for (int i = n; i >= 1; i--){
		sa[i] = __gcd(sa[i+1],a[i]);
		sb[i] = __gcd(sb[i+1],b[i]);
	}
	map<ii, long long> f0[2], f1[2];
	f0[0][{0,0}] = 1;
	int res1 = 0;
	long long res2 = 1;
	for (int i = 1; i <= n; i++){
		for (auto it: f0[0]){
			int pa = it.first.first, pb = it.first.second;
			int ways = it.second;
			int pa0 = __gcd(pa, a[i]);
			int pb0 = __gcd(pb, b[i]);
			f1[0][{pa0, pb0}] += ways;
			int pa1 = __gcd(pa, b[i]);
			int pb1 = __gcd(pb, a[i]);
			f1[1][{pa1, pb1}] += ways;
		}
		for (auto it: f0[1]){
			int pa = it.first.first, pb = it.first.second;
			int ways = it.second;
			int pa1 = __gcd(pa, b[i]);
			int pb1 = __gcd(pb, a[i]);
			f1[1][{pa1,pb1}] += ways;
		}
		for (auto it: f1[1]){
			int pa = it.first.first, pb = it.first.second;
			int ways = it.second;
			pa = __gcd(pa,sa[i+1]);
			pb = __gcd(pb,sb[i+1]);
			int val = pa+pb;
			if (res1<val) res1 = val, res2 = 0;
			if (res1==val) res2 += ways;
		}
		f0[0] = f1[0];
		f0[1] = f1[1];
		f1[0] = {};
		f1[1] = {};
	}
	cout << res1 << " " << res2 << "\n";
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

