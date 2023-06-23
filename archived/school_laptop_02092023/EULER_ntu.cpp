#include<bits/stdc++.h>

using namespace std;
#define int long long

int c[100005], phi[100005];

//void f(int x){
//	if (x<10) return;
//	cout << x << endl;
//	for (int k = 2, i; k <= x; k=i+1){
//		i = (x/(x/k));
//		f(x/i);
//	}
//}
map<int,int> m;
int calc(int x){
	if (x<1e5) return c[x];
	if (m.count(x)) return m[x];
	int res = x*x;
	for (int k = 2, i; k <= x; k=i+1){
		i = (x/(x/k));
		res -= calc(x/i)*(min(x,i)-k+1);
	}
	return m[x] = res;
}

main(){
	for (int i = 2; i <= 1e5; i++) phi[i] = i;
	for (int i = 2; i <= 1e5; i++) if (phi[i]==i){
		for (int j = i; j <= 1e5; j+=i) phi[j] -= phi[j]/i;
	}
	for (int i = 2; i <= 1e5; i++){
		c[i] = c[i-1] + phi[i];
	}
	c[1] = 1;
//	cout << "1 1\n";
	for (int i = 2; i <= 1e5; i++){
		c[i] = 2*c[i]+1;
//		cout << i << " " << c[i] << endl;
//		if (i>15) break;
	}
//	int n = 69; 
//	int res = n*n;
//	for (int i = 1; i <= sqrt(n); i++){
//		res -= c[i]*(n/i-n/(i+1));
//	}
//	int alp = sqrt(n)+2;
//	cout << res << endl;
//	while (n/alp<=sqrt(n)) alp--;
//	for (int i = 2; i <= alp; i++) res -= c[n/i];
//	cout << res << endl;
	int n;
	cin >> n;
	cout << (calc(n)+1)/2;
	
	return 0;
}
