#include<bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005];
vector<int> edge[100005];
bool d[100005];
const int p =  998244353;

bool khuyen = 0;
bool dfs(int p, int u){
	d[u] = 1;
	bool res = false;
	for (int v: edge[u]) if (v!=p){
		khuyen |= (v==u);
		res |= d[v];
		if (d[v]) continue;
		res |= dfs(u,v);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) edge[i].clear(), d[i] = 0;
		int res = 1;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0, u, v; i < n; i++){
			u = a[i], v = b[i];
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			if (!d[i]){
				khuyen = 0;
				bool tmp = dfs(0,i);
//				cout << i << " with " << tmp << " khuyen:" << khuyen << endl;
				if (tmp){
					if (khuyen) res = 1ll*n*res%p;
					else res = 2*res%p;
				} else res = 0;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
