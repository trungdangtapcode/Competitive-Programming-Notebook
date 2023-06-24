#include <bits/stdc++.h>

using namespace std;
int n, k;
bool prime[10000005];
int pref[10000005];

int main(){
	
	cin >> n >> k;
	
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; (long long int)i*i <= n; i++) if (prime[i]){
		for (int j = i*i; j <= n; j+=i) prime[j] = false;
	}
	pref[0] = pref[1] = 0;
	for (int i = 2; i <= n; i++) pref[i] = pref[i-1] + (prime[i]);
	
	long long int res = 0;
	for (int i = 1, j = 1; i <= n; i++){
		while (pref[i]-pref[j-1]>=k) j++;//, res+=j;
		res += j-1;
	}
	cout << res;
	return 0;
}
