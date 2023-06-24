#include <bits/stdc++.h>
using namespace std;
int n, sum, sum2, sum3, sumsquare, sumcube;
const int p = 1e9+7;

int main(){
	cin >> n;
	for (int i = 0, a; i < n ; i++){
		cin >> a;
		sum = (sum+a)%p;
		sumsquare = (sumsquare+1ll*a*a)%p;
		sumcube = (sumcube+1ll*a*a%p*a)%p;
	}
	int divide2 = (p-p/2)%p;
	int divide3 = 1ll*divide2*(p-p/3)%p;
	sum2 = ((1ll*sum*sum-sumsquare)%p*divide2%p+1ll*p*p)%p;
	sum3 = ((1ll*sum*sum2-1ll*sumsquare*sum+sumcube)%p*divide3%p+1ll*p*p)%p;
	cout << sum3;
	return 0;
}
