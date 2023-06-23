#include <bits/stdc++.h>

using namespace std;
int fact[10000050], inFact[10000050], inNum[10000050], phi[10000050];
int p = 1e7+19;
long long int n, m, r;

int AmuB(int a, long long int b){
	int res = 1;
	while (b!=0){
		if (b%2) res = 1ll*res*a%p;
		a = 1ll*a*a%p;
		b /= 2;
	}
	return res;
}
int calc_fact(long long int n){
	int res = 1;
	while (n>1){
		if ((n/p)%2) res = p - res;
		res = 1ll*res*fact[n%p]%p;
		n /= p;
	}
	return res;
}
int calc_inFact(long long int n){
	return AmuB(calc_fact(n),phi[p]-1);
}
int nCr0(long long int n, long long int r){
	return 1ll*calc_fact(n)*calc_inFact(n-r)%p*calc_inFact(r)%p;
}
int nCr(long long int n, long long int r){
	int x = nCr0(n,r);
	return x; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	
	int t = 1;
	while (t--){
		cin >> n >> m >> p;
		phi[1] = fact[0] = fact[1] = inFact[0] = inFact[1] = inNum[0] = inNum[1] = 1;
		for (int i = 2; i <= p; i++){
			fact[i] = 1ll*fact[i-1]*i%p;
			inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
			inFact[i] = 1ll*inFact[i-1]*inNum[i]%p;
			phi[i] = i;
		}
		for (int i = 2; i <= p; i++) if (phi[i]==i){
			for (int j = i; j <= p; j+=i) phi[j] -= phi[j]/i;
		}
		cout << phi[p] << endl;
		cout << 1ll*calc_inFact(4)*24%p << '\n';
	}
	return 0;
}

