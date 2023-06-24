#include <bits/stdc++.h>

using namespace std;
long long int n, m, x, y;
long long int res1, res2, res3;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> x >> y;
		if (n<m) swap(n,m);
		if (m==1){
			cout << (n-1)*x << '\n';
			continue;
		}
		res1 = (n+m-2)*x; //only x
		res2 = (m-1)*y + (n-m)*x; //x + y (1 type way)
		res3 = (m-1)*y + (n-m)/2*(2*y); //only y
		if ((n-m)%2==1) res3 += x; //di zic zac, neu le tien 1 buoc
		cout << min({res1,res2,res3}) << '\n';
	}
	
	return 0;
}
