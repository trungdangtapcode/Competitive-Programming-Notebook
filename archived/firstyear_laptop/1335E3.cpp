#include<bits/stdc++.h>

using namespace std;
int n, a[200005], cnt[200005][205];
vector<int> pos[205];
void solve(){
	cin >> n;
	for (int i = 1; i <= 200; i++) pos[i].clear();
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 1; j <= 200; j++){
			cnt[i][j] = cnt[i-1][j] + (a[i]==j); 
		}
		pos[a[i]].push_back(i);
	}
	int res = 0;
	for (int i = 1; i <= 200; i++){
		res = max(res,(int)pos[i].size());
		for (int j = 0; 2*j < ((int)pos[i].size()-1); j++){
			int l = pos[i][j], r = pos[i][pos[i].size()-1-j];
			for (int x = 1; x <= 200; x++) res = max(res,2*(j+1)+cnt[r-1][x]-cnt[l][x]);
		}
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--) solve();
	
	return 0;
}
