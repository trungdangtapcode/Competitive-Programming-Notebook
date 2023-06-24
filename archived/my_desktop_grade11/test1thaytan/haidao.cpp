#include <bits/stdc++.h>

using namespace std;
int main(){
	long int n;
	long long int T;
	cin >> n >> T;
	vector  <long long int> sum (n+5);
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	//for (long int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	long int result = 1e7;
	for (long int i = 1; i <= n; i++){
		long long int x = T+sum[i-1];
		//cout << i <<  " "<<x<< " -> " << (lower_bound(sum.begin(),sum.end(),x)-sum.begin()) << endl; 
		if ((lower_bound(sum.begin()+i,sum.end(),x)-sum.begin())<=n)
			result = min(result,(long int)(lower_bound(sum.begin()+i,sum.end(),x)-sum.begin())-i+1);
	}
	if (result == 1e7) cout << -1; else cout << result;
	
	return 0;
}
