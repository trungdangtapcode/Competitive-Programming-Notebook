#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, a[maxN], d[maxN];
void solve(){
	cin >> n;
	int mmax = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i-1]<a[i]){
			d[a[i-1]+1]++;
			d[a[i]+1]--;
		}
		mmax = max(mmax,a[i]);
	}
	for (int i = 1; i <= mmax; i++) d[i] += d[i-1];
	for (int i = 1; i <= mmax; i++){
		long long res = 0;
		for (int j = 0; i*j+1 <= mmax; j++) res += d[i*j+1];
		cout << res << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

