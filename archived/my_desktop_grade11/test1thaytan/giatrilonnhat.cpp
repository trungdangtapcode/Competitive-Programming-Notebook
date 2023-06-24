#include <bits/stdc++.h>

using namespace std;

int main(){
	long int n;
	cin >> n;
	long long int *a = new long long int[100005];
	long long int *maxR = new long long int[100005];
	long long int *maxL = new long long int[100005];
	maxL[0] = -1e10;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		maxL[i] = max(maxL[i-1],a[i]);
	}
	maxR[n+1] = -1e10;
	for (long int i = n; i >= 1; i--){
		maxR[i] = max(maxR[i+1],a[i]);
	}
	
	long long int result = -1e12;
	for (long int i = 2; i <= n-1; i++){
		result = max(result,2*maxL[i-1]-3*a[i]+5*maxR[i+1]);
	}
	cout << result;
	
	return 0;
}
