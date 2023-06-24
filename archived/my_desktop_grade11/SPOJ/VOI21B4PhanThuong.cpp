#include <bits/stdc++.h>
//[0..n-1]
//node: [1..num]
//hai so dac biet ke nhau

using namespace std;
int n, m;
string c[300005]; 
int p[300005];

vector<pair<int,char>> trie_edge[300005];
vector<int> match_edge[300005], match_edge_special[300005];
int trie_trace[300005], node[300005];
int trie_num = 0;

long long int B[300005], C[300005], dp[300005], F[300005];
int cnt[300005];
bool isSpecial[300005];

void build(int p, int u, int pos, int num){ //DFS
	trie_trace[u] = p;
	if (pos>=c[num].length()){
		node[num] = u; //not p
		return;
	};
	for (auto it: trie_edge[u]) if (it.second==c[num][pos]){
		build(u,it.first,pos+1,num);
		return;
	}
	trie_edge[u].push_back({++trie_num,c[num][pos]});
	build(u,trie_num,pos+1,num);
	return;
}
void update(int num, long long int val){ //BFS
	int u = node[num];
	u = trie_trace[u]; //it nhat 1 ky tu
	while (u!=0){
		B[u] = max(B[u],val);
		u = trie_trace[u];
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> c[i] >> p[i];
	}
	for (int i = 1, x, y; i <= m; i++){
		cin >> x >> y;
		match_edge[x].push_back(y);
		match_edge[y].push_back(x);
		cnt[x]++; cnt[y]++;
	}
	int T = sqrt(m);
	for (int i = 1; i <= 1e5; i++) isSpecial[i] = (cnt[i]>T);
	for (int i = 1; i <= 1e5; i++){
		for (auto it: match_edge[i]){
			if (isSpecial[it]) match_edge_special[i].push_back(it); //to special
		}
	}
	for (int i = 0; i < n; i++){
		build(-1,0,0,i);
	}
	for (int i = 0; i < n; i++){ //can we combine C[] and F[]
		dp[i] = max(B[node[i]],C[p[i]]) + p[i]; 
		for (auto it: match_edge_special[p[i]]) dp[i] = max(dp[i],F[it]+p[i]);
		update(i,dp[i]);
		if (isSpecial[p[i]]){
			F[p[i]] = max(F[p[i]],dp[i]);
		} else {
			for (auto it: match_edge[p[i]]) C[it] = max(C[it],dp[i]);
		}
	}
	long long int res = 0;
	for (int i = 0; i < n; i++){
		res = max(res,dp[i]);
	}
	cout << res;
//	for (int i = 0; i <= trie_num; i++) {
//		cout << i << ": ";
//		for (auto it: trie_edge[i]) cout << "("<< it.first << "," << it.second << ") "; 
//		cout << "   trace = " << trie_trace[i] << endl;
//	}
//	for (int i = 0; i < n; i++){
//		cout << "num[" <<i+1 << "] = " << node[i] << endl;
//	}

//	for (int i = 1; i <= 20; i++){
//		cout << "isSpecial[" << i << "] = " << isSpecial[i] << " => F[" << i << "] = " << F[i] << endl;
//	}
//	for (int i = 0; i < n; i++) cout << "DP[" << i << "] = " << dp[i] << endl;
	
	return 0;
}
