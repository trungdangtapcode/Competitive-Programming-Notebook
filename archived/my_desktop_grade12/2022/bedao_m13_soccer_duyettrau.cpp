#include<bits/stdc++.h>

using namespace std;
int n, m, c[205][205];
bool check[205];
vector<int> v;
int res = 1e9;

void solve(){
	memset(check,0,sizeof(check));
	for (int u: v) check[u] = true;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= 2*n; i++) if (check[i]) for (int j = i+1; j <= 2*n; j++) if (check[j]) sum1 += c[i][j];
	for (int i = 1; i <= 2*n; i++) if (!check[i]) for (int j = i+1; j <= 2*n; j++) if (!check[j]) sum2 += c[i][j];
	res = min(res,abs(sum1-sum2));
}

void sinh(int u, int s){
	if (s==n){
		solve();
	}
	if (2*n-u<2*n-s-2||u>2*n) return;
	sinh(u+1,s);
	v.push_back(u);
	sinh(u+1,s+1);
	v.pop_back();
}

int main(){
	cin >> n >> m;
	for (int i = 0, u, v, ic; i < m; i++){
		cin >> u >> v >> ic;
		c[u][v] = ic;
		c[v][u] = ic;
	}
	sinh(1,0);
	cout << res;
	
	return 0;
}
