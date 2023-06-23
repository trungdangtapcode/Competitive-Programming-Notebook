#include<bits/stdc++.h>

using namespace std;
int n, m, k, a[105], b[105];
vector<int> res;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		bool hasAns = true;
		res.clear();
		for (int i = 0, j = 0;;){
			while (i<n&&a[i]==0) k++, res.push_back(a[i++]);
			while (j<m&&b[j]==0) k++, res.push_back(b[j++]);
			if ((i>=n||a[i]>k)&&(j>=m||b[j]>k)) break;
			if (i<n&&a[i]<=k) res.push_back(a[i++]);
			if (j<m&&b[j]<=k) res.push_back(b[j++]);
		}	
		hasAns = res.size()==m+n;
		if (hasAns) for (auto it: res) cout << it << " ";
		else cout << -1;
		cout << "\n";
	}
	
	return 0;
}
