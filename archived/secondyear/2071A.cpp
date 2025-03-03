#include<bits/stdc++.h>

using namespace std;
int k;
void solve(){
	cin >> k;
	cout << (k%3==1?"YES\n":"NO\n");
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

