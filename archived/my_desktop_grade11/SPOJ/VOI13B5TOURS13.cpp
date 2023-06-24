#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair < pair < int, int > , int > id;
vector <id> edge;
int head[1005];
typedef pair <int, int> pack;

int dijkstra(int s){
	if (head[s] == -1) return -1;
	priority_queue<pack, vector<pack>, greater<pack>> heap;
	vector <int> d(n+1,-1);
	
	heap.push({edge[head[s]].first.second,head[s]});
	while (!heap.empty()){
		pack x = heap.top();
		if (edge[x.second].second==s) return x.first;
		
		int nodeU = edge[x.second].second;
		d[nodeU] = x.first;
		if (head[nodeU]!=-1) heap.push({d[nodeU]+edge[head[nodeU]].first.second,head[nodeU]});//cout << "pushed: " << edge[head[nodeU]].second <<" (" <<d[nodeU]+edge[head[nodeU]].first.second << ")"<<  endl;
		//cout << nodeU << endl;
		
		while (d[edge[heap.top().second].second]!=-1){
			int y = heap.top().second; //edge
			heap.pop();
			int nodeU = edge[y].first.first;
			while (y < m && edge[y].first.first == nodeU){
				int nodeV = edge[y].second;
				if (d[nodeV]==-1){
					if (nodeU == s) heap.push({0+edge[y].first.second,y});
					else heap.push({d[nodeU]+edge[y].first.second,y});
					//cout << "pushed: " << edge[y].second  << " (" <<d[nodeU]+edge[y].first.second << ")"  << endl;
					break;
				}
				y++;
			}
		}
	}
	return -1;
}

int main(){
	int t; cin >> t;
	while (t--){
		edge.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			edge.push_back({{a,c},b});
		}
		sort (edge.begin(),edge.end());
	
		memset(head,-1,sizeof(head));
		for (int i = 0; i < m; i++){
			if (head[edge[i].first.first]==-1) head[edge[i].first.first] = i;
		}
		//cout << endl;
		//for (int i = 0; i < m; i++) cout << i <<". "<< edge[i].first.first << " " << edge[i].second << " " << edge[i].first.second << endl;
		//cout << dijkstra(3);
		
		for (int i = 1; i <= n; i++) cout << dijkstra(i) << '\n';
		//for (int i = 1; i <= n; i++) cout << i << " " << head[i] << endl;
	}
	
	return 0;
}






//#include <bits/stdc++.h>
//
//using namespace std;
//int n, m;
//struct canh {int u, v, c;};
//vector <canh> edge;
//
//int main(){
//	
//	cin >> n >> m;
//	edge.resize(m);
//	for (auto& it: edge){
//		cin >> it.u >> it.v >> it.c;
//	}
//	sort (edge.begin(),edge.end(),[](canh a, canh b){return (a.u<b.u)||(a.u == b.u && a.c<b.c);});
//	for (int i = 0; i < m; i++){
//		cout << edge[i].u << " " << edge[i].v << " " << edge[i].c <<endl;
//	}
//	
//	
//	return 0;
//}

//for (int i = 0; i < m; i++){
//		cout << edge[i].first.first << " " << edge[i].second << " " << edge[i].first.second <<endl;
//	}
