#include <bits/stdc++.h>

using namespace std;
long long int n;

long long int f(long long int k){
	return k*(k-1)/2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int k = 2; k <= 4*sqrt(n); k++){
		if ((n-f(k))%k==0&&n>f(k)){
			cout << (n-f(k))/k << " " << (n-f(k))/k + k -1 << endl;
		}
	}
	
	return 0;
}
