#include<bits/stdc++.h>

using namespace std;
int n, m, a[10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	
	int res = 0;
	for (int i = 1; i <= n; i++){
		int k = n;
		for (int j = i+1; j < n; j++){
			while (k>j+1&&a[i]+a[j]+a[k]>m) k--;
			if (k>j&&a[i]+a[j]+a[k]<=m) res = max(res,a[i]+a[j]+a[k]);
		}
	}
	cout << res;
	
	return 0;
}
