#include<bits/stdc++.h>

using namespace std;
int n, x;
vector<int> a, res;
int main(){
	cin >> n >> x;
	a.assign(n,0);
	res.assign(x+1,1e9);
	res[0] = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= x; i++) for (int j = 0; j < n; j++) if (i>=a[j]){
		res[i] = min(res[i],res[i-a[j]]+1);
	}
	cout << (res[x]==1e9?-1:res[x]);
	return 0;
}
