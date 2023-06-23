#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m;
bitset<1005> edge[1005], redge[1005];
long long int res = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	bitset<1005> mask1 = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) edge[i] = redge[i] = 0;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		res += (redge[u]&edge[v]).count();
		edge[u] |= (mask1<<v);
		redge[v] |= (mask1<<u);
	}
	cout << res;
	
	return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m;
bitset<1005> edge[1005], redge[1005];
vector<ii> edgelist;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		if (u==v) continue;
		edge[u] |= (1<<v);
		redge[v] |= (1<<u);
		edgelist.push_back({u,v});
	}
	long long int res = 0;
	for (auto it: edgelist){
		int u = it.first, v = it.second;
		res += (redge[u]&edge[v]).count();
	}
	cout << res/3;
	
	return 0;
}
*/
