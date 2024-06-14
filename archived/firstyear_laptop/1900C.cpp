#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int > ii;
const int maxN = 2e6+5;
int n, l[maxN], r[maxN];
string s;
int dfs(int u){
	if (u==0) return 1e9;
	if (l[u]==0&&r[u]==0) return 0;
	return min(dfs(l[u])+(s[u]!='L'),dfs(r[u])+(s[u]!='R'));
}
void solve(){
	cin >> n >> s;
	s = "#" + s;
	for (int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	cout << dfs(1) << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
