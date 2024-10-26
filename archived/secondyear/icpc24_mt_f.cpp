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
    int n, s, t, d[505], ptr[505];
    vector<int> edge[505];
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

const int maxN = 1e4+5;
int n, na, nb, nc, ma, mb, mc, ca[maxN], cb[maxN], cc[maxN];

void solve(){
	cin >> n >> na >> nb >> nc;
	for (int i = 1; i <= n; i++) ca[i] = cb[i] = cc[i] = 0;
	cin >> ma; 
	for (int i = 1; i <= ma; i++){
		int x; cin >> x;
		ca[x] = 1;
	}
	cin >> mb; 
	for (int i = 1; i <= mb; i++){
		int x; cin >> x;
		cb[x] = 1;
	}
	cin >> mc; 
	for (int i = 1; i <= mc; i++){
		int x; cin >> x;
		cc[x] = 1;
	}
	int res = 0, cab = 0, cbc = 0, cca = 0, cabc = 0;
	for (int i = 1; i <= n; i++){
		if (ca[i]&&!cb[i]&&!cc[i]&&na>0){
			res++;
			na--;
		}
		if (!ca[i]&&cb[i]&&!cc[i]&&nb>0){
			res++;
			nb--;
		}
		if (!ca[i]&&!cb[i]&&cc[i]&&nc>0){
			res++;
			nc--;
		}
		cab += (ca[i]&&cb[i]&&!cc[i]);
		cbc += (!ca[i]&&cb[i]&&cc[i]);
		cca += (ca[i]&&!cb[i]&&cc[i]);
		cabc += (ca[i]&&cb[i]&&cc[i]);
	}
	Flow fl(9,1,9);
	fl.addEdge(1,2,na);
	fl.addEdge(1,3,nb);
	fl.addEdge(1,4,nc);
	
	fl.addEdge(5,9,cab);
	fl.addEdge(6,9,cbc);
	fl.addEdge(7,9,cca);
	fl.addEdge(8,9,cabc);
	
	fl.addEdge(2,5,1e6);
	fl.addEdge(2,7,1e6);
	fl.addEdge(2,8,1e6);
	fl.addEdge(3,5,1e6);
	fl.addEdge(3,6,1e6);
	fl.addEdge(3,8,1e6);
	fl.addEdge(4,6,1e6);
	fl.addEdge(4,7,1e6);
	fl.addEdge(4,8,1e6);
	
	int x = fl.maxFlow();
	cout << res+x << "\n";
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

