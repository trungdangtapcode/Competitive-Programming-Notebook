#include <bits/stdc++.h>

using namespace std;
int n, b, a[2005], dp[2005][2005];
const int p = 1e9+7;

int calc(int k, int gz){
	if (k<1) return 1;
	int *res = &dp[k][gz];
	if (*res!=-1) return *res;
	*res = 0;
	if (a[k]==-1){
		if (gz>b) return *res;
		*res = (calc(k-1,gz) + 1ll*min(b-gz,k-1)*calc(k-1,gz+1))%p;
	} else {
		if (a[k]+gz>b) return *res;
		if (a[k]==0) *res = calc(k-1,gz);
		else *res = calc(k-1,gz+1);
	}
//	cout << k << " " << gz << " " << *res << endl;
	return *res;
}

int main(){
//	freopen("GRAPH.INP","r",stdin);
//	freopen("GRAPH.OUT","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << calc(n,0);
	return 0;
}
