#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int,int>> id;
vector<id> edge;
int a, b, c;

int cha[1000000];

int timcha(int u){
	if (cha[u]==u) return u;
	cha[u] = timcha(cha[u]);
	return cha[u];
}
void hop(int u, int v){
	if (timcha(u)==timcha(v)) return;
	cha[cha[v]] = cha[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		edge.push_back({c,{a,b}});
	}
	sort(edge.begin(),edge.end());
	
	for (int i = 1; i <= n; i++) cha[i] = i;
	int res = 0;
	for (int i = 0; i < m; i++){
		if (timcha(edge[i].second.first)==timcha(edge[i].second.second)) continue;
		hop(edge[i].second.first,edge[i].second.second);
		//cout << edge[i].second.first << " " << edge[i].second.second << endl;
		res += edge[i].first;
	}
	cout << res;
	
	return 0;
}
