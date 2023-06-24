#include <bits/stdc++.h>

using namespace std;
long long int p = 1e9 + 7, n;
map<long long int, long long int> m;

long long int fibo(long long int n){
	if (n == 0) return 0;
	if (n <= 2) return 1;
	//cout << n << endl;
	if (m[n]!=0) return m[n];
	long long int t = n/2;
	if (n%2==0){
		m[n] = fibo(t)*(2*fibo(t+1)%p-fibo(t)%p+p)%p; //tru modular ma quen +p
	} else {
		m[n] = (fibo(t+1)*fibo(t+1)%p + fibo(t)*fibo(t)%p)%p;
	}
	return m[n];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cout << fibo(n);
	
	return 0;
}
