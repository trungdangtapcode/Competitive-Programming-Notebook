#include<bits/stdc++.h>

using namespace std;
typedef pair<long long int, long long int> ll; //first(modul)*t^second (in p modul)
long long int fact[1000005], n, m, p, phi[1000005], p0, t;
vector<long long int> a, b, bm;

long long int getPower(long long int a, long long int b, long long int p){
	long long int res = 1;
	while (b){
		if (b%2) res = res*a%p;
		b /= 2;
		a = a*a%p;
	}
	return res;
}

ll getDivide(ll a, ll b){
	return {a.first*getPower(b.first,phi[p]-1,p)%p,a.second-b.second};
}
ll getMul(ll a, ll b){
	return {a.first*b.first%p,a.second+b.second};
}
long long int getTrans(ll x){
	return x.first*getPower(t,x.second,p)%p;
}
ll calcFact(long long int n){
//	cout << n << " " << n/t << " " << n%t << endl;
	if (n<=1) return {1,0};
	ll tmp = calcFact(n/t);
	return {getPower(fact[p-1],n/p,p)*fact[n%p]%p*tmp.first%p,n/t+tmp.second};
}
long long int nCrThai(long long int n, long long int r){
	return getTrans(getDivide(calcFact(n),getMul(calcFact(n-r),calcFact(r))));
}
//long long int nCrLucas(long long int n, long long int r){
//	if (r==0) return 1;
//	return nCrLucas(n/p,r/p)*nCr(n%p,r%p)%p;
//}

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
	
//	n = 400; m = 44; p0 = 16969;
	cin >> n >> m >> p0;
	if (p0==1){
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= p0; i++) if (phi[i]==i-1){
		int tmp = p0;
		while (tmp%i==0) tmp/=i;
		if (tmp!=p0) b.push_back(p0/tmp), bm.push_back(i);
	}
	
	for (int i = 0; i < b.size(); i++){
		p = b[i]; //main modul p is a prime power
		t = bm[i]; //main small modul p = t^k (prime factor)
		fact[0] = fact[1] = 1;
		for (int i = 2; i <= p; i++){
			int tmp = i;
//			while (tmp%t==0) tmp /= t;
			if (tmp%t==0) tmp = 1;
			fact[i] = fact[i-1]*tmp%p;
//			cout << i << " -> " << fact[i] << endl;
		} 
//		cout << p << " => " << getDivide(calcFact(79),calcFact(78)).first << endl;
//		cout << p << " => " << calcFact(79).first << " " << calcFact(79).second << endl;
		a.push_back(nCrThai(n+m-1,m-1));
//		cout << p << " => " << a.back() << endl;
	}
	
	p = p0;
	cout << HanTin();
	
	return 0;
}
