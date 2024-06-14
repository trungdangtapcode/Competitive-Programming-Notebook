#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 5;
int n, a;
long long t;
int main(){
	int g = 0;
	cin >> n >> t ;
	for (int i = 1; i <= n; i++){
		cin >> a;
		g = __gcd(a,g);
	}
	cout << t/g+1;
	
	return 0;
}
