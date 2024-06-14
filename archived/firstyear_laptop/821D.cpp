#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e4+5;
typedef pair<int,int> ii;
int n, m, k, d[maxN*3];
ii lamp[maxN];
vector<ii> edge[maxN*3];
void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++){
		cin >> lamp[i].first >> lamp[i].second;
	}
	lamp[k+1].first = n;
	lamp[k+1].second = m;
	for (int i = 1; i <= k+1; i++){
		edge[k+1+lamp[i].first].push_back({i,0});
		edge[k+1+n+lamp[i].second].push_back({i,0});
		
		if (i==k+1) continue;
		if (lamp[i].first>1) edge[k+1+lamp[i].first-1].push_back({i,0});
		if (lamp[i].first<n) edge[k+1+lamp[i].first+1].push_back({i,0});
		if (lamp[i].second>1) edge[k+1+n+lamp[i].second-1].push_back({i,0});
		if (lamp[i].second<m) edge[k+1+n+lamp[i].second+1].push_back({i,0});
		
		edge[i].push_back({k+1+lamp[i].first,1});
		edge[i].push_back({k+1+n+lamp[i].second,1});
		if (lamp[i].first>1) edge[i].push_back({k+1+lamp[i].first-1,1});
		if (lamp[i].first<n) edge[i].push_back({k+1+lamp[i].first+1,1});
		if (lamp[i].second>1) edge[i].push_back({k+1+n+lamp[i].second-1,1});
		if (lamp[i].second<m) edge[i].push_back({k+1+n+lamp[i].second+1,1});
	}
	for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++){
		if (abs(lamp[i].first-lamp[j].first)+abs(lamp[i].second-lamp[j].second)<=1) edge[i].push_back({j,0});
		if (lamp[i]==lamp[k+1]) edge[i].push_back({k+1,0});
	}
	for (int i = 1; i <= k+1+n+m; i++) d[i] = 1e9;
	int s = 1; for (int i = 2; i <= k; i++) if (lamp[i]==ii{1,1}){
		s = i;
		break;
	}
	d[s] = 0;
	deque<int> dq;
	dq.push_back(s);
	while (dq.size()){
		int u = dq.front(); dq.pop_front();
//		cout << u << " d = " << d[u] << "\n";
		for (auto it: edge[u]){
			int v = it.first, c = it.second;
//			cout << " -> " << v << " c = " << c << "\n";
			if (d[v]<=d[u]+c) continue;
			d[v] = d[u]+c;
			if (c==0) dq.push_front(v);
			else dq.push_back(v);
		}
	}
	cout << (d[k+1]==1e9?-1:d[k+1]) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

// f[maxN], fr[maxN], fc[maxN]

//	for (int i = 2; i < n; i++){
//		for (int a: row[i-1]) for (int b: row[i+1]){
//			edge[a].push_back(b);
//			edge[b].push_back(a);
//		}
//	}
//	for (int i = 2; i < m; i++){
//		for (int a: col[i-1]) for (int b: col[i+1]){
//			edge[a].push_back(b);
//			edge[b].push_back(a);
//		}
//	}
//	for (int i = 1; i <= m; i++) for (int a: col[i]) for (int )
