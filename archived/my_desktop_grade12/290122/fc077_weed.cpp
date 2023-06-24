#include<bits/stdc++.h>

using namespace std;
int n, a = -1e9, b = 1e9;
int main(){
	cin >> n;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		a = max(a,x);
		b = min(b,x);
	}
	cout << a-b;
	
	return 0;
}
