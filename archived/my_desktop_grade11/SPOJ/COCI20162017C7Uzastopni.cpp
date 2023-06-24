#include <bits/stdc++.h>

using namespace std;
long long int n;

long long int f(long long int x){
	return x*(x+1)/2;
}
long long int g(long long int x, long long int y){
	return f(y) - f(x-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (long long int i = 1; i <= n; i++){ //4*sqrt(n)
		//for (long long int j = i; j <= 4*sqrt(n);j++) if (g(i,j)==n) cout << i << " " << j << endl;
		long long int l = i+1, h = n, m= -1;
		while (l <= h){
			m = (l+h)/2;
			//cout << i<< " BIT " << l << " " << h << "  " << m << endl;
			if (g(i,m)==n) break;
			if (g(i,m)>n) h = m-1; else l = m + 1;
		}
		if (g(i,m)==n) cout << i << " " << m << endl;
	}
	
	return 0;
}
