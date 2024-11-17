#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
int n, cha[maxN], a[maxN], mmax[maxN];
typedef pair<int,int> ii;
int timcha(int x){
	return (cha[x]==x?x:cha[x]=timcha(cha[x]));
}
void hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return;
	cha[u] = v;
	mmax[v] = max(mmax[u],mmax[v]);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cha[i] = i, mmax[i] = a[i];
	multiset<ii> ms;
	set<ii> st;
	for (int i = 1; i <= n; i++){
		while (ms.size() && ms.upper_bound({a[i],1e9})!=ms.end()){
			auto it = ms.upper_bound({a[i],1e9});
			hop((*it).second,i);
//			cout << i << " -> " << (*it).second << "\n";
			ms.erase(it);
		}
		if (st.size() && st.upper_bound({a[i],1e9})!=st.end()){
			auto it = st.upper_bound({a[i],1e9});
			hop((*it).second,i);
//			cout << i << " -> " << (*it).second << "\n";
		}
		ms.insert({a[i],i});
		st.insert({a[i],i});
	}
	for (int i = 1; i <= n; i++){
		int u = timcha(i);
//		cout << i << " " << u << "\n";
		cout << mmax[u] << " ";
	}
	cout << "\n";
//	exit(0);
}

int32_t main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

