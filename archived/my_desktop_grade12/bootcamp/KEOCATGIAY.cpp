#include<bits/stdc++.h>

using namespace std;
long long int n, m;
int main(){
	cin >> n >> m;
	if (n>m) swap(n,m);
	cout << (n-1)*m-n*(n+1)/2+1 + n*(n-1)/2;
	
	return 0;
}
