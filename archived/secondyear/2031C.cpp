#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	if (n%2==0){
		for (int i = 1; i <= n/2; i++) cout << i << " " << i << " ";
		cout << "\n";
		return;
	}
	if (n<27){
		cout << -1 << "\n";
		return;
	}
	cout << 1 << " " << 2 << " ";
	for (int i = 3; i <= 9; i++) cout << i << " " << i << " ";
	cout << 1 << " " << 2 << " ";
	for (int i = 10; i <= 13; i++) cout << i << " " << i << " ";
	cout << 2 << " ";
	
	for (int i = 14; i <= n/2; i++) cout << i << " " << i << " ";
	cout << "\n";
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

