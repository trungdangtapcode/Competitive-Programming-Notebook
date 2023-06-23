#include<bits/stdc++.h>

using namespace std;
long long int a, b;
int main(){
	cin >> a >> b;
	cout << __gcd(a,b) << " " << a*b/__gcd(a,b);
	
	return 0;
}
