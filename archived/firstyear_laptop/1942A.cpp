#include<bits/stdc++.h>

using namespace std;
int n, k;
void solve(){
	cin >> n >> k;
	if (n==k){
		for (int i = 1; i <= n; i++) cout << 1 << " ";
		cout << "\n";
		return;
	}
	if (k==1){
		for (int i = 1; i <= n; i++) cout << i << " ";
		cout << "\n";
		return;
	}
	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

