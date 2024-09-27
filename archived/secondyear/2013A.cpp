#include<bits/stdc++.h>

using namespace std;
int x, y, n;
void solve(){
	cin >> n >> x >> y;
//	int t = x/y;
//	int a = (n+x-1)/x, b = (n+x-1)/x;
	cout << (n+min(x,y)-1)/min(x,y) << "\n";
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

