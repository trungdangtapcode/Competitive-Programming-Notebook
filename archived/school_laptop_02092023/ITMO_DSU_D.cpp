#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,string> iis;
int n, m, k, cha[50005], sz[50005];
vector<iis> query;
int timcha(int x){
	if (cha[x]==x) return x;
	return cha[x] = timcha(cha[x]);
}
void hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return;
	if (sz[pu]>sz[pv]) swap(pu,pv);
	cha[pu] = pv;
	sz[pv] += sz[pu];
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cha[i] = i, sz[i] = 1;
	for (int i = 0, a, b; i < m; i++) cin >> a >> b;
	query.assign(k,{{0,0},""});
	for (int i = 0; i < k; i++){
		cin >> query[i].second >> query[i].first.first >> query[i].first.second;
	}
	vector<bool> res;
	for (int i = k-1; i >= 0; i--){
		int u = query[i].first.first, v = query[i].first.second;
		string p = query[i].second;
		if (p=="cut"){
			hop(u,v);
		} else {
			res.push_back(timcha(u)==timcha(v));
		}
	}
	for (int i = res.size()-1; i >= 0; i--) cout << (res[i]?"YES\n":"NO\n");
	return 0;
}
