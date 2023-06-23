#include<bits/stdc++.h>

using namespace std;
int deepest[100005], n;
vector<int> edge[100005];
int dfs(int u){
	int res = 0; 
	deepest[u] = 1;
	for (int v: edge[u]){
//		res = max(res,dfs(v));
//		sum += deepest[v]; //init 1
		res += dfs(v);
		deepest[u] = max(deepest[u],deepest[v]+1);
	}
	return max(res,deepest[u]);
}

int main(){
	cin >> n;
	for (int i = 2, x; i <= n; i++){
		cin >> x;
		edge[x].push_back(i);
	}
	cout << dfs(1);
	
	return 0;
}
