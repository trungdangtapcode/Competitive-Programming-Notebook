#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main(){
	cin >> n;
	a.assign(n,0);
	for (auto& i: a) cin >> i;
	sort(a.begin(),a.end());
	int res = 0;
	for (int i = 0; i < n-1; i++) res = max(res,a[i]%a[i+1]);
	cout << res;
	
	return 0;
}
