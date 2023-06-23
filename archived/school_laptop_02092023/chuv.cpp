#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a, res;

int main(){
	cin >> n;
	a.assign(n,0);
	res.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(),a.rend());
	for (int i = 0, l = 0, r = n-1; i < n; i++)
		if (i&1) res[r--] = a[i]; else res[l++] = a[i];
	for (int i = 0; i < n; i++) cout << res[i] << " ";
	
	return 0;
}
