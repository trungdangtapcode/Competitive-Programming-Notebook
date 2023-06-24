#include <bits/stdc++.h>

using namespace std;
int n, a[200005];

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	long long int res = 1e10;
	for (int i = 1; i < n; i++) res = min(res,1ll*a[i]-a[i-1]);
	cout << res;
	return 0;
}
