#include <bits/stdc++.h>

using namespace std;
vector <pair <int, pair <int, int>>> w, w0; //
int n, m, cha[100005], q;

int timcha(int u){
	if (cha[u]<0) return u;
	cha[u] = timcha(cha[u]);
	return cha[u];
}
void hop(int u, int v){
	if (timcha(u)==timcha(v)) return;
	if (cha[timcha(u)]<cha[timcha(v)]){
		cha[timcha(v)] += cha[timcha(u)];
		cha[timcha(v)] = timcha(u);
	} else {
		cha[timcha(u)] += cha[timcha(v)];
		cha[timcha(u)] = timcha(v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> q;
		w.resize(m);
		for (int i = 0; i < m; i++){
			cin >> w[i].second.first >> w[i].second.second >> w[i].first;
			w[i].second.first--;
			w[i].second.second--;
		}
		while (q--){
			//tmp graph
			w0 = w;
			for (int i = 0; i < n; i++) cha[i] = -1;
			
			int k, m0;
			cin >> k >> m0;
			k--;
			while (m0--){
				int u, c;
				cin >> u >> c;
				w0[u-1].first = c;
			}
			for (auto& it: w0) if (it.first<w0[k].first) hop(it.second.first,it.second.second);
			cout << (timcha(w0[k].second.first)==timcha(w0[k].second.second)?"YES":"NO") << '\n';
		}
	}
	
	return 0;
}
