#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <int> edge[2005];
bool visited[2005];


int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}
	int tplt = 0;
	for (int i = 0; i < n; i++) if (!visited[i]){
		queue<int> q;
		q.push(i);
		while (!q.empty()){
			int nodeU = q.front();
			q.pop();
			if (visited[nodeU]) continue;
			for (auto& it: edge[nodeU]){
				int nodeV = it;
				q.push(nodeV);
			}
			visited[nodeU] = true;
		}
		tplt++;
	}
	cout << m-n+tplt;
	return 0;
}
