#include<bits/stdc++.h>

using namespace std;
int n, m, cha[200005];
vector<pair<int,pair<int,int>>> edgelist;
long long int res = 0;

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
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edgelist.push_back({c,{u,v}});
	}
	sort(edgelist.begin(),edgelist.end());
	for (auto it: edgelist){
		int u = it.second.first, v = it.second.second, c = it.first;
		if (hop(u,v)) res += c;
	}
	cout << res;
	
	return 0;
}
