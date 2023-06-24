#include <bits/stdc++.h>

using namespace std;
int n;
int pt[1005];
vector <int> edge[1005], edgeT[1005];
bool used[1005];
int cmp[1005];
stack <int> sta;

void dfs1(int u){
	used[u] = true;
	for (auto& v: edge[u]){
		if (!used[v]) dfs1(v);
	}
	sta.push(u);
}
void dfs2(int u, int cnt){
	cmp[u] = cnt;
	for (auto& v: edgeT[u]){
		if (cmp[v]==-1) dfs2(v,cnt);
	}
}

void solve(){
	cin >> n;
	
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		pt[x-1] = i;
	}

	for (int i = 0; i < n; i++) edge[i].clear(), edgeT[i].clear();
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++){
			if (s[j]=='0') edge[i].push_back(pt[j]), edgeT[pt[j]].push_back(i);
		}
	}
	
	memset(used,false,sizeof(used));
	memset(cmp,-1,sizeof(cmp));
	
//	for (int i = 0; i < n; i++){
//		cout << i+1 << ": ";
//		for (auto& j: edge[i]) cout << j+1 << " ";
//		cout << endl;
//	}
	
	for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
	for (int i = 0, cnt = 0; i < n; i++){
		if (cmp[sta.top()]==-1) dfs2(sta.top(),cnt++);
		sta.pop();
	}
//	for (int i = 0; i < n; i++) cout << cmp[i] << " "; cout << endl;
	for (int i = 1; i < n; i++)
		if (cmp[i-1]!=cmp[i]){
			cout << "YES" << '\n';
			return;
		}
	cout << "NO" << '\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
