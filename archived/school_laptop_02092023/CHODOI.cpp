#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, m, f[200005];
vector<int> vec;
vector<pair<int,int>> a;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		vec.push_back(a[i].second);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	vec.push_back(1e12);
	for (int i = 0; i < vec.size(); i++) f[i] = 1e12;
	for (int i= 0; i < n; i++){
		a[i].second = lower_bound(vec.begin(),vec.end(),a[i].second)-vec.begin();
		f[a[i].second] = min(f[a[i].second],a[i].first);
	}
	for (int i = vec.size()-2; i >= 0; i--) f[i] = min(f[i],f[i+1]);
	for (int i=0, x; i < m; i++){
		cin >> x;
		int pos = upper_bound(vec.begin(),vec.end(),x)-vec.begin();
//		cout << f[pos] << "->";
		pos = f[pos];
		if (pos==1e12) cout << -1 << "\n";
		else cout << max(0ll,pos-x) << "\n";
	}
	
	
	return 0;
}
