#include<bits/stdc++.h>

using namespace std;

int n, sum[200005], p[200005], unloop[200005], inStack[200005];
vector<int> trace[200005];
void dfs(int u){
	sum[u] = unloop[u] = 1;
	for (int v: trace[u]) dfs(v), sum[u] += sum[v];
}

void solve(){
	cin >> n;
	for (int i = 0; i <= n; i++) trace[i].clear(), inStack[i] = unloop[i] = sum[i] = 0;
	for (int i = 1,a; i <= n; i++){
		cin >> a;
		p[i] = i+a;
		p[i] = max(p[i],0);
		p[i] = min(p[i],n+1);
		if (p[i]==n+1) p[i] = 0;
		trace[p[i]].push_back(i);
	}	
	dfs(0);
	long long res = 0;
//	for (int i = 1; i <= n; i++) cout << unloop[i] << " "; cout << "\n";
	if (unloop[1]==0){
		int u = 1;
		while (true){
			res += n + sum[0];
			inStack[u] = true;
			u = p[u];
			if (inStack[u]) break;
		}
	} else if (unloop[1]==1) {
		int u = 1;
		while (true){
			res += n + sum[0] - sum[u];
			inStack[u] = true;
			u = p[u];
			if (u==0) break;
		}
		for (int i = 1; i <= n; i++) if (inStack[i]==0){
			res += 2*n+1;
		}
	};
//	assert(loop[1]!=-1);
	
	cout << res << "\n";
	
	

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;	
}


/*
int n, loop[200005], visited[200005], p[200005], inStack[200005];
void dfs(int u){
	if (p[u]==0||p[u]==n+1){
		loop[u] = false;
		visited[u] = true;
		return;
	}
	if (inStack[p[u]]){
		loop[u] = true;
		visited[u] = true;
		return;
	}
	if (visited[p[u]]){
		loop[u] = loop[p[u]];
		visited[u] = true;
		return;
	}
	visited[u] = inStack[u] = true;
	dfs(p[u]);
	loop[u] = loop[p[u]];
	inStack[u] = false;
}

void solve(){
	cin >> n;
	for (int i = 1,a; i <= n; i++){
		cin >> a;
		p[i] = i+a;
		p[i] = max(p[i],0);
		p[i] = min(p[i],n+1);
		if (p[i]==n+1) p[i] = 0;
	}	
	for (int i = 1; i <= n; i++) visited[i] = 0, loop[i] = -1, inStack[i] = 0;
	for (int i = 1; i <= n; i++) if (!visited[i]){
		dfs(i);
	}
	int cntUnloop = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++) cntUnloop += (loop[i]==0);
//	for (int i = 1; i <= n; i++) cout << loop[i] << " "; cout << "\n";
	if (loop[1]==1){
		int u = 1, l = 0;
		while (u!=0&&u!=n+1){
			++l;
			res += n+1 + cntUnloop;
			u = p[u];
			if (u==1) break;
		}
	} else if (loop[1]==0) {
		int u = 1, l = 0;
		while (u!=0&&u!=n+1){
			++l;
			res += n+1 + cntUnloop - l;
			inStack[u] = true;
			u = p[u];
			if (u==1) break;
		}
		for (int i = 1; i <= n; i++) if (inStack[i]==0){
			res += 2*n+1;
		}
	};
	assert(loop[1]!=-1);
	
	cout << res << "\n";
	
	

}
*/
