#include <bits/stdc++.h>

using namespace std;
long long int n, mu10[20], demso[20];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	mu10[0] = 1; demso[0] = 1;
	for (int i = 1; i <= 18; i++) mu10[i] = mu10[i-1]*10;
	for (int i = 1; i <= 18; i++) demso[i] = (mu10[i]-1)-mu10[i-1]+1;
	int i = 1;
	while (i*demso[i]<n){
		n -= i*demso[i];
		i++;
	}
	long long int m = mu10[i-1] + (n-1)/i;
	cout << to_string(m)[(n-1)%i];
	
	
	return 0;
}
