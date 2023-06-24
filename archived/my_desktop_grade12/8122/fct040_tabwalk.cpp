#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, res = 1e12;
main(){
	cin >> n;
	for (int i = 1; i*i <= n; i++) if (n%i==0){
		res = min(res,i+n/i-2);
	}
	cout << res;
	
	return 0;
}
