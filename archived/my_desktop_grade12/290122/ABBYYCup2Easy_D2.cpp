#include<bits/stdc++.h>

using namespace std;
int n, m, c, a[100005], b[100005];
int main(){
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1, x; i <= m; i++){
		cin >> x;
		b[i] += x;
		b[n-m+i+1] -= x;
	}
	for (int i = 1; i <= n; i++){
		(b[i] += b[i-1]) %= c;
		(((a[i] += b[i])%=c)+=c)%=c;
		cout << a[i] << " ";
	}
	
	return 0;
}
