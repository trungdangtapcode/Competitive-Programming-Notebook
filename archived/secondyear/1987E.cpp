#include<bits/stdc++.h>

using namespace std;
const int maxN = 5005;
int n, a[maxN], d[maxN];
long long b[maxN];
vector<int> edge[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		edge[i].clear();
	}
	for (int i = 2; i <= n; i++){
		int p; cin >> p;
		edge[p].push_back(i);
		d[i] = d[p]+1;
	}
	for (int i = 1; i <= n; i++){
		if (edge[i].size()==0){
			b[i] = 1e18;
			continue;
		}
		b[i] = 0;
		for (int v: edge[i]){
			b[i] += a[v];
		}
		b[i] -= a[i];
	}
	long long res = 0;
	for (int i = n; i >= 1; i--){
		queue<int> q;
		q.push(i);
		while (b[i]<0){
			int u = q.front(); q.pop();
			for (int v: edge[u]){
				long long tmp = min(-b[i],b[v]);
				if (tmp>0){
					b[i] += tmp;
					b[v] -= tmp;
					res += tmp*(d[v]-d[i]);
				}
				q.push(v);
			}
		}
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

