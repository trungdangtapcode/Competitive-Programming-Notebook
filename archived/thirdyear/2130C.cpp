#include<bits/stdc++.h>

using namespace std;
const int maxN = 6e3+5;
int n, cha[maxN];

int timcha(int x){
	return x==cha[x]?x:cha[x]=timcha(cha[x]);
}
bool hop(int u, int v){
	u = timcha(u), v = timcha(v);
	if (u==v) return false;
	cha[v] = u;
	return true;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n*2; i++) cha[i] = i;
	vector<int> res;
	for (int i = 1; i <= n; i++){
		int u, v;
		cin >> u >> v;
		if (hop(u,v)){
			res.push_back(i);
		}
	}
	cout << res.size() << "\n";
	for (int x: res){
		cout << x << " ";
	}
	cout << "\n";
	
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

