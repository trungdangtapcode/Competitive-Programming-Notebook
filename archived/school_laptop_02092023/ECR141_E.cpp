#include<bits/stdc++.h>

using namespace std;
int n, f[200005], a[200005], b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		fill(f,f+n+1,0);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) if (a[i]>b[i]){
			f[a[i]]--;
			f[b[i]]++;
		}
		for (int i = 1; i <= n; i++) f[i] += f[i-1];
		vector<int> res;
		for (int i = 1; i <= n; i++){
			bool cur = true;
			for (int j = i; j <= n; j+= i) cur &= (!f[j]);
			if (cur) res.push_back(i);
		}
		cout << res.size() << "\n";
		for (auto it: res) cout << it << " "; cout << "\n";
	}
	
	return 0;
}
