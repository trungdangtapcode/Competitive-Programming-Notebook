#include <bits/stdc++.h>

using namespace std;
int n, a[1000005], prime[1000005];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= 1e6; i++) if (prime[i]){
		for (int j = i*i; j <= 1e6; j+=i) prime[j] = false;
	}
//	for (int i = 0; i <= 100; i++) if (prime[i]) cout << i << " "; cout << endl;
	
	long long int sum = 0, max_end_here = 0, res = -1e7;
	for (int i = 2; i <= n; i++){
		max_end_here += a[i];
		if (prime[i]) res = max(res,max_end_here);
		//cout << (prime[i]?i:-i) << " ";
		if (max_end_here<a[i]&&prime[i]) max_end_here = a[i]; //begin here
	}
	cout << res;
	
	return 0;
}
