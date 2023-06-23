#include<bits/stdc++.h>

using namespace std;
vector<int> prvv[200005];
bool f[200005];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n;	
		for (int i = 0; i <= n; i++) f[i] = false, prvv[i].clear();
		for (int i = 1, a, u, v; i <= n; i++){
			cin >> a;
			u = i-a; v = i;
			if (u>=1) prvv[v].push_back(u);
			u = i; v = i+a;
			if (v<=n) prvv[v].push_back(u);
		}
		f[0] = true;
		for (int i = 1; i <= n; i++){
			for (int u: prvv[i]) f[i] |= f[u-1];
		}
		cout << (f[n]?"YES":"NO") << "\n";
	}
	
	return 0;
}
