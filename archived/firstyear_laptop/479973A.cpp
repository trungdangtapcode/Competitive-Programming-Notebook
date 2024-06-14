#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 4e5+5;
int n, w, a[maxN], b[maxN], x[maxN], pi[maxN];
main(){
	
	cin >> n >> w;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = n; i > 1; i--){
		a[i] -= a[i-1];
		x[w+i-1] = a[i];	
	}
	for (int i = 1; i <= w; i++){
		cin >> b[i];
	}
	for (int i = w; i > 1; i--){
		b[i] -= b[i-1];
		x[i-1] = b[i]; 
	}
	if (w==1){
		cout << n;
		return 0;
	}
	x[w] = -2e9;
	int nx = n+w-1;
//	for (int i = 1; i <= nx; i++) cout << x[i] << " "; cout << "\n";
	pi[1] = 0;
	int res = 0;
	for (int i = 2; i <= nx; i++){
		int k = pi[i-1];
		while (k&&x[k+1]!=x[i]) k = pi[k];
		if (x[k+1]==x[i]) pi[i] = k+1;
		else pi[i] = 0;
		if (pi[i]==w-1) res++;
	}
	cout << res << "\n";
//	for (int i = 1; i <= nx; i++) cout << pi[i] << " "; cout << "\n";
	
	return 0;
}
