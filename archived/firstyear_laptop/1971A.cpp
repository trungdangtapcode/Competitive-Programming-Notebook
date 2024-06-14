#include<bits/stdc++.h>

using namespace std;

void solve(){
	int x, y; cin >> x >> y; if (x>y) swap(x,y);
	cout << x << " " << y << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

