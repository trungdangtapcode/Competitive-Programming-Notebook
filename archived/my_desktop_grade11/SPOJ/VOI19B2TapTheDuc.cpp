#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
long long int INF = 1e16;
int n, m, k, s[20], t[20], p[20];

typedef pair< long long int, pair<pair <long long int, int > ,pair<int, int> > > id; //{kc,{{l,v},{i,kho}}}
vector <id> edge[100005], unEdge[20][100005];;
vector <long long int> d;
typedef pair< pair<bool,int>,pair<long long int, bool >> idDanhDau; // {thuoc Nam, chieu tu u}{khoang cach tu s, ok}
idDanhDau danhdau[100005];
long long int tongS[100005];

void dijsktra(int x, int y){
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push({0,{{-1,x},{-1,-1}}});
	
	while (!pq.empty()){
		int nodeU = pq.top().second.first.second;
		long long int distU = pq.top().first;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it.second.first.second;
			long long int distUV = it.second.first.first;
			int wayV = it.second.second.first;
			int khoV = p[y];
			
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU + distUV;
				pq.push({d[nodeV],{{-1,nodeV},{-1,-1}}});
				unEdge[y][nodeV].clear();
				unEdge[y][nodeV].push_back({d[nodeU],{{distUV,nodeU},{wayV,khoV}}});
			} else if (distU+distUV==d[nodeV]) unEdge[y][nodeV].push_back({d[nodeU],{{distUV,nodeU},{wayV,khoV}}});
		}
	}
	return;
}
void initDanhDau(int x){
	memset(danhdau,0,sizeof(danhdau));
	vector <bool> visited (n+1,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[1][nodeU]){
			int nodeV = it.second.first.second;
			int wayV = it.second.second.first;
			long long int distV = it.first;
			//long long int distUV = it.second.first.first;
			//cout << " - "<<wayV << endl;
			danhdau[wayV] = {{true,nodeV},{distV,false}}; //luu y: dang di nguoc
			if (nodeV!=s[1]) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}
void editDanhDau(int x, int y){
	vector <bool> visited (n+1,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[y][nodeU]){
			int nodeV = it.second.first.second;
			int wayV = it.second.second.first;
			long long int distV = it.first;
			bool checkPath = danhdau[wayV].first.first;
			int checkNodeV = danhdau[wayV].first.second;
			long long int checkDistV = danhdau[wayV].second.first;
			int khoV = p[y];
			
			//cout<< nodeU << " " << nodeV << "-> so sanh: " << checkPath << " && " << nodeV << "==" << checkNodeV<< " && " << distV << "==" << checkDistV << "   " << khoV << endl;
			if (checkPath&&(nodeV==checkNodeV)&&((khoV==0&&distV==checkDistV)||khoV==1)) danhdau[wayV].second.second = true;
			
			if (nodeV!=s[y]) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}
void bfs(int x){
	memset(tongS,0,sizeof(tongS));
	vector <bool> visited (n+1,false);
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[1][nodeU]){
			int nodeV = it.second.first.second;
			int wayV = it.second.second.first;
			long long int distUV = it.second.first.first;
			long long int lastTongSV = tongS[nodeV];
			if (danhdau[wayV].second.second) {
				tongS[nodeV] = max(tongS[nodeV],tongS[nodeU]+distUV);
			} else tongS[nodeV] = max(tongS[nodeV],tongS[nodeU]);
			if (nodeV!=s[1]) q.push(nodeV);
			if (visited[nodeV]&&tongS[nodeV]>lastTongSV) visited[nodeV] = false;
		}
		visited[nodeU] = true;
	}
	return;
}
//void bfsViet(int x){
//	queue<int> q;
//	q.push(x);
//	
//	while (!q.empty()){
//		int nodeU = q.front();
//		q.pop();
//		
//		if (visited[nodeU]) continue;
//		for (auto& it: unEdge[nodeU]){
//			int nodeV = it.second.first;
//			int wayV = it.second.second;
//			long long int distUV = it.first;
//			//cout << " - "<<wayV << endl;
//			if (danhdau[wayV]) tongS[nodeV] = tongS[nodeU] + distUV, danhdau[wayV] = false;
//			if (nodeV!=s2) q.push(nodeV);
//		}
//		visited[nodeU] = true;
//	}
//	return;
//}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//ifstream fi("input.inp");
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		edge[a].push_back({-1,{{c,b},{i,-1}}});
		edge[b].push_back({-1,{{c,a},{i,-1}}});
	}
	cin >> s[1] >> t[1]; p[1] = 0;
	for (int i = 2; i <= k; i++){
		cin >> p[i] >> s[i] >> t[i];
	}
	
	for (int i = 1; i <= k; i++){
		d.assign(n+1,INF);
		d[s[i]] = 0;
		dijsktra(s[i],i);
	}
	initDanhDau(t[1]);
	for (int i = 2; i <= k; i++) editDanhDau(t[i],i);
	bfs(t[1]);
	for (int i = 1; i <= n; i++) cout << tongS[i] << " "; cout << endl;
	
	for (int i = 1; i <= m ; i++) cout << "{"<< danhdau[i].first.first<<","<<danhdau[i].first.second<<","<< danhdau[i].second.first<<","<<danhdau[i].second.second << "} " ; cout << endl;
	
	cout << tongS[s[1]];	
	//cout << s[2] << " -> " <<t[2] << endl;
	//cout <<  d[t[2]] << '\n';
	for (int i = 1; i<= n;i++){
		cout << i <<":  ";
		for (auto&  it: unEdge[2][i]){
			cout << " {"<<it.second.first.second<<","<<it.second.first.first<<","<<it.second.second.first<<","<<it.first<<","<<it.second.second.second<<"} ";
		}
		cout << endl;
	}
	//for (int i = 1; i <= m; i++) cout << i << " " << danhdau[i] << endl;
	
	
	
	return 0;
}
