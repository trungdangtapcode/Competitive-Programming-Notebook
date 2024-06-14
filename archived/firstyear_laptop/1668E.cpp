#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	int k = (2*n+1)/3;
	cout << k << "\n";
	for (int i = 1; i <= (k+1)/2; i++){
		cout << i << " " << 2*i-1 << "\n";
	}
	for (int i = (k+1)/2+1; i <= k; i++){
		cout << i << " " << 2*(i-(k+1)/2) << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

