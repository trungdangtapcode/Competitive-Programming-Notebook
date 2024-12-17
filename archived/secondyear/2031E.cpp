#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n;
vector<int> edge[maxN];
int calc(vector<int> &vec){
	if (vec.empty()) return 0;
	if (vec.size()==1) return vec[0]+1;
	sort(vec.begin(), vec.end());
	int offset = 0, ahead = 0;
	for (int x: vec){
		if (ahead) ahead = ((ahead-1)>>min(26,x-offset))+1;
		offset = x;
		ahead++;
	}
	return offset + 32-__builtin_clz(ahead-1);
}
int dp(int u){
	vector<int> tmp;
	for (int v: edge[u]) tmp.push_back(dp(v));
	return calc(tmp);
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int p; cin >> p;
		edge[p].push_back(i+1);
	}
	cout << dp(1) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

