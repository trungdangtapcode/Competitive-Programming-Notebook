#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int cnt[2][500005], d[2][500005], n, m, k;
vector<int> edge[500005];
void dijkstra(int x, int u){
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push({0,u});
	d[x][u] = 0;
	while (!pq.empty()){
		int u = pq.top().second, du = pq.top().first;
		pq.pop();
		if (du!=d[x][u]) continue;
		for (int v: edge[u]) if (d[x][v]>du+1){
			d[x][v] = du+1;
			pq.push({du+1,v});
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) d[0][i] = d[1][i] = 1e9;
	dijkstra(0,1); dijkstra(1,n);
	if (k>d[0][n]){
		cout << 0 << "\n";
	} else if (k<d[0][n]) {
		long long res = 0;
		for (int i = 1; i <= n; i++){
			cnt[0][d[0][i]]++;
			cnt[1][d[1][i]]++;
		}
		for (int i = 0; i <= k; i++)
			res += 1ll*cnt[0][i]*cnt[1][k-i-1];
		cout << res;
	} else {
		long long res = 0, cur = 0;
		for (int i = 1; i <= n; i++){
			cnt[0][d[0][i]]++;
			cnt[1][d[1][i]]++;
		}
		for (int i = 0; i < k-1; i++){
			cur += cnt[0][i];
			res += cur*cnt[1][k-i-2];
		}
		cout << 1ll*n*(n-1)/2-m-res;
	}
	
	return 0;
}
//	} else {
//		long long res = 0;
//		for (int i = 1; i <= n; i++){
//			cnt[0][d[0][i]]++;
//		}
//		for (int i = 0; i < k; i++)
//			res += 1ll*cnt[0][i]*cnt[0][i+1]
//	}
		
//		long long res = 0;
//		for (int i = 1; i <= n; i++){
//			cnt[0][d[0][i]]++;
//			cnt[1][d[1][i]]++;
//		}
//		for (int i = 0; i <= k-(k==d[0][n]); i++){
//			res += 1ll*cnt[0][i]*cnt[1][k-i-1] + 1ll*cnt[0][i]*(cnt[0][i]-1)/2*(k==d[0][n]);
//			cout << res << endl;
//		}
//		cout << res - m*(k==d[0][n]);
