#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cout << i << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

