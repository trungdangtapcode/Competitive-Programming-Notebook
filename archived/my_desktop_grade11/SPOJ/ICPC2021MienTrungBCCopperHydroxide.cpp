#include <bits/stdc++.h>

using namespace std;
int n;
double a[1000005], b[1000005], sum[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i], b[i] = a[i];
	for (int i = 1; i < n;) {
		int j = i;
		while (b[i] > b[i+1]&& i < n) b[i+1] = 1.0*(sum[i+1]-sum[j-1])/(i+1-j+1), i++;
		for (int k = j; k <= i; k++) b[k] = b[i];
		//cout << j << " " << i << endl;
		i++;
	}
	double res = 0;
	for (int i =1; i <= n; i++) res += (a[i]-b[i])*(a[i]-b[i]);
	cout << fixed << setprecision(7) <<sqrt(res);
	
	
	return 0;
}
