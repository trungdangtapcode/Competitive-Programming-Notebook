#include<bits/stdc++.h>

using namespace std;
long long int fact[1000005], inFact[1000005], inNum[1000005], n, m, p, phi[1000005], p0;
vector<long long int> a, b;

long long int getPower(long long int a, long long int b, long long int p){
	long long int res = 1;
	while (b){
		if (b%2) res = res*a%p;
		b /= 2;
		a = a*a%p;
	}
	return res;
}

long long int nCr(int n, int r){
	return (fact[n]*inFact[n-r]%p*inFact[r]%p);
}
long long int nCrLucas(long long int n, long long int r){
	if (r==0) return 1;
	return nCrLucas(n/p,r/p)*nCr(n%p,r%p)%p;
}

long long int HanTin(){
	vector<long long int> c;
	c.assign(b.size(),0);
	for (int i = 0; i < b.size(); i++){
		c[i] = p/b[i];
	}
	long long int res = 0;
	for (int i = 0; i < b.size(); i++){
		res += a[i]*getPower(c[i],phi[b[i]],p)%p;
		res %= p;
	}
	return res;
}

int main(){
	for (int i = 0; i <= 1e6; i++) phi[i] = i;
	for (int i = 2; i <= 1e6; i++) if (phi[i]==i){
		for (int j = i; j <= 1e6; j+=i) phi[j] -= phi[j]/i;
	}
	
	n = 400; m = 44; p0 = 10;
	for (int i = 2; i <= p0; i++) if (phi[i]==i-1){
		int tmp = p0;
		while (tmp%i==0) tmp/=i;
		if (tmp!=p0) b.push_back(p0/tmp);
	}
	
	for (int x: b){
		p = x;
		fact[0] = fact[1] = inFact[0] = inFact[1] = inNum[0] = inNum[1] = 1;
		for (int i = 2; i <= p; i++){
			fact[i] = fact[i-1]*i%p;
			inFact[i] = getPower(fact[i],phi[p]-1,p);
		}
		a.push_back(nCrLucas(n+m-1,m-1));
		cout << x << " => " << a.back() << endl;
	}
	
	p = p0;
	cout << HanTin();
//	cout << HanTin({2,3,5},{3,5,7});
//	fact[0] = fact[1] = inFact[0] = inFact[1] = inNum[0] = inNum[1] = 1;
//	for (int i = 2; i <= p; i++){
//		fact[i] = fact[i-1]*i%p;
//		inNum[i] = inNum[p%i]*(p-p/i)%p;
//		inFact[i] = inFact[i-1]*inNum[i]%p;
//	}
//	cout << nCrLucas(n+m-1,m-1);
	
	return 0;
}
