#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+5;

vector<int> adj[maxN];
bool visited[maxN];
int n;
vector<int> cycle;
set<int> cycleSet;

bool findCycle(int u, int p, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        if (visited[v]) {
            bool found = false;
            for (int node : path) {
                if (node == v) found = true;
                if (found) {
                    cycle.push_back(node);
                    cycleSet.insert(node);
                }
            }
            return true;
        }
        
        if (findCycle(v, u, path)) return true;
    }
    
    path.pop_back();
    return false;
}

int dfs(int u, int p) {
    int maxDepth = 0;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        if (cycleSet.count(v) && cycleSet.count(u)) continue;
        
        maxDepth = max(maxDepth, 1 + dfs(v, u));
    }
    
    return maxDepth;
}

int calc(vector<int>& depth, int C) {
    vector<int> B(C);
    for (int j = 0; j < C; j++) {
        B[j] = depth[j] + j;
    }

    vector<int> sufMax(C);
    sufMax[C-1] = B[C-1];
    for (int j = C-2; j >= 0; j--)
        sufMax[j] = max(B[j], sufMax[j+1]);

    vector<int> preMax(C);
    preMax[0] = B[0];
    for (int j = 1; j < C; j++)
        preMax[j] = max(B[j], preMax[j-1]);

    int ans = 0;
    for (int i = 0; i < C; i++) {
        ans = max(ans, (depth[i] - i) + sufMax[i]);

        if (i > 0)
            ans = max(ans, (depth[i] + C - i) + preMax[i-1]);
    }
    return ans;
}

void solve(){
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }
    cycle.clear();
    
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cycleSet.clear();
    vector<int> path;
    findCycle(1, -1, path);
    
    vector<int> depth(cycle.size());
    for (int i = 0; i < cycle.size(); i++) {
        depth[i] = dfs(cycle[i], -1);
    }
    
    int ans = 0;
    int C = cycle.size();
    
//    for (int i = 0; i < C; i++) {
//        for (int j = 0; j < C; j++) {
//            int dist = (j - i + C) % C;
//            ans = max(ans, depth[i] + dist + depth[j]);
//        }
//    }
	ans = calc(depth, C);
	
    cout << ans + 1 << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef JESSIE
    freopen("input.txt","r",stdin);
    #endif
    solve();
}
