#include<bits/stdc++.h>

using namespace std;
int n, m, mmax, minl = 1e9, minr = 1e9;
vector<int> edge[1000005];

int res[1000005], tplt;
bool visited[1000005];
void dfs(int u){
	visited[u] = true;
	res[u] = tplt;
	for (int v: edge[u]){
		if (!visited[v]) dfs(v);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0, a; i < m; i++){
		cin >> a;
		mmax = max(mmax,min(a,n-a+1));
		if (2*a<=n){
			minl = min(minl,a);
		} else minr = min(minr,n-a+1);
	}
	
	for (int i = 1; i < mmax; i++){
		edge[i].push_back(n-i+1);
		edge[n-i+1].push_back(i);
	}
	for (int l = minl+1, r = n-minl+1; l < r; l++, r--){
		edge[r].push_back(l);
		edge[l].push_back(r);
	}
	for (int l = minr, r = n-minr; l < r; l++, r--){
		edge[r].push_back(l);
		edge[l].push_back(r);
	}
//	for (int i = 1; i <= n; i++){
//		cout << i << ": ";
//		for (int j: edge[i]) cout << j << " ";
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++) if (!visited[i]){
		++tplt;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	
	return 0;
}
