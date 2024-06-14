#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	int cur = 501;
	cin >> n;
	cout << cur << " ";
	for (int i = 2; i <= n; i++){
		int y; cin >> y;
		cur += y;
		cout << cur << " ";
	}	
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

