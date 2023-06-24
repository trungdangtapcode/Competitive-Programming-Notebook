#include<bits/stdc++.h>

using namespace std;


long long n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		int cnt2 = 0, cnt5 = 0;
		while (n%2==0) cnt2++, n/= 2;
		while (n%5==0) cnt5++, n/= 5;
		int res = min(cnt2,cnt5);
		cnt2 -= res, cnt5 -= res;
		while (cnt5&&m>2) cnt5--, res++, m /= 2;
		while (cnt2&&m>5) cnt2--, res++, m /= 5;
		while (m>10) res++, m/= 10;
		while (res) res--, n*= 10;
		while (cnt2) cnt2--, n*= 2;
		while (cnt5) cnt5--, n*= 5;
		n*= m;
		cout << n << "\n";
	}	
	
	
	return 0;
}
