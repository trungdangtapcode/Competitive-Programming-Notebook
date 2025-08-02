#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> path;
int x, y;

bool check(int v) {
    // BFS from v to check reachability to y using only unvisited nodes
    queue<int> q;
    vector<bool> seen(MAXN, false);
    q.push(v);
    seen[v] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == y) return true;
        for (int nei : adj[u]) {
            if (!visited[nei] && !seen[nei]) {
                seen[nei] = true;
                q.push(nei);
            }
        }
    }
    return false;
}

bool dfs(int u) {
    visited[u] = true;
    path.push_back(u);
    if (u == y) return true;

    for (int v : adj[u]) {
        if (!visited[v] && check(v)) {
            if (dfs(v)) return true;
        }
    }

    path.pop_back();
    visited[u] = false;
    return false;
}

void solve(){
	int n, m;
    cin >> n >> m;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) adj[i].clear(), visited[i] = false;
	path.clear();

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    if (dfs(x)) {
        for (int node : path)
            cout << node << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();

    return 0;
}

