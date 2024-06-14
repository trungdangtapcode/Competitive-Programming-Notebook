#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	cout << (1<<__lg(n)) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

