#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;

int main(){
	freopen("DSEQ.INP","r",stdin);
	freopen("DSEQ.OUT","w",stdout);
	
	cin >> n;
	a.assign(n+1,0);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++){
		res = max(res,abs((a[i]-a[0])-(a[n]-a[j-1])));
	}
	cout << res;
	
	return 0;
}
