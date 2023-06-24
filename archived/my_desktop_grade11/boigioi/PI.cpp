#include <bits/stdc++.h>

using namespace std;
int l, r;
bool prime[1000005], primeL[1000005];

int main(){
	
	memset(prime,true,sizeof(prime));
	memset(primeL,true,sizeof(primeL));
	prime[0] = prime[1] = false;
	cin >> l >> r;
	if (l <= 1) primeL[1-l] = false;
	if (l <= 0) primeL[0-l] = false;
	
	for (int i = 2; (long long int)i*i <= r; i++) if (prime[i]){
		//cout << i << endl;
		for (int j = i*2; (long long int)j*j <= r; j += i) prime[j] = false;
		int b = (l/i)*i;
		if (l%i!=0) b+=i;
		//b = l + (i-l%i);
		//cout << i << ". "<< b << endl;
		//if (l/i<=1)
		for (int j = b; j <= r; j+=i) primeL[j-l] = false;
		if (b==i) primeL[b-l] = true;
	}
	int res = 0;
	//for (int i = 2; i*i <= r; i++) if (prime[i]) cout << i << " " ; cout << endl;
	//for (int i = l; i <= r; i++) if (primeL[i-l]) cout << i << " " ; cout << endl;
	for (int i = l; i <= r; i++) if (primeL[i-l]) res++;
	cout << res;
	
	return 0;
}
