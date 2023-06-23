#include<bits/stdc++.h>

using namespace std;
int n, m, cha[1005];
vector<pair<int,pair<int,int>>> edgelist;
int res = 2e9;

int timcha(int x){
	return cha[x] = (cha[x]==x?x:timcha(cha[x]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pu] = pv;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edgelist.push_back({c,{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	for (int i = 0; i < m; i++){
		for (int j = 1; j <= n; j++) cha[j] = j;
		int cnt = 0, j, u, v;
		for (j = i; j < m; j++){
			u = edgelist[j].second.first, v = edgelist[j].second.second;
			if (hop(u,v)) cnt++;
			if (cnt==n-1) break;
		}
		if (cnt<n-1) break;
		res = min(res,edgelist[j].first-edgelist[i].first);
	}
	if (res==2e9){
		cout << "NO";
	} else cout << "YES\n" << res;
	
	return 0;
}
