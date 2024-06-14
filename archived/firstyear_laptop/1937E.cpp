#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxN = 8e5+5;
typedef pair<ll, int> li;
typedef pair<int,int> ii;
int n, m, c[maxN];
vector<ii> edge[maxN];
ll d[maxN];
ii a[maxN];
int idx(int i, int j){
	return (i-1)*n+j;
}
void dijkstra(int s){
	priority_queue<li, vector<li>, greater<li>> pq;
	pq.push({0,s});
	d[s] = 0;
	while (pq.size()){
		int u = pq.top().second; 
		ll du = pq.top().first;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto it: edge[u]){
			int v = it.first, c = it.second;
			if (d[v]<=du+c) continue;
			d[v] = du+c;
			pq.push({d[v],v});
		}
	}
}
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[idx(j,i)].first;
			a[idx(j,i)].second = i;
		}
	}
	
	for (int i = 1; i <= m+1; i++) for (int j = 1; j <= n; j++) edge[idx(i,j)].clear();
	for (int i = 1; i <= m; i++){
		sort(a+idx(i,1),a+idx(i,n+1));	
		for (int j = 1; j < n; j++){
			edge[idx(i,a[idx(i,j)].second)].push_back({idx(i,a[idx(i,j+1)].second),a[idx(i,j+1)].first-a[idx(i,j)].first});
			edge[idx(i,a[idx(i,j+1)].second)].push_back({idx(i,a[idx(i,j)].second),0});
		}
		for (int j = 1; j <= n; j++){
			edge[idx(m+1,j)].push_back({idx(i,j),c[j]});
			edge[idx(i,j)].push_back({idx(m+1,j),0});
		}
	}
	for (int i = 1; i <= m+1; i++){
		for (int j = 1; j <= n; j++){
			d[idx(i,j)] = 1e18;
		}
	}
	dijkstra(idx(m+1,n));
	cout << d[idx(m+1,1)] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

