#include<bits/stdc++.h>

using namespace std;
void solve(){
	int a[] = {0,0,0};
	cin >> a[0] >> a[1] >> a[2];
	for (int i = 1; i <= 5; i++){
		sort(a,a+3);
		a[0] += 1;
	}
	cout << a[0]*a[1]*a[2] << "\n";
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

