#include <bits/stdc++.h>

using namespace std;
int n, a[5005], sum[5005];
bool check(int x, int y){
	int l = x, h = y, m;
	while (l<=h){
		m = (l+h)/2;
		if (sum[m]-sum[x-1]==sum[y]-sum[m]) return true;
		if (sum[m]-sum[x-1]>sum[y]-sum[m]) h = m - 1;
		else l = m + 1;
	}
	return (sum[m]-sum[x-1]==sum[y]-sum[m]);
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i];
	
	for (int l = n; l >= 2; l--){
		for (int i = 1; i <= n-l+1; i++) if (check(i,i+l-1)){
			cout << l;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
