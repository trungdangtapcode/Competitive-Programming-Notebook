#include<bits/stdc++.h>

using namespace std;
int x, y, k;
void solve(){
	cin >> x >> y >> k;
	int c1 = (x+k-1)/k, c2 = (y+k-1)/k;
	c2 = max(c2, c1-1);
	c1 = max(c1, c2);
	cout << c1+c2 << "\n";
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

