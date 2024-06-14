//DP -> line greedy to fill -> line simple -> line is maximum
#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e3 + 5;
typedef pair<int,int> ii;
int n;
vector<int> edge[maxN];
vector<int> bfs(int u){
	queue<int> q;
	q.push(u);
	vector<int> d(n+1,1e9);
	d[u] = 0;
	while (q.size()){
		int u = q.front(); q.pop();
		for (int v: edge[u]) if (d[u]+1<d[v]){
			d[v] = d[u]+1;
			q.push(v);
		}
	}
	return d;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1;  i< n; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	auto d1 = bfs(1);
	int a = max_element(d1.begin()+1,d1.end())-d1.begin();
	auto d2 = bfs(a);
	int b = max_element(d2.begin()+1,d2.end())-d2.begin();
	auto d3 = bfs(b);
	int dist = *max_element(d2.begin()+1,d2.end());
	vector<int> center;
	for (int i = 1; i <= n; i++) if (d2[i]+d3[i]==dist&&min(d2[i],d3[i])==dist/2)
		center.push_back(i);
	vector<ii> ans;
	if (dist%2==0){
		assert(center.size()==1);
		for (int i = 0; i <= dist/2; i++) ans.push_back({center[0],i});
	} else {
		assert(center.size()==2);
		int cnt = 0, r = 1;
		while (cnt < dist+1){
			ans.push_back({center[0],r});
			ans.push_back({center[1],r});
			r+=2;
			cnt += 4;
		}
	}
	cout << ans.size() << "\n";
	for (auto it: ans) cout << it.first << " " << it.second << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

