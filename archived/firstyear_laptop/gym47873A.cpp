#include<bits/stdc++.h>

using namespace std;
int a,b,c,n;
void solve(){
	cin >> a >> b >> c >> n;
	n -= min(n/100,c)*100;
	n -= min(n/10,b)*10;
	n -= min(n,a);
	cout << (n?"NO\n":"YES\n");
}
int main(){
	int t; cin >> t;
	while (t--) solve();
	
	
	return 0;
}
