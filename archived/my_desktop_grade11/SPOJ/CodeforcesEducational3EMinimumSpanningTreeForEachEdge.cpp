#include <bits/stdc++.h>

using namespace std;
vector <pair <int, pair <int, int>>> w, w0; //
typedef pair <int, int> ii;
vector <ii> edge[100005];
int n, m, cha[100005], lg;
int tin[100005], tout[100005];
int deep[100005];
ii jumpUp[100005][30]; //vi tri nhay den va khoang cach nhay
long long int total;

int timcha(int u){
	if (cha[u]<0) return u;
	cha[u] = timcha(cha[u]);
	return cha[u];
}
void hop(int u, int v){
	if (timcha(u)==timcha(v)) return;
	if (cha[timcha(u)]<cha[timcha(v)]){
		cha[timcha(v)] += cha[timcha(u)];
		cha[timcha(v)] = timcha(u);
	} else {
		cha[timcha(u)] += cha[timcha(v)];
		cha[timcha(u)] = timcha(v);
	}
}

int times = 0;
void dfs(int bu, int u, int c){
	tin[u] = times++;
	
	jumpUp[u][0] = {bu,c};
	for (int i = 1; i <= lg; i++){
		jumpUp[u][i].first = jumpUp[jumpUp[u][i-1].first][i-1].first;
		jumpUp[u][i].second = max(jumpUp[jumpUp[u][i-1].first][i-1].second,jumpUp[u][i-1].second);
	}
	for (auto& it: edge[u]){
		int v = it.first;
		int c = it.second;
		if (deep[v]==-1) deep[v] = deep[u]+1, dfs(u,v,c);
	}
	
	tout[u] = times++;
}
bool isCha(int u, int v){
	return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int lca(int u, int v){ //node u to parent then take the min
	if (isCha(u,v)) return -1e7;
	int res = -1e7;
	for (int i = lg; i >= 0; i--){
		if (!isCha(jumpUp[u][i].first,v))
			res = max(res,jumpUp[u][i].second), u = jumpUp[u][i].first;
	}
	return res = max(res,jumpUp[u][0].second);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	w.resize(m);
	for (int i = 0; i < m; i++){
		cin >> w[i].second.first >> w[i].second.second >> w[i].first;
	}
	w0 = w;
	sort(w.begin(),w.end());
	for (int i = 0; i < n; i++) cha[i] = -1;
	for (int i = 0; i < m; i++){
		int u = w[i].second.first-1, v = w[i].second.second-1, c = w[i].first;
		if (timcha(u)!=timcha(v)){
			hop(u,v);
			edge[u].push_back({v,c});
			edge[v].push_back({u,c});
			total += c;
		}
	}
	
	lg = 0;
	for (int i = n; i > 1; i /= 2) lg++;
	memset(deep,-1,sizeof(deep));
	deep[0] = 0;
	dfs(0,0,0);

	for (int i = 0; i < m; i++){
		int u = w0[i].second.first-1;
		int v = w0[i].second.second-1;
		int c = w0[i].first;
		cout << total-max(lca(u,v),lca(v,u))+c << '\n';
	}
	
	
	return 0;
}

