#include<bits/stdc++.h>

using namespace std;
long long int n, k, p;

int main(){
	freopen("SALE.INP","r",stdin);
	freopen("SALE.OUT","w",stdout);
	
	cin >> n >> k >> p;
	long long int l = 0, h = n, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (m+m/k>=n){
			res = m;
			h = m-1;
		} else l = m+1;
	}
	cout << res*p;
	
	return 0;
}
