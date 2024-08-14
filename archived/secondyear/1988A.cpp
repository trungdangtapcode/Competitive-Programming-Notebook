#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	cout << (n-1+k-2)/(k-1) << "\n";
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

