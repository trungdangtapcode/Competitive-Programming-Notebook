#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
vector<int> edge[300005];
bool res[300005];

int mmax;
vector<int> v;
void dfs(int p, int u, int d){
	d++;
	if (d>mmax){
		mmax = d;
		v.clear();
		v.push_back(u);
	} else if (d==mmax) v.push_back(u);
	for (int v: edge[u]) if (v!=p){
		dfs(u,v,d);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	mmax = -1; v.clear();
	dfs(0,1,0);
	int x = v.back();
	for (auto it: v) res[it] = true;
	mmax = -1; v.clear();
	dfs(0,x,0);
	for (auto it: v) res[it] = true;
	for (int i = 1; i <= n; i++){
		cout << mmax - 1 + res[i] << "\n";
	}
	
	return 0;
}
