#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a, lmax, lmin;
int main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	a.assign(n+2,0);
	a[0] = a[n+1] = -1e9;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a.erase(unique(a.begin(),a.end()),a.end());
	n = a.size()-2;
	for (int i = 1; i <= n; i++){
		if (a[i]>a[i+1]&&a[i]>a[i-1]) lmax.push_back(a[i]);
	}
	for (int i = 1; i <= n; i++){
		if (a[i]<a[i+1]&&a[i]<a[i-1]) lmin.push_back(a[i]);
	}
	sort(lmax.begin(),lmax.end());
	sort(lmin.begin(),lmin.end());
	sort(a.begin(),a.end());
	int res = 1;
	for (int i = 2; i < n+2; i++){
		int x = a[i];
		int floored = lower_bound(lmax.begin(),lmax.end(),x)-lmax.begin();
		int created = lower_bound(lmin.begin(),lmin.end(),x)-lmin.begin();
//		cout << x << " " << created << " " << floored << " => " << 1+created-floored<< "\n";
		res = max(res,1+created-floored);
	}
	cout << res;
	
	return 0;
}
