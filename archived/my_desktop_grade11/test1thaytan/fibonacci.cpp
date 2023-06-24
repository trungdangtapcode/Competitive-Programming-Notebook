#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int f[50];
	f[0] = 1;
	f[1] = 1;
	cout << 1 << endl;
	cout << 1 << endl;
	for (long int i = 2; i <= 44; i++){
		f[i] = f[i-1] + f[i-2];
		cout << f[i] << endl;
	}
	
	
	return 0;
}
