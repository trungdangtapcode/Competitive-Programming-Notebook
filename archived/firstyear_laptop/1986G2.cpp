#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
int n, a[maxN], cnt[maxN], dfn[maxN];
basic_string<int> divs[maxN], v[maxN], iv[maxN]; 
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) v[i] = iv[i] = {};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		int g = __gcd(a[i],i), x = i/g, y = a[i]/g;
		v[x] += y;
		iv[y] += x;
//		cout << x << " -> " << y << "\n";
	}
	for (int i = 1; i <= n; i++) dfn[i] = -1, cnt[i] = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++){
		//upd: i -> a[i] -> j|a[i]
		//get: j -> a[i]|j -> i
		for (int ai: v[i]) for (int j: divs[ai]){
			if (dfn[j]!=i) cnt[j] = 0, dfn[j] = i;
			cnt[j]++;
//			cout << i << " -> " << ai << " -> " << j << " set \n"; 
		}
		for (int aj = i; aj <= n; aj += i) for (int j: iv[aj]){
			if (dfn[j]!=i) cnt[j] = 0, dfn[j] = i;
			res += cnt[j];
//			cout << i << " -> " << aj << " -> " << j << " get " << cnt[j] << " \n"; 
		}
	}
	for (int i = 1; i <= n; i++) res -= (a[i]%i==0);
	cout << res/2 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 5e5; i++){
		for (int j = i; j <= 5e5; j += i) divs[j] += i;
	}
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

