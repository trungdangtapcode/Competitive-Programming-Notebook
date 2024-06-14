#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], x;
int calc(int x){
	int res = 0, sum = 0;
	for (int i = 1; i <= n; i++){
		sum ^= a[i];
		if ((sum|x)==x) res++, sum = 0;
	}
	return sum==0?res:-1;
}

void solve(){
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= n; i++) pref[i] = pref[i-1]^a[i];
	int res = calc(x);
	for (int i = 30; i >= 0; i--) if (x>>i&1){
		int y = x^(1<<i);
		y |= (1<<i)-1;
		res = max(res,calc(y));
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

