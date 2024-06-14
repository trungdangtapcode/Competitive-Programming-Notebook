#include<bits/stdc++.h>

using namespace std;
int a, b;
void solve(){
	cin >> a >> b;
	if (b%a==0){
		cout << b*(b/a) << "\n";
	} else {
		cout << a*(b/__gcd(a,b)) << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
