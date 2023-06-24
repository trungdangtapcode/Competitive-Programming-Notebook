#include <bits/stdc++.h>

using namespace std;
bool prime[1000005];
long long int n, m, q;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	memset(prime,true,sizeof(prime));
	prime[1] = false;
	for (long long int i = 2; i <= 1e6; i++) if (prime[i]){
		for (long long int j = i*i; j <= 1e6; j += i) prime[j] = false;
	}
	
	cin >> q;
	while (q--){
		cin >> n;
		m = sqrt(n);
		cout << (m*m==n&&prime[m]) << '\n';
	}
	
	return 0;
}
