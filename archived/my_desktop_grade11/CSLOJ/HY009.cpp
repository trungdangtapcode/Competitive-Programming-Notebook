#include <bits/stdc++.h>
//dang le n <= 10^5 (O(nlogn) dung BIT) va a[] cung ko can phai la hoan vi
using namespace std;
int a[105], n;
int main(){
	cin >> n;
	for (int i = 0, dem; i < n; i++){
		cin >> a[i];
		dem = 0;
		for (int j = 0; j < i; j++) dem += (a[j]>a[i]);
		cout << dem << " ";
	}
	return 0;
}
