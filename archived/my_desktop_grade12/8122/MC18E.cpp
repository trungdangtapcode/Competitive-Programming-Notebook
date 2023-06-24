#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> edge[200005];
int n, m, k, deg[200005], v[200005], u[200005], res[200005];
bool isAvailable[200005];

bool inGood[200005];
set<ii> good;
void del(int u){
	for (auto it: edge[u]){
		if (!isAvailable[it.second]) continue;
		int v = it.first;
		if (inGood[v]){
			good.erase({deg[v],v});
			good.insert({--deg[v],v});
		}
	}
	good.erase({deg[u],u});
	inGood[u] = false;
}
void refresh(){
	while (!good.empty()&&good.begin()->first<k){
		int u = good.begin()->second;
		del(u);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);	
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		cin >> u[i] >> v[i];
		edge[u[i]].push_back({v[i],i});
		edge[v[i]].push_back({u[i],i});
		deg[v[i]]++, deg[u[i]]++;
		isAvailable[i] = true;
	}	
	for (int i = 1; i <= n; i++){
		good.insert({deg[i],i});
		inGood[i] = true;
	}
	refresh();
	for (int i = m-1; i >= 0; i--){
		res[i] = good.size();
		isAvailable[i] = false;
		if (inGood[u[i]]&&inGood[v[i]]){
			good.erase({deg[u[i]],u[i]});
			good.insert({--deg[u[i]],u[i]});
			good.erase({deg[v[i]],v[i]});
			good.insert({--deg[v[i]],v[i]});
			refresh();
		}
	}
	for (int i = 0; i < m; i++) cout << res[i] << "\n";
	return 0;
}
