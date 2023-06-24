#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;

int main(){
	freopen("BANGSO.INP","r",stdin);
	freopen("BANGSO.OUT","w",stdout);
	
	cin >> n;
	a.assign(n+1,0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = -1e9;
	for (int i = 1, sum = 0; i <= n; i++){
		if (sum<0) sum = 0;
		sum += a[i];
		res = max(res,sum);
	}
	cout << res;
	
	return 0;
}
