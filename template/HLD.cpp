#include<bits/stdc++.h>

using namespace std;

int d[200005], head[200005], pos[200005], heavy[200005], n, q, nPos, a[200005], par[200005];
vector<int> edge[200005];
int dfs(int p, int u){
    d[u] = d[p] + 1;
    par[u] = p;
    int u_size = 1, max_size = 0;
    for (int v: edge[u]) if (v!=p){
        int v_size = dfs(u,v);
        u_size += v_size;
        if (max_size<v_size) max_size = v_size, heavy[u] = v;
    }
    return u_size;
}
void decompose(int u, int h){
    head[u] = h; pos[u] = ++nPos;
    if (heavy[u]) decompose(heavy[u],h);
    for (int v: edge[u]) if (v!=par[u]&&v!=heavy[u]) decompose(v,v);
}

int val[800005];
void segment_update(int k, int l, int r, int u, int v){
    if (l>u||r<u) return;
    if (l==r){
        val[k] = v;
        return;
    }
    int m = l+r>>1;
    segment_update(2*k,l,m,u,v);
    segment_update(2*k+1,m+1,r,u,v);
    val[k] = max(val[2*k],val[2*k+1]);
}
int segment_get(int k, int l, int r, int u, int v){
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return val[k];
    int m = l+r>>1;
    return max(segment_get(2*k,l,m,u,v),segment_get(2*k+1,m+1,r,u,v));
}

int query(int u, int v){
    int res = 0;
    for (; head[u]!=head[v]; v = par[head[v]]){
        if (d[head[u]]>d[head[v]]) swap(u,v);
        res = max(res,segment_get(1,1,n,pos[head[v]],pos[v]));
    }
    if (d[u]>d[v]) swap(u,v);
    res = max(res,segment_get(1,1,n,pos[u],pos[v]));
    return res;
}
