#include<bits/stdc++.h>

using namespace std;
typedef long double ld;

int main(){
	ld n,x,y,a,b;
	cin >> n >> x >> y >> a >> b;
	cout << fixed << setprecision(9) << n/2*sqrt(a*a+b*b);	
	return 0;
}
