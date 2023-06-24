#include <bits/stdc++.h>

using namespace std;
int fact[10000050], inFact[10000050], inNum[10000050];
const int p = 1e7+19;
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
	int res = 1;
	while (n>1){
		if ((n/p)%2) res = p - res;
		res = 1ll*res*inFact[n%p]%p;
		n /= p;
	}
	return res;
}
int nCr0(long long int n, long long int r){
//	long long int x2 = (n/p)*p, x1 = ((n-r+1)/p)*p, y = ;
//	if (n-r+1<x) return ;
	return 1ll*calc_fact(n)*calc_inFact(n-r)%p*calc_inFact(r)%p;
}
long long int countP(long long int x){
	long long int res = 0;
	while (x>0){
		x /= p;
		res += x;
	}
	return res;
}
int nCr(long long int n, long long int r){
	int x = nCr0(n,r);
	//if (x==p-1&&r!=3) return 0;
	if (countP(n)-countP(n-r)>countP(r)||r<0||r>n) return 0;
	return x; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = inFact[0] = inFact[1] = inNum[0] = inNum[1] = 1;
	for (int i = 2; i <= 1e7+18; i++){
		fact[i] = 1ll*fact[i-1]*i%p;
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
		inFact[i] = 1ll*inFact[i-1]*inNum[i]%p;
	}
	
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> r;
		cout << 1ll*(n%p)*(m%p)%p*nCr(n+m-2,r-2)%p << '\n';
	}
//	cout << 1ll*calc_fact()
//	cout << calc_fact(9)*calc_inFact(7)%p;	
//	cout << nCr(100,50);
//	cout << nCr(6,3);
	return 0;
}
