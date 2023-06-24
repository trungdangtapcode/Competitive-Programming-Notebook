#include <bits/stdc++.h>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	long long int s[105][105];
	memset(s,0,sizeof(s));
	//m dong, n cot
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++){
			cin >> s[i][j];
			s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}	
	vector<long long int> a;
	int x, y, u, v;
	for (int i = 1; i <= k; i++){
		cin >> x >> y >> u >> v;
		a.push_back(s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1]);
	}
	//for (auto& i : a) cout << i << endl; 
	cout << *max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
	return 0;
}
