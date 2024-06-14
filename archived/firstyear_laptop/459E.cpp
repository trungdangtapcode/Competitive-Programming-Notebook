#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edge;
const int maxN = 3e5 + 5;
int n, m, f[maxN], g[maxN];

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({w,{u,v}});
	}
	sort(edge.begin(),edge.end());
	edge.push_back({1e9,{0,0}});
	int res = 0, last =  0;
	vector<int> vec;
	for (auto it: edge){
		if (last<it.first){
			for (auto x: vec) g[x] = max(g[x],f[x]);
			vec.clear();
			last = it.first;
		}
		int u = it.second.first, v = it.second.second;
		f[v] = max(f[v],g[u]+1);
		res = max(res,f[v]);
		vec.push_back(v);
	}
	cout << res;
	
	return 0;
}
