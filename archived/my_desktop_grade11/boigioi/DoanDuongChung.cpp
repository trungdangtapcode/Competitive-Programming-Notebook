#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
long long int INF = 1e16;
int n, m, s1, t1, s2, t2;

typedef pair< long long int, pair<int, int> > id;
vector <id> edge[100005], unEdge[100005];;
vector <long long int> d;
bool danhdau[100005], visited[100005];
long long int tongS[100005];

void dijsktra(int x){
	priority_queue<id, vector<id>, greater<id>> pq;
	pq.push({0,{x,-1}});
	
	while (!pq.empty()){
		int nodeU = pq.top().second.first;
		long long int distU = pq.top().first;
		//int wayU = pq.top().second.second;
		pq.pop();
		
		if (distU!=d[nodeU]) continue;
		for (auto& it: edge[nodeU]){
			int nodeV = it.second.first;
			long long int distUV = it.first;
			int wayV = it.second.second;
			
			if (distU+distUV<d[nodeV]){
				d[nodeV] = distU + distUV;
				pq.push({d[nodeV],{nodeV,-1}});
				unEdge[nodeV].clear();
				unEdge[nodeV].push_back({distUV,{nodeU,wayV}});
			} else if (distU+distUV==d[nodeV]) unEdge[nodeV].push_back({distUV,{nodeU,wayV}});
		}
	}
	return;
}
void bfsNam(int x){
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[nodeU]){
			int nodeV = it.second.first;
			int wayV = it.second.second;
			//cout << " - "<<wayV << endl;
			danhdau[wayV] = true;
			if (nodeV!=s1) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}
void bfsViet(int x){
	queue<int> q;
	q.push(x);
	
	while (!q.empty()){
		int nodeU = q.front();
		q.pop();
		
		if (visited[nodeU]) continue;
		for (auto& it: unEdge[nodeU]){
			int nodeV = it.second.first;
			int wayV = it.second.second;
			long long int distUV = it.first;
			//cout << " - "<<wayV << endl;
			if (danhdau[wayV]) tongS[nodeV] = tongS[nodeU] + distUV, danhdau[wayV] = false;
			if (nodeV!=s2) q.push(nodeV);
		}
		visited[nodeU] = true;
	}
	return;
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> s1 >> t1 >> s2 >> t2;
	for (int i = 1; i <= m; i++){
		int a, b;
		long long int c;
		cin >> a >> b >> c;
		edge[a].push_back({c,{b,i}});
		edge[b].push_back({c,{a,i}});
	}
	
	memset(danhdau,false,sizeof(danhdau));
	d.assign(n+1,INF);
	d[s1] = 0;
	dijsktra(s1);
	memset(visited,false,sizeof(visited));
	bfsNam(t1);
	
	//for (int i = 1; i <= m; i++) cout << i << " " << danhdau[i] << endl;
	
	for (int i = 1; i <= n; i++) unEdge[i].clear();
	d.assign(n+1,INF);
	d[s2] = 0;
	dijsktra(s2);
	memset(visited,false,sizeof(visited));
	tongS[t2] = 0;
	bfsViet(t2);
	
	cout <<  tongS[s2] << '\n';
//	cout << d[t2] << endl;
//	for (int i = 1; i<= n;i++){
//		cout << i <<":  ";
//		for (auto&  it: unEdge[i]){
//			cout << it.first << " ";
//		}
//		cout << endl;
//	}
	//for (int i = 1; i <= m; i++) cout << i << " " << danhdau[i] << endl;
	
	
	
	return 0;
}
