#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
int k[100005], n, s;
vector<int> edge[100005];
ii dfs(int u, int p){
	if (k[u]==0) return {0,0};
	int cur = k[u] - 1, res = 1, remain = 0, sum = 0;
	vector<int> vec;
	for (int v: edge[u]) if (v!=p){
		ii x = dfs(v,u);
		int fv = x.first, r = x.second;
		remain += r;
		vec.push_back(fv);
//		if (k[v]) sum += k[v]-1;
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for (int x: vec){
		if (cur==0) break;
		res += x;
		cur--;
		res++;
	}
	res += 2*min(cur,remain);
	cur -= min(cur,remain);
//	res += min(cur,sum-remain);
//	cur -= min(cur,sum-remain);
//	cout << u << ". " << res << " " << cur << "\n";
	return {res,cur};
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> k[i];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cin >> s;
	k[s]++;
	cout << dfs(s,-1).first-1;
	
	return 0;
}
