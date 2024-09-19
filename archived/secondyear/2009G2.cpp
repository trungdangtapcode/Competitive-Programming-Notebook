#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, a[maxN], k, b[maxN], q, p[maxN];
int f[maxN][20], g[maxN][20];
void solve(){
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	set<int> stmp;
	for (int i = 1; i <= n; i++) a[i] -= i, stmp.insert(a[i]);
//	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
	multiset<int> ms;
	for (int i = 0; i < stmp.size(); i++) ms.insert(0);
	map<int,int> mp;
	for (int i = 1, j = 0; i <= n-k+1; i++){
		while (j<i+k-1){
			j++;
			ms.erase(ms.find(mp[a[j]]));
			mp[a[j]]++;
			ms.insert(mp[a[j]]);
		};
		int x = *ms.rbegin();
		b[i] = x;
//		cout << i << ": ";
//		for (int x: ms) cout << x << " "; cout << "\n";
//		cout << b[i] << " ";
		ms.erase(ms.find(mp[a[i]]));
		mp[a[i]]--;
		ms.insert(mp[a[i]]);
	}
	n -= k-1;
	deque<int> dq;
	for (int i = n; i >= 1; i--){
		while (dq.size()&&b[dq.back()]<=b[i])
			dq.pop_back();
		if (dq.size()) p[i] = dq.back();
		else p[i] = n+1;
		dq.push_back(i);
	}
	for (int i = 1; i <= n; i++) 
		g[i][0] = p[i], f[i][0] = (p[i]-i)*b[i];
	for (int l = 1; l < 20; l++){
		for (int i = 1; i <= n; i++){
			int nxt = g[i][l-1];
			if (nxt==n+1){
				g[i][l] = nxt;
				f[i][l] = f[i][l-1];	
				continue;
			}
			g[i][l] = g[nxt][l-1];
			f[i][l] = f[i][l-1]+f[nxt][l-1];
		}
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		r -= k-1;
		int len = r-l+1;
		int ptr = l;
		int res = 0;
		for (int l = 19; l >= 0; l--){
			int nxt = g[ptr][l];
			if (nxt>r) continue;
			res += f[ptr][l];
			ptr = nxt;
		}
		cout << len*k-res-(r-ptr+1)*b[ptr] << "\n";
	}
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
//https://pastebin.pl/view/3bcb7984
