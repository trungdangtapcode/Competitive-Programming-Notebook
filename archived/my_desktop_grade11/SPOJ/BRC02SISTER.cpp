#include <bits/stdc++.h>
using namespace std;
int n, a[25], sum, res;
bool p[2000005];
void backtrack(int k, int sum1){
	if (k==n){
		int sum2 = sum - sum1;
		if (p[abs(sum2-sum1)]) res = max(res,abs(sum2-sum1));
		return;
	}
	backtrack(k+1,sum1);
	backtrack(k+1,sum1+a[k]);
}

int main(){
	memset(p,true,sizeof(p));
	p[0] = p[1] = false;
	for (int i = 2; i*i <= 2e6; i++) if (p[i]){
		for (int j = i*i; j <= 2e6; j+=i) p[j] = false;
	}
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	backtrack(0,0);
	cout << res;
	return 0;
}
