#include <bits/stdc++.h>

using namespace std;
long long int a[4];


int main(){
	freopen("RECTANGLE.INP","r",stdin);
	freopen("RECTANGLE.OUT","w",stdout);
	
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a,a+4);
	cout << a[0]*a[2];
	
	return 0;
}
