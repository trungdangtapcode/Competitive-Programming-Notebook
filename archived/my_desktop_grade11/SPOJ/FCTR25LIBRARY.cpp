#include <bits/stdc++.h>

using namespace std;
int n, m;
long long int res;
vector<int> c[100005];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0, x, y; i < m; i++) cin >> x >> y, c[x-1].push_back(y-1), c[y-1].push_back(x-1);
	
	queue<int> q;
	vector<bool> visited(n);
	for (int i = 0, u, v, mmin; i < n; i++) if (!visited[i]){
		mmin = a[i]; //u node -1
		q.push(i);
		while (!q.empty()){
			u = q.front(); q.pop();
			visited[u] = true;
			for (int v: c[u]) if (!visited[v]){
				mmin = min(mmin,a[v]);
				q.push(v);
			}
		}
		res += mmin;
	}	
	cout << res;
	return 0;
}
