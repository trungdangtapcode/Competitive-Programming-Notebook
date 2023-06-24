#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	int res = 2e9;
	for (int i = 0, b; i < n; i++){
		cin >> b;
		auto it = lower_bound(a,a+n,-b);
		if (it!=a+n) res = min(res,abs(*it+b));
		if (it!=a) it--;
		res = min(res,abs(*it+b));	
	}
	cout << res;
	
	return 0;
}
