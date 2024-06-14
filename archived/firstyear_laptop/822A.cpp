#include<bits/stdc++.h>

using namespace std;
int a, b;
void solve(){
	cin >> a >> b;
	if (a>b) swap(a,b);
	long long res = 1;
	for (int i = 2; i <= a; i++) res *= i;
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

