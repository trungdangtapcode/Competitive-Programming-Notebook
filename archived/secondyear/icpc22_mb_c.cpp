#include<bits/stdc++.h>

using namespace std;

struct Matching{
	vector<int> matchX, matchY, trace;
	vector<vector<int>> adj;
	int n, m, cmp = 0;
	Matching(int an, int am){
		n = an;
		m = am;
		matchX.resize(n,-1);
		matchY.resize(m,-1);
		adj.resize(n);
	}
	void addEdge(int u, int v){
		assert(u>=0&&u<n);
		assert(v>=0&&v<m);
		adj[u].push_back(v);
	}
	int bfs(){
		queue<int> q;
		for (int i = 0; i < n; i++) if (matchX[i]==-1){
			q.push(i);
		}
		trace.assign(m,-1);
		while (q.size()){
			int u = q.front(); q.pop();
			for (int v: adj[u]) if (trace[v]==-1){
				trace[v] = u;
				if (matchY[v]==-1) return v;
				q.push(matchY[v]);
			}
		}
		return -1;
	}
	void enlarge(int y){
		while (y!=-1){
			int x = trace[y];
			int nxt = matchX[x];
			matchX[x] = y;
			matchY[y] = x;
			y = nxt;		
		}
	}
	int getCmp(){
		int y;
		while ((y=bfs())!=-1) enlarge(y);
		cmp = 0;
		bfs();
		for (int i = 0; i < n; i++) cmp += (matchX[i]!=-1);
		return cmp;
	}
};

const int maxN = 2e4+5;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int x[maxN], y[maxN];
typedef pair<int,int> ii;
map<ii,int> mp;
vector<int> needEdge[maxN];
void solve(int n){
	mp.clear();
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		if ((x[i]+y[i])%2) mp[{x[i],y[i]}] = i;
		needEdge[i].clear();
	}
	int cntEdge = 0;
	Matching match(n, n);
	for (int i = 1; i <= n; i++){
		if ((x[i]+y[i])%2) continue;
		int ux = x[i], uy = y[i];
		for (int k = 0; k < 4; k++){
			int vx = ux+dx[k], vy = uy+dy[k];
			if (!mp.count({vx,vy})) continue;
			int idx = mp[{vx,vy}];
//			if (idx<i) continue;
//			needEdge[i].push_back(cntEdge);
//			needEdge[idx].push_back(cntEdge);
//			cntEdge++;
			match.addEdge(i-1,idx-1);
		}
	}
//	for (int i = 1; i <= n; i++) for (int v: needEdge[i]){
//		cout << i << " " << v+1 << "\n";
//		match.addEdge(i-1,v);
//	}
	cout << n-match.getCmp() << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	int n; while (cin >> n)
		solve(n);
}

