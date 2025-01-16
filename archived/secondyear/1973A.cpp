#include<bits/stdc++.h>

using namespace std;
int a, b, c;
void solve(){
	cin >> a >> b >> c;
	if ((a+b+c)%2!=0){
		cout << -1 << "\n";
		return;
	}
	int res = -2;
	for (int aa = a; aa >= 0; aa -= 2) for (int bb = b; bb >= 0; bb -= 2) for (int cc = c; cc >= 0; cc -= 2){
		if (aa+bb>=cc&&aa+cc>=bb&&cc+bb>=aa){
			res = max(res,aa+bb+cc);
		}
	}
	cout << res/2 << "\n";
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

