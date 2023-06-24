#include <bits/stdc++.h>

using namespace std;
map<string,int> mp;
string in1, in2, ten[10005];
int n, k, s, m, n0;
int inK[10005];
vector<int> edge[10005];

void bfs(){
	queue<int> q;
	for (int i = 0; i < n; i++){
		if (inK[i]==0) q.push(i);
	}
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (auto v: edge[u]){
			if (inK[v]>0){
				inK[v]--;
				if (inK[v]==0) q.push(v);
			}
		} 
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> s >> m;
	for (int i = 0; i < n; i++) inK[i] = k;
	for (int i = 0; i < s; i++){
		cin >> in1;
		if (!mp.count(in1)) mp[in1] = n0++;
		inK[mp[in1]] = 0;
	}
	for (int i = 0; i < m; i++){
		cin >> in1 >> in2;
		if (!mp.count(in1)) mp[in1] = n0++;
		if (!mp.count(in2)) mp[in2] = n0++;
		edge[mp[in1]].push_back(mp[in2]);
		edge[mp[in2]].push_back(mp[in1]);
	}
	for (auto it: mp) ten[it.second] = it.first; 
	for (int i = 0; i < n; i++){
		sort(edge[i].begin(),edge[i].end());
		edge[i].resize(unique(edge[i].begin(),edge[i].end())-edge[i].begin());
	}
	
//	for (auto it: mp){
//		cout << it.first << " " << it.second << endl;
//	}
//	for (int i = 0; i < n; i++){
//		cout << i << ". ";
//		for (int j: edge[i]) cout << j << " ";
//		cout << endl;
//	}
	bfs();
//	for (int i = 0; i < n; i++) cout << "inK["<< i << "] = " << inK[i] << endl;
	vector<string> res;
	for (int i = 0; i < n; i++) if (inK[i]==0) res.push_back(ten[i]);
	sort(res.begin(),res.end());
	cout << res.size() << '\n';
	for (auto it: res) cout << it << " ";
	
	
	return 0;
}
