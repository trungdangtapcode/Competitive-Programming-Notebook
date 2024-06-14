#include<bits/stdc++.h>

using namespace std;
long long f(long long n){
	return n*(n+1)/2;
}
void solve(){
	long long n, k;
	cin >> n >> k;
	n = (n+k-1)/k;
	cout << f(n) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

