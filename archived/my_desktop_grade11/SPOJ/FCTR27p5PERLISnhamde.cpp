#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a, lis, res;
int main(){
	cin >> n;
	a.assign(n,0); res.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i], a[i] = n - a[i];
	lis.assign(n+1,1e9);
	lis[0] = -1e9;
	for (int i = n-1, pos; i >= 0; i--){
		pos = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
		lis[pos] = a[i];
		res[i] = pos;
	}
	for (int i = 0; i <n; i++) cout << res[i] << ' ';
	
	return 0;
}
