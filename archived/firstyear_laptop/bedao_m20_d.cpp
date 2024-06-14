#include<bits/stdc++.h>

using namespace std;

int n, m, a[100005], d[100005];
vector<int> edge[100005];

int check(int x){
	if (x<a[1]) return 1e9;
	queue<int> q;
	q.push(1);
	d[1] = 1;
	for (int i = 2; i <= n; i++) d[i] = 1e9;
	while (q.size()){
		int u = q.front(); q.pop();
		for (int v: edge[u]) if (d[v]==1e9&&a[v]<=x){
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	return d[n];
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int l = 0, h = n, m, ans = 1e9;
	while (l <= h){
		m = (l+h)>>1;
		int fm = check(m);
		ans = min(ans,abs(fm-m));
		if (fm>=m){
			l = m+1;
		} else h = m-1;
	}
	m--;
	ans = min(ans,abs(check(m)-m));
	cout << (ans>1e8?-1:ans) << "\n";
	
	return 0;
}
