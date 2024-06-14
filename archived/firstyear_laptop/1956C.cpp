#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i*(2*i-1);
	cout << sum << " " << 2*n << "\n";
//	return;
	for (int i = 1; i <= n; i++){
		cout << 1 << " " << i << " ";
		for (int j = n; j >= 1; j--) cout << j << ' ';
		cout << "\n"; 
		cout << 2 << " " << i << " ";
		for (int j = n; j >= 1; j--) cout << j << ' ';
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

