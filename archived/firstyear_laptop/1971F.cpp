#include<bits/stdc++.h>

using namespace std;
#define int long long
int f(int r, int x){
	if (x>r) return 0;
	int y = sqrt(r*r-x*x);
	int res = y+1;
	if (y*y == r*r-x*x) res--;
	return res;
}
void solve(){
	int r;
	cin >> r;
	int res = 0;
	for (int i = 1; i <= r+1; i++){
		res += f(r+1,i)-f(r,i);
	}
	cout << res*4 << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

