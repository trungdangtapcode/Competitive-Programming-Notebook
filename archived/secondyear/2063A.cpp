#include<bits/stdc++.h>

using namespace std;
int l, r;
void solve(){
	cin >> l >> r;
	if (l==1&&r==1){
		cout << "1\n";
		return;
	}
	cout << r-l << "\n";
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

