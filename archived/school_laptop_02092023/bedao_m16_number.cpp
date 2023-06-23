#include<bits/stdc++.h>

using namespace std;

int f[100005][31], a[100005], res, n, k;
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> k;
	
	for (int i = 1; i <= n; i++){
		if (a[i]>0) f[i][1]++; 
		if (a[i]%2==0) (res += (f[i-1][k-1]+f[i][k])%p)%=p;
		if (a[i]==0&&k==1) (++res)%=p; //idk
		for (int j = 1; j < k; j++){
			(f[i][j] += f[i-1][j])%=p;
			(f[i][j+1] += f[i-1][j])%=p;
		}
	}
	cout << res;
	
	
	return 0;
}
