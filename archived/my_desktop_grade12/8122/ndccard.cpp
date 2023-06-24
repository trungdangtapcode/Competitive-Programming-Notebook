#include<bits/stdc++.h>

using namespace std;
int n, a[10005], m, res;
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for (int i = 0; i < n-2; i++){
		if (a[i]>m) break;
		for (int j = i+2, k = i+1; j < n; j++){
			while (k<j&&a[i]+a[j]+a[k]<=m) k++;
			k--;
			if (k<=i) break;
			if (a[i]+a[j]+a[k]<=m) res = max(res,a[i]+a[j]+a[k]);
		}
	}
	cout << res;
	
	return 0;
}
