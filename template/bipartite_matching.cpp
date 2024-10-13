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
	int maxMatch(){
		int y;
		while ((y=bfs())!=-1) enlarge(y);
		cmp = 0;
		bfs();
		for (int i = 0; i < n; i++) cmp += (matchX[i]!=-1);
		return cmp;
	}
	void print(){
		cout << n << " x " << m << "\n";
		for (int i = 0; i < n; i++) for (int j: adj[i]){
			cout << i << " -> " << j << "\n";
		}
	}
};
