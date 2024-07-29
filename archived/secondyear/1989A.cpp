#include<bits/stdc++.h>

using namespace std;
const int maxN = 1005;
typedef pair<int,int> ii;
int i = 0;
int dis(const ii &a, const ii &b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int x, y;
void solve(){
	cin >> x >> y;
	cout << (y>=-1?"YES\n":"NO\n");
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

