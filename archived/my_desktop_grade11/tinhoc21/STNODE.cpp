#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;

int n, m, s, t, INF = 1e5;
typedef pair<int, int> id;
vector<vector<id>> edge (10005);
vector<int> d, f;
vector<int> trace, untrace;
vector<bool> inPath;
//vector<bool> DFSfree;


void findPath(int x){
	priority_queue<id,vector<id>,greater<id>> pq;
	pq.push({0,x});
	
	while (!pq.empty()){
		int nodeU = pq.top().second;
		int distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it.second;
			int distUV = it.first;
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU+distUV;
				trace[nodeV] = nodeU;
				pq.push({d[nodeV],nodeV});
			}
		}
	}
}

void tracePath(int x){
	while (trace[x]!=-1){
		inPath[x] = true;
		untrace[trace[x]] = x;
		x = trace[x];
	}
}

void DFS(int nodeU){
	//cout << nodeU << endl;
	//if (inPath[x]) return d[x];
	for (auto& it: edge[nodeU]){
		int nodeV = it.second;
		if (!inPath[nodeV]&&f[nodeV]==-1) DFS(nodeV); //inPath da duoc toi uu nen khoi can DFS
		f[nodeU] = max(f[nodeU],f[nodeV]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		//edge[b-1].push_back({1,a-1});
		edge[a-1].push_back({1,b-1});
	}
	
	d.assign(n,INF);
	d[s-1] = 0;
	trace.assign(n,-1);
	findPath(s-1);
	
	inPath.assign(n,false);
	inPath[s-1] = true;
	untrace.assign(n,-1);
	tracePath(t-1);
	//for (int i = 0; i < n; i++) cout << inPath[i] << " "; cout << endl;
	
	//NOW duong xa nhat la tot nhat (vi no gan voi dich)
	//SO d[] -> f[]
	//fix;
	f.assign(n,-1);
	for (int i = 0; i < n; i++) if (inPath[i]) f[i] = d[i];
	for (int nodeU = 0; nodeU < n; nodeU++) if (!inPath[nodeU]) DFS(nodeU);
	//for (int i = 0; i < n; i++) cout << f[i] << " "; cout << endl;
	
	//tim lien thong voi u -> v lon nhat (trong INPATH) thong qua OUTPATH vua tinh
	int nodeU = s-1;
	//cout << "f[nodeU] = " << myMax << endl;
	while (nodeU != t-1){
		for (auto& it: edge[nodeU]){
			int nodeV = it.second;
			f[nodeU] = max(f[nodeU],f[nodeV]);
		}
		nodeU = untrace[nodeU];
	}
	
	//TIM INPATH -> calc OUTPATH -> calc INPATH -> calc RESULT
	//for (int i = 0; i < n; i++) cout << f[i] << " "; cout << endl;
	nodeU = s-1;
	int result = 0, myMax = f[nodeU], di = 0;
	nodeU = untrace[nodeU];
	while (nodeU != t-1){
		di++;
		if (myMax<=di) result++;
		myMax = max(myMax,f[nodeU]);
		nodeU = untrace[nodeU];
	}
	cout << result << endl;
	
	
	return 0;
}
