#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> id;
vector <id> edge[500005];
vector <long long int> d;
int n, k;

void bfs(int s){
	queue <int> q;
	q.push(s);
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (auto& it: edge[u]){
			int v = it.first;
			int c = it.second;
			if (d[v]==-1){
				d[v] = d[u] + c; 
				q.push(v);
			}
		}
		
	}
	return;
}


int main(){
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[a-1].push_back({b-1,c});
		edge[b-1].push_back({a-1,c});
	}
	d.assign(n,-1);
	d[0] = 0;
	bfs(0);
	for (int i = 0; i < n; i++) cout << d[i] << " ";
	
	return 0;
}
