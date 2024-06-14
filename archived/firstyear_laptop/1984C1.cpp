#include<bits/stdc++.h>

using namespace std;
long long n, a;
void solve(){
	long long mmin = 0, mmax = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a;
		long long tmp1 = mmin, tmp2 = mmax;
		mmax = max({tmp1+a,tmp2+a,abs(tmp1+a), abs(tmp2+a)});
		mmin = min({tmp1+a,tmp2+a,abs(tmp1+a), abs(tmp2+a)});
	}
	cout << mmax << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

