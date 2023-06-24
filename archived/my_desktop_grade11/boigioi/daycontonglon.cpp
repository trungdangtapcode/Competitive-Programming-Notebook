#include <bits/stdc++.h>

using namespace std;
int n;
long long int s, a[1000005];



int main(){
	cin >> n >> s;
	a[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	
	int res = n;
	for (int i = 0; i < n; i++){
		int pos = (lower_bound(a,a+n+1,s+a[i])-a);
		if (pos <= n) res = min(res,pos-i);
		//cout << i << " " <<(lower_bound(a,a+n+1,s+a[i])-a)<< endl;
	}
	cout << res;
	
	return 0;
}
