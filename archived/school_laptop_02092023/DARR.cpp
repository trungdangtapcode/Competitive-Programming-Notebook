#include<bits/stdc++.h>

using namespace std;
#define ILNT main()
#define int long long

int a[100005], n, k;
ILNT{
	freopen("DARR.INP","r",stdin);
	freopen("DARR.OUT","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = n-2; i >= 0; i--){
		a[i] += a[i+1];
	}
	sort(a+1,a+n);
	int res = a[0];
	for (int i = n-k+1; i < n; i++) res += a[i];
	cout << res;
	
	return 0;
}
