#include <bits/stdc++.h>

using namespace std;
int n, prv[1000005];
double a[1000005], b[1000005], sum[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i], b[i] = a[i], prv[i] = i;
	b[0] = -1e6;
	for (int i = 1; i <= n;) {
		int j = i;
		while (j>=1&&b[j-1]>b[i]) b[i] = 1.0*(sum[i]-sum[prv[j-1]-1])/(i-prv[j-1]+1), prv[i] = prv[j-1],j = prv[j-1]; 
		i++;
	}
	for (int i = n; i >= 1;){
		for (int j = i-1; j >= prv[i]; j--) b[j] = b[i];
		i = prv[i]-1;
	}
	//for (int i = 1; i <= n; i++) cout <<" {" << b[i] << "," <<prv[i]<< "} ";
	double res = 0;
	for (int i =1; i <= n; i++) res += (a[i]-b[i])*(a[i]-b[i]);
	cout << fixed << setprecision(7) <<sqrt(res);
	
	
	return 0;
}
