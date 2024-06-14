#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, k, a[maxN];
int check(int x){
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += max(0ll,x-a[i]);
	return k-sum;
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l = 0, h = k/n+a[n]+1, m, res, pos;
	while (l<=h){
		m = (l+h)/2;
		int tmp = check(m);
		if (tmp>=0){
			res = m;
			pos = tmp; //rem
			l = m+1;
		} else h = m-1;
	}
	int bonus = 0;
	for (int i = 1; i <= n; i++) bonus += a[i]>res;
	cout << res*n-n+1 + pos+bonus << "\n";// << res*n-8 << " " << pos << " " << bonus;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

