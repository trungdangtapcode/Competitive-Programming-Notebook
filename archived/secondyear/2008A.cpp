#include<bits/stdc++.h>

using namespace std;
int x, y;
void solve(){
	cin >> x >> y;
	if (x%2==0&&y%2==0){
		cout << "YES\n";
		return;
	}
	if (x%2||y%2&&x<=1){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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

