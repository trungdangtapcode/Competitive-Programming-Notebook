#include<bits/stdc++.h>

using namespace std;
int n;
long long int res = -1e9, sum;
int main(){
	cin >> n;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		sum = max(sum,0ll);
		sum += a;
		res = max(res,sum);
	}
	cout << res;
	
	return 0;
}
