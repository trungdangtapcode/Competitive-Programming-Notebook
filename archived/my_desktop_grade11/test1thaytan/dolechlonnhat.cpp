#include <bits/stdc++.h>

using namespace std;

int main(){
	long int n;
	long long int s;
	cin >> n >> s;
	long long int *a = new long long int[1000005];
	a[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	
	long int result = 1e6;
	for (long int i = 1; i <= n; i++){
		for (long int j = i; j <= n; j++){
			if (a[j]-a[i-1]==s){
				result = min(result,j-i+1);
			}
		}
	}
	if (result == 1e6) cout << -1; else cout << result;
	
	return 0;
}
