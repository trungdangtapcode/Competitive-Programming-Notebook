#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> g;
vector<int> res;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	res.assign(n+1,0);
	g.assign(n+1,vector<int>());
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		g[x].push_back(i); //sorted
	}
	int x = n;
	for (int i = 1; i <= n; i++){
		for (auto it: g[i]) res[it] = x--;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	
	return 0;
}
