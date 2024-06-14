#include<bits/stdc++.h>

using namespace std;
int n, m;
string s[105];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	if (s[1][1]=='1'){
		cout << -1 <<"\n";
		return;
	}
	vector<vector<int>> res;
	for (int i = 1; i <= n; i++){
		for (int j = m; j > 1; j--) if (s[i][j]=='1'){
			res.push_back({i,j-1,i,j});
		}
	}
	for (int i = n; i > 1; i--) if (s[i][1]=='1'){
		res.push_back({i-1,1,i,1});
	}
	cout << res.size() << "\n";
	for (auto &it: res){
		for (auto x: it){
			cout << x << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

