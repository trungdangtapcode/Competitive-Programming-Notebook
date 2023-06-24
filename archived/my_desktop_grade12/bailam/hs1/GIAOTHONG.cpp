#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int,pair<int,int>>> edge;
vector<int> cha; 

int timcha(int x){
	if (cha[x]!=x)
		return (cha[x] = timcha(cha[x]));
	return x;
}
bool hop(int u, int v){
	int pu = timcha(u), pv = timcha(v);
	if (pu==pv) return false;
	cha[pv] = pu;
	return true;
}

int main(){
	freopen("GIAOTHONG.INP","r",stdin);
	freopen("GIAOTHONG.OUT","w",stdout);
	
	
	cin >> n >> m;
	edge.assign(m,pair<int,pair<int,int>>());
	cha.assign(n+5,-1);
	for (int i = 1; i <= n; i++) cha[i] = i;
	for (int i = 0; i < m; i++){
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
	}
	sort(edge.begin(),edge.end());
	int res = 0;
	for (int i = 0; i < m; i++){
		if (hop(edge[i].second.first,edge[i].second.second)){
			res = max(res,edge[i].first);
		};
	}
	cout << res;
	
	
	return 0;
}
