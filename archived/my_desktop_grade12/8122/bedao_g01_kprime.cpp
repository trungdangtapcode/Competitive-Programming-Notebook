#include<bits/stdc++.h>

using namespace std;
int p[10000005], n , k;
long long int res;
int main(){
	cin >> n >> k;
	for (int i = 2; i <= n; i++) p[i] = 1;
	for (int i = 2; i <= n; i++) if (p[i]) for (int j = min(1ll*i*i,1ll*n+1); j <= n; j+=i) p[j] = 0;
	for (int i = 1; i <= n; i++) p[i] += p[i-1];
	for (int i = 1, j = 0; i <= n; i++){
		while (j<n&&p[j]-p[i-1]<k) j++;
		if (p[j]-p[i-1]>=k){
			res += (n-j+1);
		}
	}
	cout << res;
	
	return 0;
}
