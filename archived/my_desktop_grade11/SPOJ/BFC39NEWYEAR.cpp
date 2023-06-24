#include <bits/stdc++.h>

using namespace std;
int n, a[100005], cnt, last;
int main(){
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	last = a[n-1];
	for (int i = n-2; i >= 0; i--)
		if (last<a[i]) cnt++, last = a[i];
	cout << cnt;
	
	return 0;
}
