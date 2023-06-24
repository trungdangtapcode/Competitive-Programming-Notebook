#include<bits/stdc++.h>

using namespace std;
int n;
long long int f[2];

int main(){
	cin >> n;
	f[1] = -1e12; //co 1 thang (+) => ko ton tai => -1e9
	for (int i = 0, x; i < n; i++){
		cin >> x;
		tie(f[0],f[1]) = make_tuple(max(f[0],f[1]-x),max(f[1],f[0]+x));
	}
	cout << max(f[0],f[1]);
	
	
	return 0;
}
