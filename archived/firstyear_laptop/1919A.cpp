#include<bits/stdc++.h>

using namespace std;
void solve(){
	int a, b;
	cin >> a >> b;
	cout << ((a+b)%2?"Alice\n":"Bob\n");
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	return 0;
}
