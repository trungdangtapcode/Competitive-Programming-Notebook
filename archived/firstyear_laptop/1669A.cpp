#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x; cin >> x;
	if (x>=1900) cout << "Division 1\n";
	else if (x>=1600) cout << "Division 2\n";
	else if (x>=1400) cout << "Division 3\n";
	else cout << "Division 4\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

