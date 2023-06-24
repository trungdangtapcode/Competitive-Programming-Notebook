#include <bits/stdc++.h>

using namespace std;
long long int n;

int main(){
	cin >> n;
	if (n%3!=0) cout << ((n-1)/2)*n;
	if (n%3==0) cout <<((n-1)/2)*n - n + n/3;
	
	return 0;
}
