#include<bits/stdc++.h>

using namespace std;
long long n, a, b;
long long f(long long k){
	k = max(k,0ll);
	k = min({k,n,b});
	return k*(b+1) + (n-k)*a - k*(k+1)/2;
}
void solve(){
	cin >> n >> a >> b;
	long long  res = max(f(-a+b),f(-a+b+1));
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

