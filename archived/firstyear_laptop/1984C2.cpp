#include<bits/stdc++.h>

using namespace std;
#define int long long
#define ii pair<long long, long long>
const int mod = 998244353;
int n, a;
void solve(){
	ii mmin = {0,1}, mmax = {0,1};
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a;
		ii tmp1 = mmin, tmp2 = mmax;
		mmax.first = max({tmp1.first+a,tmp2.first+a,abs(tmp1.first+a), abs(tmp2.first+a)});
		mmax.second = 0;
		if (tmp1.first+a==mmax.first) mmax.second += tmp1.second;
		if (tmp2.first+a==mmax.first&&tmp1.first!=tmp2.first) mmax.second += tmp2.second;
		if (abs(tmp1.first+a)==mmax.first) mmax.second += tmp1.second;
		if (abs(tmp2.first+a)==mmax.first&&tmp1.first!=tmp2.first) mmax.second += tmp2.second;
		mmax.second %= mod;
		
		mmin.first = min({tmp1.first+a,tmp2.first+a,abs(tmp1.first+a), abs(tmp2.first+a)});
		mmin.second = 0;
		if (tmp1.first+a==mmin.first) mmin.second += tmp1.second;
		if (tmp2.first+a==mmin.first&&tmp1.first!=tmp2.first) mmin.second += tmp2.second;
		if (abs(tmp1.first+a)==mmin.first) mmin.second += tmp1.second;
		if (abs(tmp2.first+a)==mmin.first&&tmp1.first!=tmp2.first) mmin.second += tmp2.second;
		mmin.second %= mod;
	}
	cout << mmax.second << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

