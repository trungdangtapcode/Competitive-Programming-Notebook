#include<bits/stdc++.h>

using namespace std;
long long n, m;
void solve(){
	cin >> n >> m;
	if (n>m) swap(n,m);
	if (n==1&&m>2){
		cout << -1 << "\n";
		return;
	}
	cout << (2*n-2+ 2*(m-n) -((m-n)%2?1:0)) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

