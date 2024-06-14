#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long double res = 0, last = a[1];
	for (int i = 2; i <= n; i++){
		res += (a[i]-last)/2*(i-1);
		last = (last*(i-1)+a[i])/i;
	}
	cout << fixed << setprecision(9) << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

