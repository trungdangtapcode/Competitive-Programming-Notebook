#include<bits/stdc++.h>

using namespace std;
long double a, b, n, tmp;
int tmp2;
int main(){
	cin >> a >> b >> n;
	tmp = n/(a*b-b);
	tmp2 = tmp;
	cout << (tmp-tmp2>1e-9?tmp2+1:tmp2);
	
	return 0;
}
