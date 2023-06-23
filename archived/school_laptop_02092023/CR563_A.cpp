#include<bits/stdc++.h>

using namespace std;
int n, a[100005];
int main(){
	
	cin >> n;
	n*= 2;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	if (a[0]==a[n-1]) return cout << -1,0;
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	
	return 0;
}
