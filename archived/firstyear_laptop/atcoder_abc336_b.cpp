#include<bits/stdc++.h>

using namespace std;
long long n;
void solve(){
	cin >> n;
	cout << __builtin_ctzll(n);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

