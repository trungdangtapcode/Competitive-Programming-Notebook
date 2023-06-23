#include<bits/stdc++.h>

using namespace std;

int phi[100005], n;
long long int sum[100005];

int main(){
	for (int i = 0; i <= 1e5; i++) phi[i] = i;
	for (int i = 2; i <= 1e5; i++) if (phi[i]==i){
		for (int j = i; j <= 1e5; j += i) phi[j] -= phi[j]/i;
	}
	for (int i = 1; i <= 1e5; i++) sum[i] = sum[i-1] + phi[i];
	n = 10;
	long long int res = 0;
	for (int i = 2; i <= n; i++) if (phi[i]==i-1){
		int x = n/i;
		res += 2*sum[x]-1;
	}
	cout << res;
	
	
	return 0;
}
