#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
	cin >> n;
	int res = 0;
	for (long long int i = 5; i <= n; i*=5){
		res += n/i;
	} 
	cout << res;
	
	return 0;
}
