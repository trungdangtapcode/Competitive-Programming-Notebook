#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include <tuple> 
#define fix cout<<"fix"<<endl;
using namespace std;
typedef pair<int, long long int> id;
long long int INF = 1e15;
int n,k,s;
vector<vector<id>> edges (3005);
vector<long long int> d;
vector<int> deep;
 
void bfs(int x) {
	queue<id> q;
	q.push({ x,0 });
	while (!q.empty()){
		int nodeU = q.front().first;
		long long int distU = q.front().second;
		q.pop();
		
		for (auto& i : edges[nodeU]) {
			int nodeV = i.first;
			long long int distUV = i.second;
			if (d[nodeV] != INF) continue;
			deep[nodeV] = deep[nodeU] + 1;
			d[nodeV] = distU + distUV;
			q.push({ nodeV,d[nodeV] });
		}
	}
	return;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s >> k;
 
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a-1].push_back({b-1,1});
		edges[b-1].push_back({a-1,1});
	}
	deep.assign(n, 3005);
	deep[s-1] = 0;
	d.assign(n, INF); 
	d[s-1] = 0; 
	bfs(s-1);
	
	int result = 3005;
	cout << d[k-1];
	//if (result == 3005) cout << -1; else cout << result;
	return 0;
}
