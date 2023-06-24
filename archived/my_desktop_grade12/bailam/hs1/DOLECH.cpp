#include<bits/stdc++.h>

using namespace std;
int n;

int main(){
	freopen("DOLECH.INP","r",stdin);
	freopen("DOLECH.OUT","w",stdout);
	
	cin >> n;
	long long int res = -1e18, mmin = 1e18;
	for (int i = 0; i < n; i++){
		long long int a;
		cin >> a;
		mmin = min(mmin,a); //i<=j bi nham :))
		res = max(res,a-mmin);
	}
	cout << res;
	
	return 0;
}
