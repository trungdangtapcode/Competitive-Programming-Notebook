#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int,pair<int,int>>> edgelist;

int cha[1005];
int timcha(int u){
	if (cha[u]==u) return u;
	return (cha[u]=timcha(cha[u]));
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pv] = pu;
	return true;
}


int main(){
	freopen("NOIMANG.INP","r",stdin);
	freopen("NOIMANG.OUT","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edgelist.push_back({0,{u,v}});
	}
	for (int i = 1, c; i <= n; i++) for (int j = 1; j <= n; j++){
		cin >> c;
		edgelist.push_back({c,{i,j}});
	}
	sort(edgelist.begin(),edgelist.end());
	int res = 0;
	for (auto it: edgelist){
		int u = it.second.first, v = it.second.second, c = it.first;
		if (hop(u,v)) res += c;
	}
	cout << res;
	
	return 0;
}
