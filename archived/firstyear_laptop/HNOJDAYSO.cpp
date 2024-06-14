#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5, T = 2e14;
map<int,int> mp;
int to[maxN*50][2], cnt[maxN*50], ntrie = 0;
int n, a[maxN], h[maxN], pref[maxN];
struct Trie{
	int root;
	Trie(){
		root = ++ntrie;
	}
	void push(int x){
		int u = root;
		cnt[u]++;
		for (int i = 48; i >= 0; i--){
			int c = (x>>i)&1;
			if (to[u][c]==0) to[u][c] = ++ntrie;
			u = to[u][c];
			cnt[u]++;
		}
	}
	int query(int x){
		int u = root, res = 0;
		for (int i = 48; i >= 0; i--){
			int c = (x>>i)&1;
			if (c&&to[u][!c]!=0) res += cnt[to[u][!c]];
			if (to[u][c]==0) return res;
			u = to[u][c];
		}
		return res;
	}
};
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}
vector<Trie> tree;

main(){
//	Trie x;
//	x.push(2);
//	cout << x.query(3) << "\n";
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
//	n = 2e5;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
//		a[i] = Rand(-100,100);
		pref[i] = pref[i-1] + a[i];
		if (mp.count(a[i])) continue;
		mp[a[i]] = 1ll*rd()/500*rd();
//		cout << a[i] << ". " << mp[a[i]] << "\n";
	}
//	cout << "hi";
	int cur = 0;
	h[0] = 0;
	vector<int> vec;
	vec.push_back(0);
	for (int i = 1; i <= n; i++){
		cur ^= mp[a[i]];
		h[i] = cur;
		vec.push_back(h[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 0; i <= n; i++) h[i] = lower_bound(vec.begin(),vec.end(),h[i])-vec.begin();
	for (int i = 0; i <= n; i++) tree.push_back(Trie());
//	cout << "hi\n";
	//h[j-1] = h[i] => [j..i] thoa (1)
	//pref[i] > pref[j-1] => thoa (2)
	tree[0].push(0+T);
	int res = 0;
	for (int i = 1; i <= n; i++){
//		if (i%10000==0) cout << i << "\n";
		res += tree[h[i]].query(pref[i]+T);
		tree[h[i]].push(pref[i]+T);
	}
	cout << res;
	
	
	return 0;
}
