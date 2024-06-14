#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e3+5;
#define int long long
int n, p, l, t;
int check(int x){
	int task = min((n-1)/7+1,2*(n-x));
	return task*t + (n-x)*l; 
}
void solve(){
	cin >> n >> p >> l >> t;
	int l = 0, h = n, m, res = -1;
//	cout << check(0) << "x\n";
	while (l<=h){
		m = (l+h)/2;
		if (check(m)>=p){
			res = m;
			l = m+1;
		} else h = m-1;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
