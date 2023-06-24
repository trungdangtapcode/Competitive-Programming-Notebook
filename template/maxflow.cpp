#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
struct myEdge{
    int u, v, cap, flow;
};
struct eulerEdge{
    int u, v, pos, neg, idx, res;
} edgelist[5005];

struct Flow{
    int n, s, t, d[5005], ptr[5005];
    vector<int> edge[5005];
    vector<myEdge> edgelist;
    Flow(int _n, int _s, int _t){
        n = _n;
        s = _s;
        t = _t;
    }
    void addEdge(int u, int v, int c){
        edge[u].push_back(edgelist.size()); edgelist.push_back(myEdge({u,v,c,0}));
        edge[v].push_back(edgelist.size()); edgelist.push_back(myEdge({v,u,0,0}));
    }
    int bfs(){
        for (int i = 1; i <= n; i++) d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size()){
            int u = q.front(); q.pop();
            for (int idx: edge[u]){
                auto& it = edgelist[idx];
                if (d[it.v]==-1&&it.flow<it.cap) d[it.v]=d[u]+1, q.push(it.v);
            }
        }
        return d[t] != -1;
    }
    int dfs(int u, int val){
        if (!val) return 0;
        if (u==t) return val;
        for (; ptr[u] < edge[u].size(); ++ptr[u]){
            int idx = edge[u][ptr[u]];
            auto &it = edgelist[idx], &it_rev = edgelist[idx^1];
            if (d[it.v]!=d[u]+1) continue;
            int new_val = dfs(it.v,min(val,it.cap-it.flow));
            if (!new_val) continue;
            it.flow += new_val;
            it_rev.flow -= new_val;
            return new_val;
        }
        return 0;
    }
    int maxFlow(){
        int res = 0;
        while (bfs()){
            for (int i = 1; i <= n; i++) ptr[i] = 0;
            while (true){
                int val = dfs(s,1e9);
                if (!val) break;
                res += val;
            }
        }
        return res;
    }
    void trace(vector<eulerEdge> &tmp, int nNode){
        int sz = tmp.size();
        queue<int> q;
        q.push(s);
        while (q.size()){
            int u = q.front(); q.pop();
            for (int idx: edge[u]){
                auto it = edgelist[idx];
                if (it.flow>0){
                    // cout << it.u << " -> " << it.v << "\n";
                    if (it.u<=nNode+sz&&it.v<=nNode+sz) tmp[it.u-nNode-1].res = it.v;
                    q.push(it.v);
                }
            }
        }
    }
};
