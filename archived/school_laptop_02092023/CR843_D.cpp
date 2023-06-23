#include<bits/stdc++.h>

using namespace std;

int spf[1000005], n, s, t, d[1000005], trace[1000005];
bool check[1000005];
vector<int> dPrime[1000005], pFact[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 2; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e6; i++) if (spf[i]==i){
		for (int j = i*i; j <= 1e6; j += i) spf[j] = i;
	}
	cin >> n;
	for (int i = 1, a; i <= n; i++){
		cin >> a;
		while (a>1){
			int d = spf[a];
			dPrime[d].push_back(i);
			pFact[i].push_back(d);
			while (a%d==0) a /= d;
		}
	}
	cin >> s >> t;
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	d[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto p: pFact[u]){
			if (check[p]) continue;
			check[p] = true;
			for (auto v: dPrime[p]) if (d[v]>d[u]+1){
				d[v] = d[u]+1;
				q.push(v);
				trace[v] = u;
			}
		}
	}
	if (d[t]==1e9) return cout << -1,0;
	cout << d[t] << "\n";
	vector<int> res;
	for (int i = 0, u = t; i < d[t]; i++){
		res.push_back(u);
		u = trace[u];
	}
	reverse(res.begin(),res.end());
	for (int x: res) cout << x << " ";
	
	return 0;
}
