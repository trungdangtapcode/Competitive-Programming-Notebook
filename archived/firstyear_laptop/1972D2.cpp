#include<bits/stdc++.h>

using namespace std;
int n, m;
void solve(){
	cin >> n >> m;
	long long res = 0;
	for (int i = 1; i*i <= n; i++) for (int j = 1; j*j <= m; j++) if (__gcd(i,j)==1){
		res += min(n/i,m/j)/(i+j);
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

