#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
struct edgeT{
	int to, idx, w, direct, from, isShortest = 0, isHard = 0;
	edgeT(int to, int idx, int w, int direct){
		this->to = to;
		this->idx = idx;
		this->w = w;
		this->direct = direct;
	}
};
vector<edgeT> edge[100005], trace[10][100005];
set<int> farShort[10][100005];
vector<edgeT> edgelist;
int d[10][100005], n, m, k, s[10], t[10], isHard[10], isEasy[10], nEasy, easyId[10];
void dijkstra(int person){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0,s[person]});
	for (int i = 1; i <= n; i++) d[person][i] = 1e18;
	d[person][s[person]] = 0;
	while (pq.size()){
		int u = pq.top().second, du = pq.top().first; pq.pop();
		if (du!=d[person][u]) continue;
		for (auto it: edge[u]){
			int v = it.to, c = it.w, idx = it.idx;
			if (d[person][v]>du+c){
				pq.push({d[person][v]=du+c,v});
				trace[person][v].clear();
				trace[person][v].push_back(edgeT(u,idx,c,-1));
			} else if (d[person][v]==du+c) trace[person][v].push_back(edgeT(u,idx,c,-1));;
		}
	}
} 
int visited[100005];
void traceBack1(int u){
	if (visited[u]) return;
	visited[u] = 1;
	for (auto it: trace[0][u]){
		int v = it.to, idx = it.idx;
		edgelist[idx].isShortest = 1;
		edgelist[idx].direct = v;
		traceBack1(v);
	}
}
void traceBack2(int person, int u){
	if (visited[u]) return;
	visited[u] = 1;
	for (auto it: trace[person][u]){
		int v = it.to, idx = it.idx;
		traceBack2(person,v);
		if (!edgelist[idx].isShortest||edgelist[idx].direct!=v) continue;
		if (isHard[person]){
			if (d[person][v]==d[0][v]) edgelist[idx].isHard = 1;
			continue;
		}
		for (auto it: farShort[person][v]) farShort[person][u].insert(it);
		if (farShort[person][v].empty()) farShort[person][u].insert(v);
	}
}
int f[100005][32];
int dp(int u, int mask){
	if (f[u][mask]!=-1) return f[u][mask];
	if (u==s[0]) return 0;
	f[u][mask] = 0;
	for (auto it: trace[0][u]){
		int v = it.to, idx = it.idx, c = it.w;
		f[u][mask] = max(f[u][mask],dp(v,mask)+c*edgelist[idx].isHard);
	}
	for (int i = 0; i < nEasy; i++) if (!(mask>>i&1)){
		for (int v: farShort[easyId[i]][u]) f[u][mask] = max(f[u][mask],dp(v,mask^(1<<i))+d[0][u]-d[0][v]);
	}
	return f[u][mask];
}

main(){
	cin >> n >> m >> k;
	for (int i = 0, u, v, c; i < m; i++){
		cin >> u >> v >> c;
		edge[u].push_back(edgeT(v,i,c,-1));
		edge[v].push_back(edgeT(u,i,c,-1));
		edgelist.push_back(edgeT(v,i,c,-1));
		edgelist.back().from = u;
	}
	cin >> s[0] >> t[0];
	for (int i = 1; i < k; i++){
		cin >> isEasy[i] >> s[i] >> t[i];
		isHard[i] = !isEasy[i];
		if (isEasy[i]) easyId[nEasy++] = i;
	}
	for (int i = 0; i < k; i++) dijkstra(i);
	traceBack1(t[0]);
	for (int i = 1; i < k; i++){
		memset(visited,0,sizeof(visited));
		traceBack2(i,t[i]);
	}
//	for (int i = 0; i < m; i++){
//		int u = edgelist[i].to, v = edgelist[i].from;
//		cout << u  << " - " << v << " " << edgelist[i].isHard << "\n";	
//	}
//	for (int i = 1; i <= n; i++){
//		cout << i << ": ";
//		for (int j = 1; j < k; j++) for (auto it: farShort[j][i]) cout << it << " ";
//		cout << "\n";
//	}
	for (int i = 1; i <= n; i++) for (int j = 0; j < (1<<nEasy); j++) f[i][j] = -1;
	cout << dp(t[0],0);
	
	return 0;
}

