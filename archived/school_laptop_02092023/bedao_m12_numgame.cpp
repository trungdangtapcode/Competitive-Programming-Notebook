#include<bits/stdc++.h>

using namespace std;
int inNum[10000005], phi[10000005], spf[10000005], cnt[10000005];
int n;
const int p = 1e9+7;

int main(){
	
	cin >> n;
	
	inNum[0] = inNum[1] = 1;
	for (int i = 2; i <= 100; i++) inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
	for (int i = 0; i <= n; i++) spf[i] = 1, phi[i] = i;
	for (int i = 2; i <= n; i++) if (phi[i]==i){
		for (int j = i; j <= n; j+=i) phi[j]-=phi[j]/i; 
	}
	for (int i = 1; i*i <= n; i++){
		for (int j = i*i; j <= n; j+=i*i) spf[j] = j/(i*i);
	}
	long long int res = 0;
//	for (int y = 2; y <= n; y++) res = res + 1ll*(n/y)*(n/y)%p*phi[y]%p;
	for (int x = 2; x <= n; x++) res = res + 1ll*(n/x)*(n/x-1)%p*inNum[2]%p*phi[x]%p;
	for (int i = 1; i <= n; i++){
		cnt[spf[i]]++;
//		cout << i << " " << spf[i] << endl;
	}
//	cout << res << endl;
	for (int i = 1; i <= n; i++) res -= cnt[i]*(cnt[i]-1)/2, res = (res+p)%p;
//	cout << res << endl;
	
	cout << 1ll*(1ll*n*(n-1)%p*(n-2)%p*(n-3)%p*inNum[4]%p-res+2ll*p)*inNum[2]%p;
	
	
	
	return 0;
}
