#include<bits/stdc++.h>

using namespace std;
int n, m, k;
void solve(){
	cin >> n >> m >> k;
	int tmp = (n+m-1)/m;
	cout << (n-tmp<=k?"NO":"YES") << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

