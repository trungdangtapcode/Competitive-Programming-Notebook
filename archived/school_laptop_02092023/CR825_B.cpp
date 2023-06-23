#include<bits/stdc++.h>

using namespace std;
int n;
vector<long long int> a, b;

void solve(){
	cin >> n;
	a.assign(n,0);
	b.assign(n+1,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	b[0] = a[0]; b[n] = a[n-1];
	for (int i = 1; i < n; i++) b[i] = a[i-1]*a[i]/__gcd(a[i-1],a[i]);
	for (int i = 0; i < n; i++){
		if (a[i]!=__gcd(b[i],b[i+1])){
			cout << "NO\n";
			return;
		} 
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		solve();
	}
	
	return 0;
}
