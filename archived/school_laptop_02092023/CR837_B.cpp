#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		priority_queue<ii,vector<ii>,greater<ii>> edge;
		for (int i = 0, u, v; i < m; i++){
			cin >> u >> v;
			if (u>v) swap(u,v);
			edge.push({v,u});
		}
		long long res =0;
		for (int i = 1, j = 1; i <= n; i++){
			while (edge.size()&&edge.top().first<=i) j = max(edge.top().second+1,j), edge.pop();
			res += (i-j+1);
		}
		cout << res << "\n";
	}
	
	return 0;
}
