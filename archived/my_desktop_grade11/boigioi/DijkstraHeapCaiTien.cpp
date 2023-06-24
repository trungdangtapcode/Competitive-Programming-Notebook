#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair < pair < int, int > , int > id;
vector <id> edge;
int head[1005];
typedef pair <int, int> pack;

void dijkstra(int s){
	priority_queue<pack, vector<pack>, greater<pack>> heap;
	vector <int> d(n+1,-1);
	d[s] = 0;
	
	if (head[s]!=-1) heap.push({edge[head[s]].first.second,head[s]});
	while (!heap.empty()){
		pack x = heap.top();
		
		int nodeU = edge[x.second].second;
		if (d[nodeU]==-1||x.first<d[nodeU]) {
			if (d[nodeU]==-1) d[nodeU] = x.first; else d[nodeU] = min(d[nodeU],x.first);
			if (head[nodeU]!=-1) heap.push({d[nodeU]+edge[head[nodeU]].first.second,head[nodeU]}); //cout << "pushed: " << edge[head[nodeU]].second <<" (" <<d[nodeU]+edge[head[nodeU]].first.second << ")"<<  endl;
		}
		
		while (d[edge[heap.top().second].second]!=-1&&!heap.empty()){
			int y = heap.top().second; //edge
			//cout << y << " " << heap.size() << endl;
			heap.pop();
			int nodeU = edge[y].first.first;
			//cout << y << " " << edge[y].first.first <<" "<< heap.size() << endl;
			while (y < m && edge[y].first.first == nodeU){
				int nodeV = edge[y].second;
				if (d[nodeV]==-1){
					heap.push({d[nodeU]+edge[y].first.second,y});
					//cout << "pushed: " << edge[y].second  << " (" <<d[nodeU]+edge[y].first.second << ")"  << endl;
					break;
				}
				y++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;
	return;
}

int main(){
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({{a,c},b});
		edge.push_back({{b,c},a});
	}
	m *= 2;
	sort (edge.begin(),edge.end());
	
	//cout << endl;
	//for (int i = 0; i < m; i++) cout << i <<". "<< edge[i].first.first << " " << edge[i].second << " " << edge[i].first.second << endl;

	memset(head,-1,sizeof(head));
	for (int i = 0; i < m; i++){
		if (head[edge[i].first.first]==-1) head[edge[i].first.first] = i;
	}
	
	//for (int i = 1; i <= n; i++) cout << "head[" << i << "] = " << head[i] << endl;
	
	//dijkstra(1);
	//for (int i = 1; i <= n; i++) cout << i << " " << head[i] << endl;
	for (int i = 1; i <= n; i++){
		dijkstra(i);
	}
	
	return 0;
}



