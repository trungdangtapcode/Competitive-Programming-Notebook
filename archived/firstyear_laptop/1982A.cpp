#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii x, y;
void solve(){
	cin >> x.first >> y.first >> x.second >> y.second;
	if (x>y) swap(x,y);
	cout << (x.second>=y.second?"NO\n":"YES\n");
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

