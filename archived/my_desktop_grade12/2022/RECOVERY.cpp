#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
int n, c, k, res = 1e18;
vector<ii> a;
main(){
	cin >> n >> c >> k;
	a.assign(n+1,{0,0});
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) a[i].second = a[i].first;
	a[n] = {c+1,0};
	for (int i = 0; i < n; i++) a.push_back({a[i].first+1,0}), a.push_back({a[i].first+k,0});
	a.push_back({1,0});
	a.push_back({1,0});
	a.push_back({k,0});
	sort(a.begin(),a.end());
//	sort(a.begin(),a.end(),[](ii a, ii b){
//		if (a.first==b.first) return a.second>b.second;
//		return a.first < b.first;
//	});
	n = a.size();
	for (int i = 1; i < n; i++){
		if (a[i].first==a[i-1].first) a[i].second += a[i-1].second, a[i-1].second = 0;
	}
	for (int i = 1; i < n; i++) a[i].second = a[i-1].second + a[i].second;
//	for (int i = 0; i < n; i++) cout << a[i].first << "(" << a[i].second << ") "; cout << endl;
	for (int i = 1, j = 1; i < n; i++){
		while (j<n&&a[j].first-a[i].first+1<=k) j++;
		j--;
//		cout << a[i].first << " " << a[j].first << " " << i << " " << j << " " << n << endl;
		if (a[j].first<=c) res = min(res,a[j].second-a[i-1].second);
		else break;
	}
	cout << res;
//	cout << (res==1e18?0:res);
	
	return 0;
}
