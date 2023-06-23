#include<bits/stdc++.h>

using namespace std;

long long int a, b, c, d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> a >> b >> c >> d;
		long long int res1 = -1, res2 = -1;
		for (int i = a+1; i <= c; i++){
			long long int x = a*b/__gcd(a*b,1ll*i);
			long long int l = b/x + 1, r = d/x;
			if (l<=r){
				res1 = i;
				res2 = l*x;
			}
		}
		cout << res1 << " " << res2 << "\n";
	}
	
	return 0;
}
