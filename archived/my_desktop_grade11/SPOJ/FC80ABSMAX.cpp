#include <bits/stdc++.h>

using namespace std;
int a[200005], n;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	cout << max(abs(a[n-1]+a[n-2]),abs(a[0]+a[1]));
	return 0;
}
