#include <bits/stdc++.h>

using namespace std;
int n;
long long int k, a[1000005];

bool check(long long int x){
	long long int res = 0;
	for (int i = 1; i <= n; i++) res += max(a[i]-x,0ll);
	return (res>=k);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	long long int l = 0, h = 1e9, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			res = m;
			l = m + 1;
		} else h = m - 1;
	}
	cout << res;
	
	
	return 0;
}
