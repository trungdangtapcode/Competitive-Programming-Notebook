#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> a, b;
vector<long long int> sum;

int main(){
	cin >> n >> k;
	a.assign(n+1,0);
	sum.assign(n+1,0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	long long int res = 0;
	int res_l, res_r;
	for (int i = 1; i <= n-k+1; i++){
		if (res<sum[i+k-1]-sum[i-1]){
			res = sum[i+k-1]-sum[i-1];
			res_l = i;
			res_r = i+k-1;
		}
	}
//	b.push_back(0);
//	for (int i = 1; i <= n; i++) if (i<res_l||res_r<i){
//		b.push_back(a[i]);
//	}
//	for (int i = 1; i <= n-k; i++){
//		sum[i] = sum[i-1] + b[i];
//		cout << b[i] << " ";
//	}
//	res = 0;
//	for (int i = 1; i <= (n-k)-k+1; i++){
//		res = max(res,sum[i+k-1]-sum[i-1]);
//	}
	res = 0;
	for (int i = 1; i <= n-k+1; i++) if (i>res_r||i+k-1<res_l){
		res = max(res,sum[i+k-1]-sum[i-1]);
	}
	cout << res;
	
	return 0;
}
