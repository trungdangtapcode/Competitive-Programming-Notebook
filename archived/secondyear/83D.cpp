#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
vector<int> prime;
int n, p[maxN], k, a, b;
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++)
		if (x%i==0) return false;
	return true;
}
int phi(int x, int i){
	if (i==-1) return x;
	if (!x) return 0;
	return phi(x,i-1)-phi(x/prime[i],i-1);
}
int f(int x){
	if (1ll*k*k>x) return k<=x;
	int i;
	x /= k;
	for (i = -1; prime[i+1]<k; i++);
//	cout << x << " "<< i << " " << prime[i] << "\n";
	return phi(x,i);
}

void solve(){
//	cout << phi(100,1) << "\n";
	cin >> a >> b >> k;
	if (!isPrime(k)){
		cout << 0 << "\n";
		return;
	}
	cout << f(b)-f(a-1) << "\n";	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	
	int n = 5e4;
	for (int i = 2; i <= n; i++) p[i] = 1;
	for (int i = 1; i*i <= n; i++) if (p[i]){
		for (int j = i*i; j <= n; j += i)
			p[j] = 0;
	}
	for (int i = 1; i <= n; i++) if (p[i]) prime.push_back(i);
//	int t; cin >> t;
//	while (t--)
	solve();
}

