#include<bits/stdc++.h>

using namespace std;
int n, a[5005], res;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1, k = i; j <= n; j++){
			while (k<j-1&&a[k]-a[i-1]<a[j]-a[k]) k++;
			if (a[k]-a[i-1]==a[j]-a[k]) res = max(res,j-i+1);
		}
	}
	cout << res;
	
	return 0;
}
